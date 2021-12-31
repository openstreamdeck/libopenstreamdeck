//
// Created by Cyril Vlaminck on 24/12/2021.
//

#ifndef STREAMDECK_COMMAND_STREAMDECKPLUGINIMPL_H
#define STREAMDECK_COMMAND_STREAMDECKPLUGINIMPL_H

#include "../StreamDeckPlugin.h"
#include "ActionManager.h"
#include "CommunicationManager.h"
#include "EventManager.h"
#include "StreamDeckPluginStatus.h"

namespace openstreamdeck::internal {

class StreamDeckPluginImpl : public StreamDeckPlugin, public std::enable_shared_from_this<StreamDeckPluginImpl> {
   private:
    const std::shared_ptr<Logger> logger;
    const std::shared_ptr<EventParsingManager> eventParsingManager;
    const std::shared_ptr<CommunicationManager> communicationManager;
    const std::shared_ptr<ActionManager> actionManager;
    const std::shared_ptr<EventManager> eventManager;

    StreamDeckPluginStatus status;
    const std::shared_ptr<Registration> registration;

    StatusChangedCallback statusChangedCallback;

   public:
    StreamDeckPluginImpl(int argc, const char* argv[]);
    ~StreamDeckPluginImpl() override = default;

    auto setStatusChangedCallback(StatusChangedCallback statusChangedCallback) -> void override;

    auto getActions() -> Actions& override;

    auto getEvents() -> Events& override;

    auto run() -> void override;

   private:
    auto setStatus(StreamDeckPluginStatus status) -> void;

    auto onPluginConnected(CommunicationManager& communicationManager) -> void;
    auto onEventWritten(CommunicationManager& communicationManager, std::shared_ptr<event::SentEvent> event, bool writeSucceded) -> void;
    auto onEventReceived(CommunicationManager& communicationManager, std::unique_ptr<Event> event) -> void;
};

}  // namespace openstreamdeck::internal

#endif  // STREAMDECK_COMMAND_STREAMDECKPLUGINIMPL_H
