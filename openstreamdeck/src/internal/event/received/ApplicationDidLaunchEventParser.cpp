//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "ApplicationDidLaunchEventParser.h"

#include "EventKeys.h"
#include "event/ApplicationDidLaunchEvent.h"

namespace openstreamdeck::internal::event {

ApplicationDidLaunchEventParser::ApplicationDidLaunchEventParser() : EventParser(kApplicationDidLaunchEvent) {
}

auto ApplicationDidLaunchEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    const auto &payload = this->parsePayload(json);

    return std::make_unique<ApplicationDidLaunchEvent>(EventParser::parseString(payload, kEventPayloadApplication));
}

}  // namespace openstreamdeck::internal::event
