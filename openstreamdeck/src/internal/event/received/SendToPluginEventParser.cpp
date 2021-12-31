//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "SendToPluginEventParser.h"

#include "event/SendToPluginEvent.h"

namespace openstreamdeck::internal::event {

SendToPluginEventParser::SendToPluginEventParser() : EventParser(kSendToPluginEvent) {
}

auto SendToPluginEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    return std::make_unique<SendToPluginEvent>(this->parseAction(json), this->parseContext(json), this->parsePayload(json));
}

}  // namespace openstreamdeck::internal::event
