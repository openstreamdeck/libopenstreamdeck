//
// Created by Cyril Vlaminck on 24/12/2021.
//

#ifndef STREAMDECK_COMMAND_REGISTRATION_H
#define STREAMDECK_COMMAND_REGISTRATION_H

#include <cstdint>
#include <string>

#include "event/sent/RegistrationSentEvent.h"

namespace openstreamdeck::internal {

class Registration {
   public:
    const uint16_t port;
    const std::string pluginUUID;
    const std::string registerEvent;
    // FIXME Info

    Registration(uint16_t port, std::string pluginUUID, std::string registerEvent);

    /**
     * Return the event that must be sent to the Elgato Stream deck application through the websocket to register the plugin.
     */
    [[nodiscard]] auto getRegistrationEvent() const -> std::shared_ptr<event::RegistrationSentEvent>;
};

}  // namespace streamdeck::internal

#endif  // STREAMDECK_COMMAND_REGISTRATION_H
