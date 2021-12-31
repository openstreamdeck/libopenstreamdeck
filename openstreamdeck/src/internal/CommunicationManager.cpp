//
// Created by Cyril Vlaminck on 24/12/2021.
//

#include "CommunicationManager.h"

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/strand.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/format.hpp>
#include <utility>

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using io_context = boost::asio::io_context;
using tcp = boost::asio::ip::tcp;

namespace openstreamdeck::internal {

constexpr size_t kCommunicationManagerReadLimit = UINT16_MAX;

CommunicationManager::CommunicationManager(std::shared_ptr<Logger> _logger, std::shared_ptr<EventParsingManager> _eventParsingManager)
    : logger(std::move(_logger)), eventParsingManager(std::move(_eventParsingManager)) {
}

auto CommunicationManager::configureWithIOContext(boost::asio::io_context& ioContext) -> void {
    this->resolver = std::make_unique<tcp::resolver>(net::make_strand(ioContext));
    this->ws = std::make_unique<websocket::stream<beast::tcp_stream>>(net::make_strand(ioContext));
}

auto CommunicationManager::connect(const std::string& host, uint16_t port) -> void {
    this->host = host;
    this->port = (boost::format("%1%") % port).str();

    if (this->logger->isLogEnabled()) {
        this->logger->log(boost::format("Resolving IP address for '%1%:%2%' before connection.") % host % port);
    }

    if (!this->resolver) {
        if (this->logger->isLogEnabled()) {
            this->logger->log(boost::format("No IO context configured."));
        }
        return;
    }

    // Look up the domain name
    this->resolver->async_resolve(this->host, this->port, beast::bind_front_handler(&CommunicationManager::onHostResolved, shared_from_this()));
}

auto CommunicationManager::write(std::shared_ptr<event::SentEvent> event) -> void {
    auto json = serialize(event->serializeToJson());
    if (this->logger->isLogEnabled()) {
        this->logger->log(boost::format("Sending event to Stream deck app: %1%") % json);
    }

    if (!this->ws) {
        if (this->logger->isLogEnabled()) {
            this->logger->log(boost::format("No IO context configured."));
        }
        return;
    }

    auto buffer = net::buffer(json);
    this->ws->async_write(buffer, beast::bind_front_handler(&CommunicationManager::onWrite, shared_from_this(), event));
}

auto CommunicationManager::read() -> void {
    if (this->logger->isLogEnabled()) {
        this->logger->log(boost::format("Waiting to receive event from Stream deck app."));
    }

    if (!this->ws) {
        if (this->logger->isLogEnabled()) {
            this->logger->log(boost::format("No IO context configured."));
        }
        return;
    }

    this->ws->async_read_some(this->readBuffer, kCommunicationManagerReadLimit, beast::bind_front_handler(&CommunicationManager::onRead, shared_from_this()));
}

auto CommunicationManager::setOpenCallback(OpenCallback _openCallback) -> void {
    this->openCallback = std::move(_openCallback);
}

auto CommunicationManager::setWriteCallback(WriteCallback _writeCallback) -> void {
    this->writeCallback = std::move(_writeCallback);
}

auto CommunicationManager::setReadCallback(ReadCallback _readCallback) -> void {
    this->readCallback = std::move(_readCallback);
}

auto CommunicationManager::onHostResolved(beast::error_code ec, tcp::resolver::results_type results) -> void {
    if (ec) {
        if (this->logger->isLogEnabled()) {
            this->logger->log(boost::format("Failed to resolve host '%1%:%2%' with error code: %3%") % this->host % this->port % ec);
        }
        throw std::runtime_error("Failed to resolve host.");
    }

    if (this->logger->isLogEnabled()) {
        this->logger->log(boost::format("Connecting to host '%1%:%2%'.") % this->host % this->port);
    }

    if (!this->ws) {
        if (this->logger->isLogEnabled()) {
            this->logger->log(boost::format("No IO context configured."));
        }
        throw std::runtime_error("Failed to resolve host.");
    }

    beast::get_lowest_layer(*this->ws).expires_after(std::chrono::seconds(30));
    beast::get_lowest_layer(*this->ws).async_connect(results, beast::bind_front_handler(&CommunicationManager::onConnectionEstablished, shared_from_this()));
}

auto CommunicationManager::onConnectionEstablished(beast::error_code ec, tcp::resolver::results_type::endpoint_type ep) -> void {
    if (ec) {
        if (this->logger->isLogEnabled()) {
            this->logger->log(boost::format("Failed to connect to host '%1%:%2%' with error code: %3%") % this->host % this->port % ec);
        }
        throw std::runtime_error("Failed to connect to host.");
    }

    if (!this->ws) {
        if (this->logger->isLogEnabled()) {
            this->logger->log(boost::format("No IO context configured."));
        }
        throw std::runtime_error("Failed to connect to host.");
    }

    // Turn off the timeout on the tcp_stream, because the websocket stream has
    // its own timeout system.
    beast::get_lowest_layer(*this->ws).expires_never();

    // Set suggested timeout settings for the websocket
    this->ws->set_option(websocket::stream_base::timeout::suggested(beast::role_type::client));

    // This will provide the value of the Host HTTP header during the WebSocket
    // handshake. See https://tools.ietf.org/html/rfc7230#section-5.4
    auto fullHost = (boost::format("%1%:%2%") % this->host % this->port).str();

    if (this->logger->isLogEnabled()) {
        this->logger->log(boost::format("Performing handshake with host '%1%:%2%'.") % this->host % this->port);
    }

    // Perform the websocket handshake
    this->ws->async_handshake(fullHost, "/", beast::bind_front_handler(&CommunicationManager::onConnectionHandshaked, shared_from_this()));
}

auto CommunicationManager::onConnectionHandshaked(boost::beast::error_code ec) -> void {
    if (ec) {
        throw std::runtime_error("Failed to handshake with host.");
    }
    if (this->openCallback) {
        this->openCallback(*this);
    }
}

auto CommunicationManager::onWrite(std::shared_ptr<event::SentEvent> event, boost::beast::error_code ec, std::size_t bytesWritten) -> void {
    if (this->logger->isLogEnabled()) {
        if (ec) {
            this->logger->log(boost::format("Failed to write event '%1%' with error code: %2%") % event->event % ec);
        } else {
            this->logger->log(boost::format("Event '%1%' has been successfully written.") % event->event);
        }
    }

    boost::ignore_unused(bytesWritten);
    bool writeSucceded = (bool)ec;
    if (this->writeCallback) {
        this->writeCallback(*this, std::move(event), writeSucceded);
    }
}

auto CommunicationManager::onRead(boost::beast::error_code ec, std::size_t bytesRead) -> void {
    if (ec) {
        if (this->logger->isLogEnabled()) {
            this->logger->log(boost::format("Failed to read event with error code: %1%") % ec);
        }
        return;
    }

    const char* data = static_cast<const char*>(this->readBuffer.cdata().data());
    std::string serializedJson(data, bytesRead);
    if (this->logger->isLogEnabled()) {
        this->logger->log(boost::format("Event has been read from websocket: %1%") % serializedJson);
    }

    // Reinitialize buffer for next read operation.
    this->readBuffer = {};

    try {
        auto event = this->eventParsingManager->parseEvent(serializedJson);
        if (this->readCallback) {
            this->readCallback(*this, std::move(event));
        }
    } catch (std::invalid_argument& e) {
        if (this->logger->isLogEnabled()) {
            this->logger->log(e);
        }
    }
}

}  // namespace openstreamdeck::internal
