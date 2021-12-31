//
// Created by Cyril Vlaminck on 29/12/2021.
//

#ifndef STREAMDECK_COMMAND_OPENURLSENTEVENT_H
#define STREAMDECK_COMMAND_OPENURLSENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class OpenUrlSentEvent : public SentEvent {
   public:
    const std::string url;

    OpenUrlSentEvent(std::string url);
    auto serializeToJson() -> boost::json::object override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_OPENURLSENTEVENT_H
