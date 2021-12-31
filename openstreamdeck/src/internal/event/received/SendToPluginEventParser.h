//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_SENDTOPLUGINEVENTPARSER_H
#define STREAMDECK_COMMAND_SENDTOPLUGINEVENTPARSER_H

#include "EventParser.h"

namespace openstreamdeck::internal::event {

class SendToPluginEventParser : public EventParser {
   public:
    SendToPluginEventParser();
    [[nodiscard]] auto parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> override;
};

}

#endif  // STREAMDECK_COMMAND_SENDTOPLUGINEVENTPARSER_H
