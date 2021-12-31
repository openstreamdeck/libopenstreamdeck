//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_PROPERTYINSPECTORDIDDISAPPEAREVENT_H
#define STREAMDECK_COMMAND_PROPERTYINSPECTORDIDDISAPPEAREVENT_H

#include "Event.h"

namespace openstreamdeck {

constexpr char kPropertyInspectorDidDisappearEvent[] = "propertyInspectorDidDisappear";

/**
 * Event received when the Property Inspector disappears.
 */
class PropertyInspectorDidDisappearEvent : public Event {
   public:
    PropertyInspectorDidDisappearEvent(std::string action, std::string context, std::string device);
    ~PropertyInspectorDidDisappearEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_PROPERTYINSPECTORDIDDISAPPEAREVENT_H
