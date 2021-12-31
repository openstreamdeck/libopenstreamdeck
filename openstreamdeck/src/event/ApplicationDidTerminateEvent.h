//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_APPLICATIONDIDTERMINATEEVENT_H
#define STREAMDECK_COMMAND_APPLICATIONDIDTERMINATEEVENT_H

#include "Event.h"

namespace openstreamdeck {

constexpr char kApplicationDidTerminateEvent[] = "applicationDidTerminate";

/**
 * Event received when a monitored application is terminated.
 */
class ApplicationDidTerminateEvent : public Event {
   public:
    const std::string application;

    ApplicationDidTerminateEvent(std::string application);
    ~ApplicationDidTerminateEvent() override;
};

}

#endif  // STREAMDECK_COMMAND_APPLICATIONDIDTERMINATEEVENT_H
