//
// Created by Cyril Vlaminck on 25/12/2021.
//

#include "EventParser.h"

#include <boost/format.hpp>

#include "EventKeys.h"

namespace openstreamdeck::internal::event {

EventParser::EventParser(std::string event) : event(std::move(event)) {
}

auto EventParser::parseValue(const boost::json::object &json, boost::string_view key) -> const boost::json::value & {
    if (!json.if_contains(key)) {
        throw std::invalid_argument((boost::format("Missing key '%1%'. %2%") % key % boost::json::serialize(json)).str());
    }
    return json.at(key);
}

auto EventParser::parseBoolean(const boost::json::object &json, boost::string_view key) -> bool {
    const auto value = parseValue(json, key);
    if (!value.is_bool()) {
        throw std::invalid_argument((boost::format("Value of key '%1%' is not a boolean.") % key).str());
    }
    return value.as_bool();
}

auto EventParser::parseString(const boost::json::object &json, boost::string_view key) -> std::string {
    const auto value = parseValue(json, key);
    if (!value.is_string()) {
        throw std::invalid_argument((boost::format("Value of key '%1%' is not a string.") % key).str());
    }
    return std::string(value.as_string());
}

auto EventParser::parseUint8(const boost::json::object &json, boost::string_view key) -> uint8_t {
    const auto value = parseValue(json, key);
    if (!value.is_int64()) {
        throw std::invalid_argument((boost::format("Value of key '%1%' is not an integer.") % key).str());
    }
    auto intValue = value.as_int64();
    if (intValue < 0) {
        throw std::invalid_argument((boost::format("Value of key '%1%' is not valid: %2% < 0") % key % intValue).str());
    }
    if (intValue > UINT8_MAX) {
        throw std::invalid_argument((boost::format("Value of key '%1%' is not valid: %2% > %3%") % key % intValue % UINT8_MAX).str());
    }
    return intValue;
}

auto EventParser::parseOptionalUint8(const boost::json::object &json, boost::string_view key) -> std::optional<uint8_t> {
    if (!json.if_contains(key)) {
        return std::nullopt;
    } else {
        return EventParser::parseUint8(json, key);
    }
}

auto EventParser::parseObject(const boost::json::object &json, boost::string_view key) -> const boost::json::object & {
    const auto &value = parseValue(json, key);
    if (!value.is_object()) {
        throw std::invalid_argument((boost::format("Value of key '%1%' is not an object.") % key).str());
    }
    return value.get_object();
}

auto EventParser::parseAction(const boost::json::object &json) const -> std::string {
    return std::move(this->parseString(json, kEventActionKey));
}

auto EventParser::parseDevice(const boost::json::object &json) const -> std::string {
    return std::move(this->parseString(json, kEventDeviceKey));
}

auto EventParser::parseContext(const boost::json::object &json) const -> std::string {
    return std::move(this->parseString(json, kEventContextKey));
}

auto EventParser::parsePayload(const boost::json::object &json) const -> const boost::json::object & {
    const auto &payload = EventParser::parseObject(json, kEventPayloadKey);
    return payload;
}

}  // namespace openstreamdeck::internal::event
