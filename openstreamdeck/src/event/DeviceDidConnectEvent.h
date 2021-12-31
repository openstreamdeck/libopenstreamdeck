//
// Created by Cyril Vlaminck on 26/12/2021.
//

#ifndef STREAMDECK_COMMAND_DEVICEDIDCONNECTEVENT_H
#define STREAMDECK_COMMAND_DEVICEDIDCONNECTEVENT_H

#include "Event.h"

namespace openstreamdeck {

constexpr char kDeviceDidConnectEvent[] = "deviceDidConnect";

/**
 * Event received by the plugin when a device is plugged to the computer.
 *
 * https://developer.elgato.com/documentation/stream-deck/sdk/events-received/#devicedidconnect
 */
class DeviceDidConnectEvent : public Event {
   public:
    /**
     * Type of device.
     */
    const uint8_t type;
    /**
     * The number of columns of keys that the device owns.
     */
    const uint8_t sizeColumns;
    /**
     * The number of rows of keys that the device owns.
     */
    const uint8_t sizeRows;
    /**
     * The name of the device set by the user.
     */
    const std::string name;

    DeviceDidConnectEvent(std::string device, uint8_t type, uint8_t sizeColumns, uint8_t sizeRows, std::string name);
    ~DeviceDidConnectEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_DEVICEDIDCONNECTEVENT_H
