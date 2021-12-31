//
// Created by Cyril Vlaminck on 26/12/2021.
//

#include "DeviceDidConnectEvent.h"

#include <utility>

namespace openstreamdeck {

DeviceDidConnectEvent::DeviceDidConnectEvent(std::string device, uint8_t type, uint8_t sizeColumns, uint8_t sizeRows, std::string name)
    : Event(kDeviceDidConnectEvent, "", "", std::move(device)), type(type), sizeColumns(sizeColumns), sizeRows(sizeRows), name(std::move(name)) {
}

DeviceDidConnectEvent::~DeviceDidConnectEvent() = default;

}  // namespace openstreamdeck
