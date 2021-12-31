//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_SHOWOKSENTEVENT_H
#define STREAMDECK_COMMAND_SHOWOKSENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class ShowOkSentEvent : public SentEvent {
   public:
    ShowOkSentEvent(std::string context);
};

}

#endif  // STREAMDECK_COMMAND_SHOWOKSENTEVENT_H
