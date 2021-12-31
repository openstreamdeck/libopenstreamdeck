//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_GETGLOBALSETTINGSSENTEVENT_H
#define STREAMDECK_COMMAND_GETGLOBALSETTINGSSENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class GetGlobalSettingsSentEvent : public SentEvent {
   public:
    GetGlobalSettingsSentEvent(std::string context);
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_GETGLOBALSETTINGSSENTEVENT_H
