//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "ApplicationDidTerminateEvent.h"

#include <utility>

namespace openstreamdeck {

ApplicationDidTerminateEvent::ApplicationDidTerminateEvent(std::string application)
    : Event(kApplicationDidTerminateEvent, "", "", ""), application(std::move(application)) {
}

ApplicationDidTerminateEvent::~ApplicationDidTerminateEvent() = default;

}  // namespace openstreamdeck
