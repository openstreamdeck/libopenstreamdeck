//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "SendToPluginEvent.h"

namespace openstreamdeck {

SendToPluginEvent::SendToPluginEvent(std::string action, std::string context, boost::json::object payload)
    : Event(kSendToPluginEvent, std::move(action), std::move(context), ""), payload(std::move(payload)) {
}

SendToPluginEvent::~SendToPluginEvent() = default;

}  // namespace openstreamdeck
