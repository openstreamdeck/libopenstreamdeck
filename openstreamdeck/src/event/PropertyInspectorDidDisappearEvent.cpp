//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "PropertyInspectorDidDisappearEvent.h"

namespace openstreamdeck {

PropertyInspectorDidDisappearEvent::PropertyInspectorDidDisappearEvent(std::string action, std::string context, std::string device)
    : Event(kPropertyInspectorDidDisappearEvent, std::move(action), std::move(context), std::move(device)) {
}

PropertyInspectorDidDisappearEvent::~PropertyInspectorDidDisappearEvent() = default;

}  // namespace openstreamdeck
