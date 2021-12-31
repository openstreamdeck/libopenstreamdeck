//
// Created by Cyril Vlaminck on 25/12/2021.
//

#include "KeyDownEvent.h"

namespace openstreamdeck {

KeyDownEvent::KeyDownEvent(std::string action, std::string context, std::string device, boost::json::object settings, uint8_t coordinatesColumn,
                           uint8_t coordinatesRow, std::optional<uint8_t> state, std::optional<uint8_t> userDesiredState, bool isInMultiAction)
    : Event(kKeyDownEvent, std::move(action), std::move(context), std::move(device)),
      settings(std::move(settings)),
      coordinatesColumn(coordinatesColumn),
      coordinatesRow(coordinatesRow),
      state(state),
      userDesiredState(userDesiredState),
      isInMultiAction(isInMultiAction) {
}

KeyDownEvent::~KeyDownEvent() = default;

}  // namespace openstreamdeck
