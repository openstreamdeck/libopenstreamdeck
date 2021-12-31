//
// Created by Cyril Vlaminck on 25/12/2021.
//

#ifndef STREAMDECK_COMMAND_KEYDOWNEVENT_H
#define STREAMDECK_COMMAND_KEYDOWNEVENT_H

#include <boost/json.hpp>

#include "Event.h"

namespace openstreamdeck {

constexpr char kKeyDownEvent[] = "keyDown";

/**
 * Event received by the plugin when the user presses a key.
 *
 * https://developer.elgato.com/documentation/stream-deck/sdk/events-received/#keydown
 */
class KeyDownEvent : public Event {
   public:
    /**
     * This json object contains data that you can set and are stored persistently.
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
     * This is a parameter that is only set when the action is triggered with a specific value from a Multi Action. For example if the user sets the Game
     * Capture Record action to be disabled in a Multi Action, you would see the value 1. Only the value 0 and 1 are valid.
     */
    const std::optional<uint8_t> userDesiredState;
    /**
     * Boolean indicating if the action is inside a Multi Action.
     */
    const bool isInMultiAction;

    KeyDownEvent(std::string action, std::string context, std::string device, boost::json::object settings, uint8_t coordinatesColumn, uint8_t coordinatesRow,
                 std::optional<uint8_t> state, std::optional<uint8_t> userDesiredState, bool isInMultiAction);
    ~KeyDownEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_KEYDOWNEVENT_H
