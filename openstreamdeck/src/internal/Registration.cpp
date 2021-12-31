//
// Created by Cyril Vlaminck on 24/12/2021.
//

#include "Registration.h"

namespace openstreamdeck::internal {

Registration::Registration(uint16_t port, std::string pluginUUID, std::string registerEvent)
    : port(port), pluginUUID(std::move(pluginUUID)), registerEvent(std::move(registerEvent)) {
}

auto Registration::getRegistrationEvent() const -> std::shared_ptr<event::RegistrationSentEvent> {
    return std::make_shared<event::RegistrationSentEvent>(this->registerEvent, this->pluginUUID);
}

}  // namespace streamdeck::internal
