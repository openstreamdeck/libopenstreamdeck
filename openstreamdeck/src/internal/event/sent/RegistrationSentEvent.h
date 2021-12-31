//
// Created by Cyril Vlaminck on 25/12/2021.
//

#ifndef STREAMDECK_COMMAND_REGISTRATIONSENTEVENT_H
#define STREAMDECK_COMMAND_REGISTRATIONSENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

class RegistrationSentEvent : public SentEvent {
   private:
    const std::string pluginUUID;

   public:
    RegistrationSentEvent(std::string event, std::string pluginUUID);
    auto serializeToJson() -> boost::json::object override;
};

}  // namespace streamdeck::internal::event

#endif  // STREAMDECK_COMMAND_REGISTRATIONSENTEVENT_H
