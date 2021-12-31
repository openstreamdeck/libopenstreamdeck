//
// Created by Cyril Vlaminck on 26/12/2021.
//

#include "WillAppearEventParser.h"

#include "EventKeys.h"
#include "event/WillAppearEvent.h"

namespace openstreamdeck::internal::event {

WillAppearEventParser::WillAppearEventParser() : EventParser(kWillAppearEvent) {
}

auto WillAppearEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    const auto &payload = this->parsePayload(json);
    const auto &coordinates = EventParser::parseObject(payload, kEventPayloadCoordinatesKey);

    return std::make_unique<WillAppearEvent>(
        this->parseAction(json), this->parseContext(json), this->parseDevice(json), EventParser::parseObject(payload, kEventPayloadSettingKey),
        EventParser::parseUint8(coordinates, kEventPayloadCoordinatesColumnKey), EventParser::parseUint8(coordinates, kEventPayloadCoordinatesRowKey),
        EventParser::parseOptionalUint8(payload, kEventPayloadStateKey), EventParser::parseBoolean(payload, kEventPayloadIsInMultiActionKey));
}

}  // namespace openstreamdeck::internal::event
