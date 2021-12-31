//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_SENDTOPLUGINEVENT_H
#define STREAMDECK_COMMAND_SENDTOPLUGINEVENT_H

#include "Event.h"

#include <boost/json.hpp>

namespace openstreamdeck {

constexpr char kSendToPluginEvent[] = "sendToPlugin";

/**
 * Event received when the Property Inspector sends a sendToPlugin event.
 */
class SendToPluginEvent : public Event {
   public:
    /**
     * Payload sent by the Property Inspector.
     */
    const boost::json::object payload;

    SendToPluginEvent(std::string action, std::string context, boost::json::object payload);
    ~SendToPluginEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_SENDTOPLUGINEVENT_H
