//
// Created by Cyril Vlaminck on 26/12/2021.
//

#ifndef STREAMDECK_COMMAND_WILLAPPEAREVENTPARSER_H
#define STREAMDECK_COMMAND_WILLAPPEAREVENTPARSER_H

#include "EventParser.h"

namespace openstreamdeck::internal::event {

class WillAppearEventParser : public EventParser {
   public:
    WillAppearEventParser();
    [[nodiscard]] auto parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_WILLAPPEAREVENTPARSER_H
