//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_DIDRECEIVESETTINGSEVENT_H
#define STREAMDECK_COMMAND_DIDRECEIVESETTINGSEVENT_H

#include <boost/json.hpp>

#include "Event.h"

namespace openstreamdeck {

constexpr char kDidReceiveSettingsEvent[] = "didReceiveSettings";

class DidReceiveSettingsEvent : public Event {
   public:
    /**
     * This json object contains persistently stored data.
     */
    const boost::json::object settings;
    /**
     * The coordinates of the action triggered.
     */
    const uint8_t coordinatesColumn;
    /**
     * The coordinates of the action triggered.
     */
    const uint8_t coordinatesRow;
    /**
     * This is a parameter that is only set when the action has multiple states defined in its manifest.json. The 0-based value contains the current state of
     * the action.
     */
    const std::optional<uint8_t> state;
    /**
     * Boolean indicating if the action is inside a Multi Action.
     */
    const bool isInMultiAction;

    DidReceiveSettingsEvent(std::string action, std::string context, std::string device, boost::json::object settings, uint8_t coordinatesColumn,
                            uint8_t coordinatesRow, std::optional<uint8_t> state, bool isInMultiAction);
    ~DidReceiveSettingsEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_DIDRECEIVESETTINGSEVENT_H
