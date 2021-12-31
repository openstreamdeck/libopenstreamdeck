//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_DIDRECEIVEGLOBALSETTINGSEVENTPARSER_H
#define STREAMDECK_COMMAND_DIDRECEIVEGLOBALSETTINGSEVENTPARSER_H

#include "EventParser.h"

namespace openstreamdeck::internal::event {

class DidReceiveGlobalSettingsEventParser : public EventParser {
   public:
    DidReceiveGlobalSettingsEventParser();
    [[nodiscard]] auto parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> override;
};

}

#endif  // STREAMDECK_COMMAND_DIDRECEIVEGLOBALSETTINGSEVENTPARSER_H
