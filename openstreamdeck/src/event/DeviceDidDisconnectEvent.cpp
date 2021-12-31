//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "DeviceDidDisconnectEvent.h"

namespace openstreamdeck {

DeviceDidDisconnectEvent::DeviceDidDisconnectEvent(std::string device) : Event(kDeviceDidDisconnectEvent, "", "", std::move(device)) {
}

DeviceDidDisconnectEvent::~DeviceDidDisconnectEvent() = default;

}  // namespace openstreamdeck
