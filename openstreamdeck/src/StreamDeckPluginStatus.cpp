//
// Created by Cyril Vlaminck on 25/12/2021.
//

#include "StreamDeckPluginStatus.h"

namespace openstreamdeck {

constexpr char kStreamDeckPluginStatusDisconnectedName[] = "disconnected";
constexpr char kStreamDeckPluginStatusConnectingName[] = "connecting";
constexpr char kStreamDeckPluginStatusRegisteringName[] = "registering";
constexpr char kStreamDeckPluginStatusConnectedName[] = "connected";

auto nameForStatus(StreamDeckPluginStatus status) -> std::string {
    switch (status) {
        case kStreamDeckPluginStatusDisconnected:
            return kStreamDeckPluginStatusDisconnectedName;
        case kStreamDeckPluginStatusConnecting:
            return kStreamDeckPluginStatusConnectingName;
        case kStreamDeckPluginStatusRegistering:
            return kStreamDeckPluginStatusRegisteringName;
        case kStreamDeckPluginStatusConnected:
            return kStreamDeckPluginStatusConnectedName;
    }
}

}  // namespace openstreamdeck
