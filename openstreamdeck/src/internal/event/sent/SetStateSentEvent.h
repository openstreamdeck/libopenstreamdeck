//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_SETSTATESENTEVENT_H
#define STREAMDECK_COMMAND_SETSTATESENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class SetStateSentEvent : public SentEvent {
   public:
    const uint8_t state;

    SetStateSentEvent(std::string context, uint8_t state);
    auto serializeToJson() -> boost::json::object override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_SETSTATESENTEVENT_H
