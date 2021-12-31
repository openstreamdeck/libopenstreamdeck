//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_EVENTMANAGER_H
#define STREAMDECK_COMMAND_EVENTMANAGER_H

#include "Logger.h"
#include "Events.h"

namespace openstreamdeck::internal {

class EventManager : public Events {
   private:
    const std::shared_ptr<Logger> logger;
    std::map<std::string, std::function<void(std::shared_ptr<StreamDeckPlugin>, std::unique_ptr<Event>)>> eventReceivedCallbacks;

   public:
    EventManager(std::shared_ptr<Logger> logger);

    auto onEventReceived(std::shared_ptr<StreamDeckPlugin> plugins, std::unique_ptr<Event> event) -> void;

    auto setKeyDownCallback(std::function<void(std::shared_ptr<StreamDeckPlugin>, std::unique_ptr<KeyDownEvent>)> callback) -> void override;
};

}  // namespace openstreamdeck::internal

#endif  // STREAMDECK_COMMAND_EVENTMANAGER_H
