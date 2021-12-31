//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "SystemDidWakeUpEventParser.h"

#include "event/SystemDidWakeUpEvent.h"

namespace openstreamdeck::internal::event {

SystemDidWakeUpEventParser::SystemDidWakeUpEventParser() : EventParser(kSystemDidWakeUpEvent) {
}

auto SystemDidWakeUpEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    return std::make_unique<SystemDidWakeUpEvent>();
}

}  // namespace openstreamdeck::internal::event
