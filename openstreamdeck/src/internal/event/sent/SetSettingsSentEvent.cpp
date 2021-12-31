//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "SetSettingsSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kSetSettingsSentEvent[] = "setSettings";

SetSettingsSentEvent::SetSettingsSentEvent(std::string context, boost::json::object payload)
    : SentEvent(kSetSettingsSentEvent, std::move(context)), payload(std::move(payload)) {
}

auto SetSettingsSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();
    jsonEvent[kSentEventPayloadKey] = this->payload;
    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
