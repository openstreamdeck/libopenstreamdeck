//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "DidReceiveSettingsEventParser.h"

#include "EventKeys.h"
#include "event/DidReceiveSettingsEvent.h"

namespace openstreamdeck::internal::event {

DidReceiveSettingsEventParser::DidReceiveSettingsEventParser() : EventParser(kDidReceiveSettingsEvent) {
}

auto DidReceiveSettingsEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    const auto &payload = this->parsePayload(json);
    const auto &coordinates = EventParser::parseObject(payload, kEventPayloadCoordinatesKey);

    return std::make_unique<DidReceiveSettingsEvent>(
        this->parseAction(json), this->parseContext(json), this->parseDevice(json), EventParser::parseObject(payload, kEventPayloadSettingKey),
        EventParser::parseUint8(coordinates, kEventPayloadCoordinatesColumnKey), EventParser::parseUint8(coordinates, kEventPayloadCoordinatesRowKey),
        EventParser::parseOptionalUint8(payload, kEventPayloadStateKey), EventParser::parseBoolean(payload, kEventPayloadIsInMultiActionKey));
}

}  // namespace openstreamdeck::internal::event
