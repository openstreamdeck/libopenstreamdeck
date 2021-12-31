//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_APPLICATIONDIDLAUNCHEVENT_H
#define STREAMDECK_COMMAND_APPLICATIONDIDLAUNCHEVENT_H

#include "Event.h"

namespace openstreamdeck {

constexpr char kApplicationDidLaunchEvent[] = "applicationDidLaunch";

/**
 * Event received when a monitored application is launched.
 */
class ApplicationDidLaunchEvent : public Event {
   public:
    const std::string application;

    explicit ApplicationDidLaunchEvent(std::string application);
    ~ApplicationDidLaunchEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_APPLICATIONDIDLAUNCHEVENT_H
