//
// Created by Cyril Vlaminck on 28/12/2021.
//

#include "SetTitleSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kSetTitleSentEvent[] = "setTitle";
constexpr char kSetTitleSentEventTitleKey[] = "title";
constexpr char kSetTitleSentEventTargetKey[] = "target";
constexpr char kSetTitleSentEventStateKey[] = "state";

SetTitleSentEvent::SetTitleSentEvent(std::string context, std::string title, SetTitleTarget target, std::optional<uint8_t> state)
    : SentEvent(kSetTitleSentEvent, std::move(context)), title(std::move(title)), target(target), state(state) {
}

auto SetTitleSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();

    boost::json::object payload;
    payload[kSetTitleSentEventTitleKey] = this->title;
    payload[kSetTitleSentEventTargetKey] = this->target;
    if (this->state) {
        payload[kSetTitleSentEventStateKey] = this->state.value();
    }
    jsonEvent[kSentEventPayloadKey] = payload;

    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
