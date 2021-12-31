//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "DidReceiveSettingsEvent.h"

namespace openstreamdeck {

DidReceiveSettingsEvent::DidReceiveSettingsEvent(std::string action, std::string context, std::string device, boost::json::object settings,
                                                 uint8_t coordinatesColumn, uint8_t coordinatesRow, std::optional<uint8_t> state, bool isInMultiAction)
    : Event(kDidReceiveSettingsEvent, std::move(action), std::move(context), std::move(device)),
      settings(std::move(settings)),
      coordinatesColumn(coordinatesColumn),
      coordinatesRow(coordinatesRow),
      state(state),
      isInMultiAction(isInMultiAction) {
}

DidReceiveSettingsEvent::~DidReceiveSettingsEvent() = default;

}  // namespace openstreamdeck
