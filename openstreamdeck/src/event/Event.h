//
// Created by Cyril Vlaminck on 25/12/2021.
//

#ifndef STREAMDECK_COMMAND_EVENT_H
#define STREAMDECK_COMMAND_EVENT_H

#include <string>

namespace openstreamdeck {

class Event {
   public:
    virtual ~Event();

    /**
     * The event identifier.
     */
    const std::string event;
    /**
     * The action unique identifier.
     */
    const std::string action;
    /**
     * An opaque value identifying the instance's action.
     */
    const std::string context;
    /**
     * An opaque value identifying the device.
     */
    const std::string device;

    Event(std::string&& event, std::string&& action, std::string&& context, std::string&& device);
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_EVENT_H
