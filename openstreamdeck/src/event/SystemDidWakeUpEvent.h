//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_SYSTEMDIDWAKEUPEVENT_H
#define STREAMDECK_COMMAND_SYSTEMDIDWAKEUPEVENT_H

#include "Event.h"

namespace openstreamdeck {

constexpr char kSystemDidWakeUpEvent[] = "systemDidWakeUp";

/**
 * Event received when the computer is wake up.
 */
class SystemDidWakeUpEvent : public Event {
   public:
    SystemDidWakeUpEvent();
    ~SystemDidWakeUpEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_SYSTEMDIDWAKEUPEVENT_H
