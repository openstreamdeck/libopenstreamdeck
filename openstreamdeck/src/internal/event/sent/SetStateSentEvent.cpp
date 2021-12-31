//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "SetStateSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kSetStateSentEvent[] = "setState";
constexpr char kSetStateSentEventStateKey[] = "state";

SetStateSentEvent::SetStateSentEvent(std::string context, uint8_t state) : SentEvent(kSetStateSentEvent, std::move(context)), state(state) {
}

auto SetStateSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();
    jsonEvent[kSentEventPayloadKey] = {{kSetStateSentEventStateKey, this->state}};
    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
