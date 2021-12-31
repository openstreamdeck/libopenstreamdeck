//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_PROPERTYINSPECTORDIDAPPEAREVENT_H
#define STREAMDECK_COMMAND_PROPERTYINSPECTORDIDAPPEAREVENT_H

#include "Event.h"

namespace openstreamdeck {

constexpr char kPropertyInspectorDidAppearEvent[] = "propertyInspectorDidAppear";

/**
 * Event received when the Property Inspector appears.
 */
class PropertyInspectorDidAppearEvent : public Event {
   public:
    PropertyInspectorDidAppearEvent(std::string action, std::string context, std::string device);
    ~PropertyInspectorDidAppearEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_PROPERTYINSPECTORDIDAPPEAREVENT_H
