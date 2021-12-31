//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_ACTIONMANAGER_H
#define STREAMDECK_COMMAND_ACTIONMANAGER_H

#include "Actions.h"
#include "CommunicationManager.h"
#include "Logger.h"
#include "Registration.h"
#include "event/sent/SentEvent.h"

namespace openstreamdeck::internal {

class ActionManager : public Actions {
   private:
    std::shared_ptr<Logger> logger;
    std::shared_ptr<CommunicationManager> communicationManager;

    const std::shared_ptr<Registration> registration;

   public:
    ActionManager(std::shared_ptr<Logger> logger, std::shared_ptr<CommunicationManager> communicationManager, std::shared_ptr<Registration> registration);

    auto setSettings(std::string context, boost::json::object payload) -> void override;
    auto getSettings(std::string context) -> void override;
    auto setGlobalSettings(boost::json::object payload) -> void override;
    auto getGlobalSettings() -> void override;
    auto openUrl(std::string url) -> void override;
    auto logMessage(std::string message) -> void override;
    auto setTitle(std::string context, std::string title, SetTitleTarget target, std::optional<uint8_t> state) -> void override;
    auto setImage(std::string context, std::optional<std::string> image, SetImageTarget target, std::optional<uint8_t> state) -> void override;
    auto showAlert(std::string context) -> void override;
    auto showOk(std::string context) -> void override;
    auto setState(std::string context, uint8_t state) -> void override;
    auto switchToProfile(std::string device, std::string profile) -> void override;
    auto sendToPropertyInspector(std::string context, std::string action, boost::json::object payload) -> void override;

   private:
    auto sendEvent(std::shared_ptr<event::SentEvent> event) -> void;
};

}  // namespace openstreamdeck::internal

#endif  // STREAMDECK_COMMAND_ACTIONMANAGER_H
