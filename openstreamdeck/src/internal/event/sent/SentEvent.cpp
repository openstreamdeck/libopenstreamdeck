//
// Created by Cyril Vlaminck on 25/12/2021.
//

#include "SentEvent.h"

#include <utility>

namespace openstreamdeck::internal::event {

constexpr char kSentEventEventKey[] = "event";
constexpr char kSentEventContextKey[] = "context";

SentEvent::SentEvent(std::string event) : event(std::move(event)), context() {
}

SentEvent::SentEvent(std::string event, std::string context) : event(std::move(event)), context(std::move(context)) {
}

auto SentEvent::serializeToJson() -> boost::json::object {
    boost::json::object jsonEvent;
    jsonEvent[kSentEventEventKey] = this->event;
    if (!this->context.empty()) {
        jsonEvent[kSentEventContextKey] = this->context;
    }
    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
