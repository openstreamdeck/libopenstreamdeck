//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "PropertyInspectorDidDisappearEventParser.h"

#include "event/PropertyInspectorDidDisappearEvent.h"

namespace openstreamdeck::internal::event {

PropertyInspectorDidDisappearEventParser::PropertyInspectorDidDisappearEventParser() : EventParser(kPropertyInspectorDidDisappearEvent) {
}

auto PropertyInspectorDidDisappearEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    return std::make_unique<PropertyInspectorDidDisappearEvent>(this->parseAction(json), this->parseContext(json), this->parseDevice(json));
}

}  // namespace openstreamdeck::internal::event
