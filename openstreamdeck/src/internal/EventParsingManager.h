//
// Created by Cyril Vlaminck on 25/12/2021.
//

#ifndef STREAMDECK_COMMAND_EVENTPARSINGMANAGER_H
#define STREAMDECK_COMMAND_EVENTPARSINGMANAGER_H

#include <map>

#include "Logger.h"
#include "event/received/EventParser.h"

namespace openstreamdeck::internal {

class EventParsingManager {
   private:
    std::shared_ptr<Logger> logger;
    std::map<std::string, std::shared_ptr<event::EventParser>> eventParsers;

   public:
    explicit EventParsingManager(std::shared_ptr<Logger> logger);

    /**
     * Parse the event coming from the Stream deck application.
     *
     * @param json Serialized event com
     * @throws std::invalid_argument If the json is not valid to be parsed into an event.
     * @return an object version of the event.
     */
    [[nodiscard]] auto parseEvent(const std::string& json) const -> std::unique_ptr<Event>;

   private:
    auto registerEventParser(const std::shared_ptr<event::EventParser>& eventParser) -> void;
};

}  // namespace openstreamdeck::internal

#endif  // STREAMDECK_COMMAND_EVENTPARSINGMANAGER_H
