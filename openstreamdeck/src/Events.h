//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_EVENTS_H
#define STREAMDECK_COMMAND_EVENTS_H

#include <functional>

#include "event/KeyDownEvent.h"
#include "event/KeyUpEvent.h"

namespace openstreamdeck {

class StreamDeckPlugin;

class Events {
   public:
    virtual auto setKeyDownCallback(std::function<void(std::shared_ptr<StreamDeckPlugin>, std::unique_ptr<KeyDownEvent>)> callback) -> void = 0;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_EVENTS_H
