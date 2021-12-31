//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_APPLICATIONDIDLAUNCHEVENTPARSER_H
#define STREAMDECK_COMMAND_APPLICATIONDIDLAUNCHEVENTPARSER_H

#include "EventParser.h"

namespace openstreamdeck::internal::event {

class ApplicationDidLaunchEventParser : public EventParser {
   public:
    ApplicationDidLaunchEventParser();
    [[nodiscard]] auto parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_APPLICATIONDIDLAUNCHEVENTPARSER_H
