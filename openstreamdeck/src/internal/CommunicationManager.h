//
// Created by Cyril Vlaminck on 24/12/2021.
//

#ifndef STREAMDECK_COMMAND_COMMUNICATIONMANAGER_H
#define STREAMDECK_COMMAND_COMMUNICATIONMANAGER_H

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/json.hpp>
#include <string>

#include "EventParsingManager.h"
#include "Logger.h"
#include "event/sent/SentEvent.h"

namespace openstreamdeck::internal {

class CommunicationManager : public std::enable_shared_from_this<CommunicationManager> {
   public:
    using OpenCallback = std::function<void(CommunicationManager&)>;
    using WriteCallback = std::function<void(CommunicationManager&, std::shared_ptr<event::SentEvent>, bool)>;
    using ReadCallback = std::function<void(CommunicationManager&, std::unique_ptr<Event>)>;

   private:
    std::shared_ptr<Logger> logger;
    std::shared_ptr<EventParsingManager> eventParsingManager;

    std::unique_ptr<boost::asio::ip::tcp::resolver> resolver;
    std::unique_ptr<boost::beast::websocket::stream<boost::beast::tcp_stream>> ws;

    std::string host;
    std::string port;

    boost::beast::flat_buffer readBuffer;

    OpenCallback openCallback;
    WriteCallback writeCallback;
    ReadCallback readCallback;

   public:
    /**
     *
     * @param ioContext The execution context into which the I/O operations will be executed.
     */
    CommunicationManager(std::shared_ptr<Logger> logger, std::shared_ptr<EventParsingManager> eventParsingManager);

    /**
     * Configure the execution context into which the I/O operations will be scheduled.
     */
    auto configureWithIOContext(boost::asio::io_context& ioContext) -> void;

    auto connect(const std::string& host, uint16_t port) -> void;

    auto write(std::shared_ptr<event::SentEvent> event) -> void;

    auto read() -> void;

    auto setOpenCallback(OpenCallback openCallback) -> void;

    auto setWriteCallback(WriteCallback writeCallback) -> void;

    auto setReadCallback(ReadCallback readCallback) -> void;

   private:
    auto onHostResolved(boost::beast::error_code ec, boost::asio::ip::tcp::resolver::results_type results) -> void;

    auto onConnectionEstablished(boost::beast::error_code ec, boost::asio::ip::tcp::resolver::results_type::endpoint_type ep) -> void;

    auto onConnectionHandshaked(boost::beast::error_code ec) -> void;

    auto onWrite(std::shared_ptr<event::SentEvent> event, boost::beast::error_code ec, std::size_t bytesWritten) -> void;

    auto onRead(boost::beast::error_code ec, std::size_t bytesRead) -> void;
};

}  // namespace openstreamdeck::internal

#endif  // STREAMDECK_COMMAND_COMMUNICATIONMANAGER_H
