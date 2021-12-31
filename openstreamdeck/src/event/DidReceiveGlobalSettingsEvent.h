//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_DIDRECEIVEGLOBALSETTINGSEVENT_H
#define STREAMDECK_COMMAND_DIDRECEIVEGLOBALSETTINGSEVENT_H

#include "Event.h"

#include <boost/json.hpp>

namespace openstreamdeck {

constexpr char kDidReceiveGlobalSettingsEvent[] = "didReceiveGlobalSettings";

/**
 * Event received after calling the getGlobalSettings API to retrieve the global persistent data stored for the plugin.
 */
class DidReceiveGlobalSettingsEvent : public Event {
   public:
    const boost::json::object settings;

    DidReceiveGlobalSettingsEvent(boost::json::object settings);
    ~DidReceiveGlobalSettingsEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_DIDRECEIVEGLOBALSETTINGSEVENT_H
