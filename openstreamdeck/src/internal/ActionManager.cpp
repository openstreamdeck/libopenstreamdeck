//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "ActionManager.h"

#include <utility>

#include "event/sent/GetGlobalSettingsSentEvent.h"
#include "event/sent/GetSettingsSentEvent.h"
#include "event/sent/LogMessageSentEvent.h"
#include "event/sent/OpenUrlSentEvent.h"
#include "event/sent/SendToPropertyInspectorSentEvent.h"
#include "event/sent/SetGlobalSettingsSentEvent.h"
#include "event/sent/SetImageSentEvent.h"
#include "event/sent/SetSettingsSentEvent.h"
#include "event/sent/SetStateSentEvent.h"
#include "event/sent/SetTitleSentEvent.h"
#include "event/sent/ShowAlertSentEvent.h"
#include "event/sent/ShowOkSentEvent.h"
#include "event/sent/SwitchToProfileSentEvent.h"

using namespace openstreamdeck::internal::event;

namespace openstreamdeck::internal {

ActionManager::ActionManager(std::shared_ptr<Logger> logger, std::shared_ptr<CommunicationManager> communicationManager,
                             std::shared_ptr<Registration> registration)
    : logger(std::move(logger)), communicationManager(std::move(communicationManager)), registration(std::move(registration)) {
}

auto ActionManager::setSettings(std::string context, boost::json::object payload) -> void {
    auto event = std::make_shared<SetSettingsSentEvent>(std::move(context), std::move(payload));
    this->sendEvent(event);
}

auto ActionManager::getSettings(std::string context) -> void {
    auto event = std::make_shared<GetSettingsSentEvent>(std::move(context));
    this->sendEvent(event);
}

auto ActionManager::setGlobalSettings(boost::json::object payload) -> void {
    auto event = std::make_shared<SetGlobalSettingsSentEvent>(this->registration->pluginUUID, std::move(payload));
    this->sendEvent(event);
}

auto ActionManager::getGlobalSettings() -> void {
    auto event = std::make_shared<GetGlobalSettingsSentEvent>(this->registration->pluginUUID);
    this->sendEvent(event);
}

auto ActionManager::openUrl(std::string url) -> void {
    auto event = std::make_shared<OpenUrlSentEvent>(std::move(url));
    this->sendEvent(event);
}

auto ActionManager::logMessage(std::string message) -> void {
    auto event = std::make_shared<LogMessageSentEvent>(std::move(message));
    this->sendEvent(event);
}

auto ActionManager::setTitle(std::string context, std::string title, SetTitleTarget target, std::optional<uint8_t> state) -> void {
    auto event = std::make_shared<SetTitleSentEvent>(std::move(context), std::move(title), target, state);
    this->sendEvent(event);
}

auto ActionManager::setImage(std::string context, std::optional<std::string> image, SetImageTarget target, std::optional<uint8_t> state) -> void {
    auto event = std::make_shared<SetImageSentEvent>(std::move(context), std::move(image), target, state);
    this->sendEvent(event);
}

auto ActionManager::showAlert(std::string context) -> void {
    auto event = std::make_shared<ShowAlertSentEvent>(std::move(context));
    this->sendEvent(event);
}

auto ActionManager::showOk(std::string context) -> void {
    auto event = std::make_shared<ShowOkSentEvent>(std::move(context));
    this->sendEvent(event);
}

auto ActionManager::setState(std::string context, uint8_t state) -> void {
    auto event = std::make_shared<SetStateSentEvent>(std::move(context), state);
    this->sendEvent(event);
}

auto ActionManager::switchToProfile(std::string device, std::string profile) -> void {
    auto event = std::make_shared<SwitchToProfileSentEvent>(this->registration->pluginUUID, std::move(device), std::move(profile));
    this->sendEvent(event);
}

auto ActionManager::sendToPropertyInspector(std::string context, std::string action, boost::json::object payload) -> void {
    auto event = std::make_shared<SendToPropertyInspectorSentEvent>(std::move(context), std::move(action), std::move(payload));
    this->sendEvent(event);
}

auto ActionManager::sendEvent(std::shared_ptr<event::SentEvent> event) -> void {
    if (logger->isLogEnabled()) {
        logger->log(boost::format("Sending event '%1%'.") % event->event);
    }
    this->communicationManager->write(std::move(event));
}

}  // namespace openstreamdeck::internal
