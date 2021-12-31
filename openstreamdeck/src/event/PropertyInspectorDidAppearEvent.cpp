//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "PropertyInspectorDidAppearEvent.h"

namespace openstreamdeck {

PropertyInspectorDidAppearEvent::PropertyInspectorDidAppearEvent(std::string action, std::string context, std::string device)
    : Event(kPropertyInspectorDidAppearEvent, std::move(action), std::move(context), std::move(device)) {
}

PropertyInspectorDidAppearEvent::~PropertyInspectorDidAppearEvent() = default;

}  // namespace openstreamdeck
