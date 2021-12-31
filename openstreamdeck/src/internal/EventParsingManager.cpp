//
// Created by Cyril Vlaminck on 25/12/2021.
//

#include "EventParsingManager.h"

#include <boost/format.hpp>
#include <utility>

#include "event/received/ApplicationDidLaunchEventParser.h"
#include "event/received/ApplicationDidTerminateEventParser.h"
#include "event/received/DeviceDidConnectEventParser.h"
#include "event/received/DeviceDidDisconnectEventParser.h"
#include "event/received/DidReceiveGlobalSettingsEventParser.h"
#include "event/received/DidReceiveSettingsEventParser.h"
#include "event/received/KeyDownEventParser.h"
#include "event/received/KeyUpEventParser.h"
#include "event/received/PropertyInspectorDidAppearEventParser.h"
#include "event/received/PropertyInspectorDidDisappearEventParser.h"
#include "event/received/SendToPluginEventParser.h"
#include "event/received/SystemDidWakeUpEventParser.h"
#include "event/received/TitleParametersDidChangeEventParser.h"
#include "event/received/WillAppearEventParser.h"
#include "event/received/WillDisappearEventParser.h"

using namespace boost::json;
using namespace openstreamdeck::internal::event;

namespace openstreamdeck::internal {

EventParsingManager::EventParsingManager(std::shared_ptr<Logger> _logger) : logger(std::move(_logger)), eventParsers() {
    this->registerEventParser(std::make_shared<ApplicationDidLaunchEventParser>());
    this->registerEventParser(std::make_shared<ApplicationDidTerminateEventParser>());
    this->registerEventParser(std::make_shared<DeviceDidConnectEventParser>());
    this->registerEventParser(std::make_shared<DeviceDidDisconnectEventParser>());
    this->registerEventParser(std::make_shared<DidReceiveGlobalSettingsEventParser>());
    this->registerEventParser(std::make_shared<DidReceiveSettingsEventParser>());
    this->registerEventParser(std::make_shared<KeyDownEventParser>());
    this->registerEventParser(std::make_shared<KeyUpEventParser>());
    this->registerEventParser(std::make_shared<PropertyInspectorDidAppearEventParser>());
    this->registerEventParser(std::make_shared<PropertyInspectorDidDisappearEventParser>());
    this->registerEventParser(std::make_shared<SendToPluginEventParser>());
    this->registerEventParser(std::make_shared<SystemDidWakeUpEventParser>());
    this->registerEventParser(std::make_shared<TitleParametersDidChangeEventParser>());
    this->registerEventParser(std::make_shared<WillAppearEventParser>());
    this->registerEventParser(std::make_shared<WillDisappearEventParser>());
}

auto EventParsingManager::parseEvent(const std::string& serializedJson) const -> std::unique_ptr<Event> {
    error_code ec;
    auto value = parse(serializedJson, ec);
    if (ec) {
        throw std::invalid_argument((boost::format("Failed to parse event with error code: %1%") % ec).str());
    }
    if (!value.is_object()) {
        throw std::invalid_argument("Event must be an object to be parsed.");
    }
    auto json = value.as_object();

    const auto event = EventParser::parseString(json, "event");
    if (!this->eventParsers.contains(event)) {
        throw std::invalid_argument((boost::format("No parser available to parse event '%1%'.") % event).str());
    }
    auto parser = this->eventParsers.at(event);
    return parser->parseEvent(json);
}

auto EventParsingManager::registerEventParser(const std::shared_ptr<event::EventParser>& eventParser) -> void {
    this->eventParsers[eventParser->event] = eventParser;
}

}  // namespace openstreamdeck::internal
