//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "OpenUrlSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kOpenUrlSentEvent[] = "openUrl";
constexpr char kOpenUrlSentEventUrlKey[] = "url";

OpenUrlSentEvent::OpenUrlSentEvent(std::string url) : SentEvent(kOpenUrlSentEvent), url(std::move(url)) {
}

auto OpenUrlSentEvent::serializeToJson() -> boost::json::object {
    auto jsonEvent = SentEvent::serializeToJson();
    jsonEvent[kSentEventPayloadKey] = {{kOpenUrlSentEventUrlKey, this->url}};
    return jsonEvent;
}

}  // namespace openstreamdeck::internal::event
