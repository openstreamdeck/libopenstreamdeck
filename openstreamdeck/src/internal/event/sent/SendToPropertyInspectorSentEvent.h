//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_SENDTOPROPERTYINSPECTORSENTEVENT_H
#define STREAMDECK_COMMAND_SENDTOPROPERTYINSPECTORSENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class SendToPropertyInspectorSentEvent : public SentEvent {
   public:
    const std::string action;
    const boost::json::object payload;

    SendToPropertyInspectorSentEvent(std::string context, std::string action, boost::json::object payload);
    auto serializeToJson() -> boost::json::object override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_SENDTOPROPERTYINSPECTORSENTEVENT_H
