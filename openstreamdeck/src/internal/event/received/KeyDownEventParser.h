//
// Created by Cyril Vlaminck on 25/12/2021.
//

#ifndef STREAMDECK_COMMAND_KEYDOWNEVENTPARSER_H
#define STREAMDECK_COMMAND_KEYDOWNEVENTPARSER_H

#include "EventParser.h"

namespace openstreamdeck::internal::event {

class KeyDownEventParser : public EventParser {
   public:
    KeyDownEventParser();
    [[nodiscard]] auto parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> override;
};

}

#endif  // STREAMDECK_COMMAND_KEYDOWNEVENTPARSER_H
