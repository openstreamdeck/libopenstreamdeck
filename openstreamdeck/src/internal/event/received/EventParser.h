//
// Created by Cyril Vlaminck on 25/12/2021.
//

#ifndef STREAMDECK_COMMAND_EVENTPARSER_H
#define STREAMDECK_COMMAND_EVENTPARSER_H

#include <boost/json.hpp>
#include <memory>

#include "event/Event.h"

namespace openstreamdeck::internal::event {

class EventParser {
   public:
    const std::string event;

    EventParser(std::string event);

    /**
     *
     * @param json
     * @return
     */
    [[nodiscard]] virtual auto parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> = 0;

    [[nodiscard]] static auto parseValue(const boost::json::object &json, boost::string_view key) -> const boost::json::value &;
    [[nodiscard]] static auto parseBoolean(const boost::json::object &json, boost::string_view key) -> bool;
    [[nodiscard]] static auto parseString(const boost::json::object &json, boost::string_view key) -> std::string;
    [[nodiscard]] static auto parseUint8(const boost::json::object &json, boost::string_view key) -> uint8_t;
    [[nodiscard]] static auto parseOptionalUint8(const boost::json::object &json, boost::string_view key) -> std::optional<uint8_t>;
    [[nodiscard]] static auto parseObject(const boost::json::object &json, boost::string_view key) -> const boost::json::object &;

   protected:
    [[nodiscard]] auto parseAction(const boost::json::object &json) const -> std::string;
    [[nodiscard]] auto parseContext(const boost::json::object &json) const -> std::string;
    [[nodiscard]] auto parseDevice(const boost::json::object &json) const -> std::string;
    [[nodiscard]] auto parsePayload(const boost::json::object &json) const -> const boost::json::object &;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_EVENTPARSER_H
