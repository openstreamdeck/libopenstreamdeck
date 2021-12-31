//
// Created by Cyril Vlaminck on 26/12/2021.
//

#include "TitleParametersDidChangeEventParser.h"

#include "EventKeys.h"
#include "event/TitleParametersDidChangeEvent.h"

namespace openstreamdeck::internal::event {

TitleParametersDidChangeEventParser::TitleParametersDidChangeEventParser() : EventParser(kTitleParametersDidChangeEvent) {
}

auto TitleParametersDidChangeEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    const auto &payload = this->parsePayload(json);
    const auto &coordinates = EventParser::parseObject(payload, kEventPayloadCoordinatesKey);
    const auto &titleParameters = EventParser::parseObject(payload, kEventPayloadTitleParameters);

    return std::make_unique<TitleParametersDidChangeEvent>(
        this->parseAction(json), this->parseContext(json), this->parseDevice(json), EventParser::parseObject(payload, kEventPayloadSettingKey),
        EventParser::parseUint8(coordinates, kEventPayloadCoordinatesColumnKey), EventParser::parseUint8(coordinates, kEventPayloadCoordinatesRowKey),
        EventParser::parseUint8(payload, kEventPayloadStateKey), EventParser::parseString(payload, kEventPayloadTitleKey),
        EventParser::parseString(titleParameters, kEventPayloadTitleParametersFontFamily),
        EventParser::parseUint8(titleParameters, kEventPayloadTitleParametersFontSize),
        EventParser::parseString(titleParameters, kEventPayloadTitleParametersFontStyle),
        EventParser::parseBoolean(titleParameters, kEventPayloadTitleParametersFontUnderline),
        EventParser::parseBoolean(titleParameters, kEventPayloadTitleParametersShowTitle),
        EventParser::parseString(titleParameters, kEventPayloadTitleParametersTitleAlignment),
        EventParser::parseString(titleParameters, kEventPayloadTitleParametersTitleColor));
}

}  // namespace openstreamdeck::internal::event
