//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "DidReceiveGlobalSettingsEvent.h"

namespace openstreamdeck {

DidReceiveGlobalSettingsEvent::DidReceiveGlobalSettingsEvent(boost::json::object settings)
    : Event(kDidReceiveGlobalSettingsEvent, "", "", ""), settings(std::move(settings)) {
}

DidReceiveGlobalSettingsEvent::~DidReceiveGlobalSettingsEvent() = default;

}  // namespace openstreamdeck
