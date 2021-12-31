//
// Created by Cyril Vlaminck on 25/12/2021.
//

#ifndef STREAMDECK_COMMAND_STREAMDECKPLUGINSTATUS_H
#define STREAMDECK_COMMAND_STREAMDECKPLUGINSTATUS_H

#include <string>

namespace openstreamdeck {

typedef enum {
    kStreamDeckPluginStatusDisconnected = 1000,
    kStreamDeckPluginStatusConnecting = 2000,
    kStreamDeckPluginStatusRegistering = 3000,
    kStreamDeckPluginStatusConnected = 4000
} StreamDeckPluginStatus;

auto nameForStatus(StreamDeckPluginStatus status) -> std::string;

}

#endif  // STREAMDECK_COMMAND_STREAMDECKPLUGINSTATUS_H
