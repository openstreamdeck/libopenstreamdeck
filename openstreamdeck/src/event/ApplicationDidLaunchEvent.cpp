//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "ApplicationDidLaunchEvent.h"

namespace openstreamdeck {

ApplicationDidLaunchEvent::ApplicationDidLaunchEvent(std::string application)
    : Event(kApplicationDidLaunchEvent, "", "", ""), application(std::move(application)) {
}

ApplicationDidLaunchEvent::~ApplicationDidLaunchEvent() = default;

}  // namespace openstreamdeck
