//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "DidReceiveGlobalSettingsEventParser.h"

#include "EventKeys.h"
#include "event/DidReceiveGlobalSettingsEvent.h"

namespace openstreamdeck::internal::event {

DidReceiveGlobalSettingsEventParser::DidReceiveGlobalSettingsEventParser() : EventParser(kDidReceiveGlobalSettingsEvent) {
}

auto DidReceiveGlobalSettingsEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    const auto &payload = this->parsePayload(json);

    return std::make_unique<DidReceiveGlobalSettingsEvent>(EventParser::parseObject(payload, kEventPayloadSettingKey));
}

}  // namespace openstreamdeck::internal::event
