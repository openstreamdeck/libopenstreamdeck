//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_DIDRECEIVESETTINGSEVENTPARSER_H
#define STREAMDECK_COMMAND_DIDRECEIVESETTINGSEVENTPARSER_H

#include "EventParser.h"

namespace openstreamdeck::internal::event {

class DidReceiveSettingsEventParser : public EventParser {
   public:
    DidReceiveSettingsEventParser();
    [[nodiscard]] auto parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_DIDRECEIVESETTINGSEVENTPARSER_H
