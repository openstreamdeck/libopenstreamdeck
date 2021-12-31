//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_PROPERTYINSPECTORDIDDISAPPEAREVENTPARSER_H
#define STREAMDECK_COMMAND_PROPERTYINSPECTORDIDDISAPPEAREVENTPARSER_H

#include "EventParser.h"

namespace openstreamdeck::internal::event {

class PropertyInspectorDidDisappearEventParser : public EventParser {
   public:
    PropertyInspectorDidDisappearEventParser();
    [[nodiscard]] auto parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_PROPERTYINSPECTORDIDDISAPPEAREVENTPARSER_H
