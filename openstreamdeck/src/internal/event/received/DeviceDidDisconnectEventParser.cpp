//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "DeviceDidDisconnectEventParser.h"

#include "event/DeviceDidDisconnectEvent.h"

namespace openstreamdeck::internal::event {

DeviceDidDisconnectEventParser::DeviceDidDisconnectEventParser() : EventParser(kDeviceDidDisconnectEvent) {
}

auto DeviceDidDisconnectEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    return std::make_unique<DeviceDidDisconnectEvent>(this->parseDevice(json));
}

}  // namespace openstreamdeck::internal::event
