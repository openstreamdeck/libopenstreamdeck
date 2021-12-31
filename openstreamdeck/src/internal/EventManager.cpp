//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "EventManager.h"

#include <utility>

#include "StreamDeckPlugin.h"

namespace openstreamdeck::internal {

template <typename T>
auto convert(std::function<void(std::shared_ptr<StreamDeckPlugin>, std::unique_ptr<T>)> callback)
    -> std::function<void(std::shared_ptr<StreamDeckPlugin>, std::unique_ptr<Event>)> {
    return [callback](std::shared_ptr<StreamDeckPlugin> plugins, std::unique_ptr<Event> event) {
        auto *eventPointer = dynamic_cast<T *>(event.get());
        if (eventPointer) {
            event.release();
            callback(std::move(plugins), std::unique_ptr<T>(eventPointer));
        } else {
            throw std::invalid_argument((boost::format("Failed to convert event '%1%'") % event->event).str());
        }
    };
}

EventManager::EventManager(std::shared_ptr<Logger> logger) : logger(std::move(logger)), eventReceivedCallbacks() {
}

auto EventManager::onEventReceived(std::shared_ptr<StreamDeckPlugin> plugins, std::unique_ptr<Event> event) -> void {
    if (this->eventReceivedCallbacks.contains(event->event)) {
        auto callback = this->eventReceivedCallbacks[event->event];
        if (callback) {
            if (logger->isLogEnabled()) {
                logger->log(boost::format("Calling callback for event '%1%'.") % event->event);
            }
            callback(std::move(plugins), std::move(event));
        }
    } else {
        if (logger->isLogEnabled()) {
            logger->log(boost::format("No callback configured for event '%1%'.") % event->event);
        }
    }
}

auto EventManager::setKeyDownCallback(std::function<void(std::shared_ptr<StreamDeckPlugin>, std::unique_ptr<KeyDownEvent>)> callback) -> void {
    this->eventReceivedCallbacks[kKeyDownEvent] = convert(callback);
}

}  // namespace openstreamdeck::internal
