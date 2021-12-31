//
// Created by Cyril Vlaminck on 25/12/2021.
//

#include "RegistrationSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kRegistrationSentEventUUIDKey[] = "uuid";

RegistrationSentEvent::RegistrationSentEvent(std::string event, std::string pluginUUID) : SentEvent(std::move(event)), pluginUUID(std::move(pluginUUID)) {
}

auto RegistrationSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();
    jsonEvent[kRegistrationSentEventUUIDKey] = this->pluginUUID;
    return std::move(jsonEvent);
}

}  // namespace streamdeck::internal::event
