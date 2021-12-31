//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "ApplicationDidTerminateEventParser.h"

#include "EventKeys.h"
#include "event/ApplicationDidTerminateEvent.h"

namespace openstreamdeck::internal::event {

ApplicationDidTerminateEventParser::ApplicationDidTerminateEventParser() : EventParser(kApplicationDidTerminateEvent) {
}

auto ApplicationDidTerminateEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    const auto &payload = this->parsePayload(json);

    return std::make_unique<ApplicationDidTerminateEvent>(EventParser::parseString(payload, kEventPayloadApplication));
}

}  // namespace openstreamdeck::internal::event
