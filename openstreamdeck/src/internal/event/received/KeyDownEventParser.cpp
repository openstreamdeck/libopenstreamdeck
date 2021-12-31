//
// Created by Cyril Vlaminck on 25/12/2021.
//

#include "KeyDownEventParser.h"

#include "EventKeys.h"
#include "event/KeyDownEvent.h"

namespace openstreamdeck::internal::event {

KeyDownEventParser::KeyDownEventParser() : EventParser(kKeyDownEvent) {
}

auto KeyDownEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    const auto &payload = this->parsePayload(json);
    const auto &coordinates = EventParser::parseObject(payload, kEventPayloadCoordinatesKey);

    return std::make_unique<KeyDownEvent>(
        this->parseAction(json), this->parseContext(json), this->parseDevice(json), EventParser::parseObject(payload, kEventPayloadSettingKey),
        EventParser::parseUint8(coordinates, kEventPayloadCoordinatesColumnKey), EventParser::parseUint8(coordinates, kEventPayloadCoordinatesRowKey),
        EventParser::parseOptionalUint8(payload, kEventPayloadStateKey), EventParser::parseOptionalUint8(payload, kEventPayloadUserDesiredStateKey),
        EventParser::parseBoolean(payload, kEventPayloadIsInMultiActionKey));
}

}  // namespace openstreamdeck::internal::event
