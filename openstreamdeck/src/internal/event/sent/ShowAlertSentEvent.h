//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_SHOWALERTSENTEVENT_H
#define STREAMDECK_COMMAND_SHOWALERTSENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class ShowAlertSentEvent : public SentEvent {
   public:
    ShowAlertSentEvent(std::string context);
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_SHOWALERTSENTEVENT_H
