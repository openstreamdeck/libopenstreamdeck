//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "PropertyInspectorDidAppearEventParser.h"

#include "event/PropertyInspectorDidAppearEvent.h"

namespace openstreamdeck::internal::event {

PropertyInspectorDidAppearEventParser::PropertyInspectorDidAppearEventParser() : EventParser(kPropertyInspectorDidAppearEvent) {
}

auto PropertyInspectorDidAppearEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    return std::make_unique<PropertyInspectorDidAppearEvent>(this->parseAction(json), this->parseContext(json), this->parseDevice(json));
}

}  // namespace openstreamdeck::internal::event
