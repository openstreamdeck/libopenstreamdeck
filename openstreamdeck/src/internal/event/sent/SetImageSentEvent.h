//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_SETIMAGESENTEVENT_H
#define STREAMDECK_COMMAND_SETIMAGESENTEVENT_H

#include "SentEvent.h"
#include "Actions.h"

namespace openstreamdeck::internal::event {

class SetImageSentEvent : public SentEvent {
   public:
    const std::optional<std::string> image;
    const SetImageTarget target;
    const std::optional<uint8_t> state;

    SetImageSentEvent(std::string context, std::optional<std::string> image, SetImageTarget target, std::optional<uint8_t> state);
    auto serializeToJson() -> boost::json::object override;
};

}

#endif  // STREAMDECK_COMMAND_SETIMAGESENTEVENT_H
