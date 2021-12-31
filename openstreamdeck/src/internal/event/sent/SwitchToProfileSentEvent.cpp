//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "SwitchToProfileSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kSwitchToProfileSentEvent[] = "switchToProfile";
constexpr char kSwitchToProfileSentEventDeviceKey[] = "device";
constexpr char kSwitchToProfileSentEventProfileKey[] = "profile";

SwitchToProfileSentEvent::SwitchToProfileSentEvent(std::string context, std::string device, std::string profile)
    : SentEvent(kSwitchToProfileSentEvent, std::move(context)), device(std::move(device)), profile(std::move(profile)) {
}

auto SwitchToProfileSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();
    jsonEvent[kSwitchToProfileSentEventDeviceKey] = this->device;
    jsonEvent[kSentEventPayloadKey] = {{kSwitchToProfileSentEventProfileKey, this->profile}};
    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
