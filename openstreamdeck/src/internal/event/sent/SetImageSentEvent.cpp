//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "SetImageSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kSetImageSentEvent[] = "setImage";
constexpr char kSetImageSentEventImageKey[] = "image";
constexpr char kSetImageSentEventTargetKey[] = "target";
constexpr char kSetImageSentEventStateKey[] = "state";

SetImageSentEvent::SetImageSentEvent(std::string context, std::optional<std::string> image, SetImageTarget target, std::optional<uint8_t> state)
    : SentEvent(kSetImageSentEvent, std::move(context)), image(std::move(image)), target(target), state(state) {
}

auto SetImageSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();

    boost::json::object payload;
    payload[kSetImageSentEventTargetKey] = this->target;
    if (this->image) {
        payload[kSetImageSentEventImageKey] = this->image.value();
    }
    if (this->state) {
        payload[kSetImageSentEventStateKey] = this->state.value();
    }
    jsonEvent[kSentEventPayloadKey] = std::move(payload);

    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
