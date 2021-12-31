//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_SETGLOBALSETTINGSSENTEVENT_H
#define STREAMDECK_COMMAND_SETGLOBALSETTINGSSENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class SetGlobalSettingsSentEvent : public SentEvent {
   public:
    const boost::json::object payload;

    SetGlobalSettingsSentEvent(std::string context, boost::json::object payload);
    auto serializeToJson() -> boost::json::object override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_SETGLOBALSETTINGSSENTEVENT_H
