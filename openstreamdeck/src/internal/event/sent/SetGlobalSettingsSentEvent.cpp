//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "SetGlobalSettingsSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kSetGlobalSettingsSentEvent[] = "setGlobalSettings";

SetGlobalSettingsSentEvent::SetGlobalSettingsSentEvent(std::string context, boost::json::object payload)
    : SentEvent(kSetGlobalSettingsSentEvent, std::move(context)), payload(std::move(payload)) {
}

auto SetGlobalSettingsSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();
    jsonEvent[kSentEventPayloadKey] = this->payload;
    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
