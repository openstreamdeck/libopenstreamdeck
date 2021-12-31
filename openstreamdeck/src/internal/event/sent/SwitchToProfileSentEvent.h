//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_SWITCHTOPROFILESENTEVENT_H
#define STREAMDECK_COMMAND_SWITCHTOPROFILESENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class SwitchToProfileSentEvent : public SentEvent {
   public:
    const std::string device;
    const std::string profile;

    SwitchToProfileSentEvent(std::string context, std::string device, std::string profile);
    auto serializeToJson() -> boost::json::object override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_SWITCHTOPROFILESENTEVENT_H
