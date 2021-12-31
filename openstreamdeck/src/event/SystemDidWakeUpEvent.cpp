//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "SystemDidWakeUpEvent.h"

namespace openstreamdeck {

SystemDidWakeUpEvent::SystemDidWakeUpEvent() : Event(kSystemDidWakeUpEvent, "", "", "") {
}

SystemDidWakeUpEvent::~SystemDidWakeUpEvent() = default;

}  // namespace openstreamdeck
