//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "SendToPropertyInspectorSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kSendToPropertyInspectorSentEvent[] = "sendToPropertyInspector";
constexpr char kSendToPropertyInspectorSentEventActionKey[] = "action";

SendToPropertyInspectorSentEvent::SendToPropertyInspectorSentEvent(std::string context, std::string action, boost::json::object payload)
    : SentEvent(kSendToPropertyInspectorSentEvent, std::move(context)), action(std::move(action)), payload(std::move(payload)) {
}

auto SendToPropertyInspectorSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();
    jsonEvent[kSendToPropertyInspectorSentEventActionKey] = this->action;
    jsonEvent[kSentEventPayloadKey] = this->payload;
    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
