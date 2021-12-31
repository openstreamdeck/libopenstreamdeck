//
// Created by Cyril Vlaminck on 27/12/2021.
//

#include "LogMessageSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kLogMessageSentEvent[] = "logMessage";
constexpr char kLogMessageSentEventMessageKey[] = "message";

LogMessageSentEvent::LogMessageSentEvent(std::string message) : SentEvent(kLogMessageSentEvent), message(std::move(message)) {
}

auto LogMessageSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();
    jsonEvent[kLogMessageSentEventMessageKey] = this->message;
    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
