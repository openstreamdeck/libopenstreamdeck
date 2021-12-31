//
// Created by Cyril Vlaminck on 24/12/2021.
//

#include "StreamDeckPluginImpl.h"

#include <boost/json.hpp>

#include "RegistrationParser.h"

namespace openstreamdeck::internal {

StreamDeckPluginImpl::StreamDeckPluginImpl(int argc, const char* argv[])
    : registration(RegistrationParser().parse(argc, argv)),
      logger(std::make_shared<Logger>()),
      eventParsingManager(std::make_shared<EventParsingManager>(logger)),
      communicationManager(std::make_shared<CommunicationManager>(logger, eventParsingManager)),
      actionManager(std::make_shared<ActionManager>(logger, communicationManager, registration)),
      eventManager(std::make_shared<EventManager>(logger)),
      status(kStreamDeckPluginStatusDisconnected) {
    auto openCallback = std::bind(&StreamDeckPluginImpl::onPluginConnected, this, std::placeholders::_1);
    communicationManager->setOpenCallback(openCallback);

    auto writeCallback = std::bind(&StreamDeckPluginImpl::onEventWritten, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    communicationManager->setWriteCallback(writeCallback);

    auto readCallback = std::bind(&StreamDeckPluginImpl::onEventReceived, this, std::placeholders::_1, std::placeholders::_2);
    communicationManager->setReadCallback(readCallback);
}

auto StreamDeckPluginImpl::setStatusChangedCallback(StatusChangedCallback _statusChangedCallback) -> void {
    this->statusChangedCallback = _statusChangedCallback;
}

auto StreamDeckPluginImpl::getActions() -> Actions& {
    return *this->actionManager;
}

auto StreamDeckPluginImpl::getEvents() -> Events& {
    return *this->eventManager;
}

auto StreamDeckPluginImpl::run() -> void {
    boost::asio::io_context ioContext;
    communicationManager->configureWithIOContext(ioContext);

    // Prevent run to return even if there is no more work in the loop queue.
    boost::asio::executor_work_guard<boost::asio::io_context::executor_type> workGuard(ioContext.get_executor());

    setStatus(kStreamDeckPluginStatusConnecting);
    communicationManager->connect("localhost", this->registration->port);

    ioContext.run();
}

auto StreamDeckPluginImpl::setStatus(StreamDeckPluginStatus _status) -> void {
    if (this->status != _status) {
        this->status = _status;

        if (this->logger->isLogEnabled()) {
            this->logger->log(boost::format("Plugin status changed to '%1%'") % nameForStatus(_status));
        }

        if (this->statusChangedCallback) {
            this->statusChangedCallback(*this, this->status);
        }
    }
}

auto StreamDeckPluginImpl::onPluginConnected(CommunicationManager& communicationManager) -> void {
    setStatus(kStreamDeckPluginStatusRegistering);
    auto registrationEvent = this->registration->getRegistrationEvent();
    communicationManager.write(registrationEvent);
}

auto StreamDeckPluginImpl::onEventWritten(CommunicationManager& communicationManager, std::shared_ptr<event::SentEvent> event, bool writeSucceded) -> void {
    if (event->event == this->registration->registerEvent) {
        setStatus(kStreamDeckPluginStatusConnected);

        // Start reading events from websocket
        communicationManager.read();
    }
}

auto StreamDeckPluginImpl::onEventReceived(CommunicationManager& _communicationManager, std::unique_ptr<Event> event) -> void {
    if (this->logger->isLogEnabled()) {
        this->logger->log(boost::format("Received event '%1%'.") % event->event);
    }

    this->eventManager->onEventReceived(shared_from_this(), std::move(event));

    // Waiting for next event to come in.
    _communicationManager.read();
}

}  // namespace openstreamdeck::internal
