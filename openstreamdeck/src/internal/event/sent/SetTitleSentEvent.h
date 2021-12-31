//
// Created by Cyril Vlaminck on 28/12/2021.
//

#ifndef STREAMDECK_COMMAND_SETTITLESENTEVENT_H
#define STREAMDECK_COMMAND_SETTITLESENTEVENT_H

#include "SentEvent.h"
#include "Actions.h"

namespace openstreamdeck::internal::event {

class SetTitleSentEvent : public SentEvent {
   public:
    const std::string title;
    const SetTitleTarget target;
    const std::optional<uint8_t> state;

    SetTitleSentEvent(std::string context, std::string title, SetTitleTarget target, std::optional<uint8_t> state);
    auto serializeToJson() -> boost::json::object override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_SETTITLESENTEVENT_H
