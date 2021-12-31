//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_DEVICEDIDDISCONNECTEVENT_H
#define STREAMDECK_COMMAND_DEVICEDIDDISCONNECTEVENT_H

#include "Event.h"

namespace openstreamdeck {

constexpr char kDeviceDidDisconnectEvent[] = "deviceDidDisconnect";

/**
 * Event received when a device is unplugged from the computer.
 */
class DeviceDidDisconnectEvent : public Event {
   public:
    DeviceDidDisconnectEvent(std::string device);
    ~DeviceDidDisconnectEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_DEVICEDIDDISCONNECTEVENT_H
