//
// Created by Cyril Vlaminck on 26/12/2021.
//

#include "DeviceDidConnectEventParser.h"

#include "EventKeys.h"
#include "event/DeviceDidConnectEvent.h"

namespace openstreamdeck::internal::event {

DeviceDidConnectEventParser::DeviceDidConnectEventParser() : EventParser(kDeviceDidConnectEvent) {
}

auto DeviceDidConnectEventParser::parseEvent(const boost::json::object &json) const -> std::unique_ptr<Event> {
    const auto &deviceInfo = EventParser::parseObject(json, kEventDeviceInfoKey);
    const auto &size = EventParser::parseObject(deviceInfo, kEventDeviceInfoSizeKey);

    return std::make_unique<DeviceDidConnectEvent>(
        this->parseDevice(json), EventParser::parseUint8(deviceInfo, kEventDeviceInfoTypeKey), EventParser::parseUint8(size, kEventDeviceInfoSizeColumnsKey),
        EventParser::parseUint8(size, kEventDeviceInfoSizeRowsKey), EventParser::parseString(deviceInfo, kEventDeviceInfoNameKey));
}

}  // namespace openstreamdeck::internal::event
