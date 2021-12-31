//
// Created by Cyril Vlaminck on 26/12/2021.
//

#include "WillDisappearEvent.h"

namespace openstreamdeck {

WillDisappearEvent::WillDisappearEvent(std::string action, std::string context, std::string device, boost::json::object settings, uint8_t coordinatesColumn,
                                       uint8_t coordinatesRow, std::optional<uint8_t> state, bool isInMultiAction)
    : Event(kWillDisappearEvent, std::move(action), std::move(context), std::move(device)),
      settings(std::move(settings)),
      coordinatesColumn(coordinatesColumn),
      coordinatesRow(coordinatesRow),
      state(state),
      isInMultiAction(isInMultiAction) {
}

WillDisappearEvent::~WillDisappearEvent() = default;

}  // namespace openstreamdeck
