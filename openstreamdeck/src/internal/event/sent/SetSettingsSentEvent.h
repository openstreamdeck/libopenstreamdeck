//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_SETSETTINGSSENTEVENT_H
#define STREAMDECK_COMMAND_SETSETTINGSSENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class SetSettingsSentEvent : public SentEvent {
   public:
    const boost::json::object payload;

    SetSettingsSentEvent(std::string context, boost::json::object payload);
    auto serializeToJson() -> boost::json::object override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_SETSETTINGSSENTEVENT_H
