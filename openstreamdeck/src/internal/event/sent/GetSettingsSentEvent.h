//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_GETSETTINGSSENTEVENT_H
#define STREAMDECK_COMMAND_GETSETTINGSSENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class GetSettingsSentEvent : public SentEvent {
   public:
    GetSettingsSentEvent(std::string context);
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_GETSETTINGSSENTEVENT_H
