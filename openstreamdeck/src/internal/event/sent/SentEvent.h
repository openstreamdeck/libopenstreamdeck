//
// Created by Cyril Vlaminck on 25/12/2021.
//

#ifndef STREAMDECK_COMMAND_SENTEVENT_H
#define STREAMDECK_COMMAND_SENTEVENT_H

#include <boost/json.hpp>
#include <string>

namespace openstreamdeck::internal::event {

constexpr char kSentEventPayloadKey[] = "payload";

class SentEvent {
   public:
    /**
     * Type of the event sent to the Stream deck application through the websocket.
     *
     * Complete list of events is available here: https://developer.elgato.com/documentation/stream-deck/sdk/events-sent/
     */
    const std::string event;

    /**
     * An opaque value identifying the instance's action.
     */
    const std::string context;

    explicit SentEvent(std::string event);
    SentEvent(std::string event, std::string context);

    /**
     * Serialize the event into a JSON in order to be sent through the websocket.
     *
     * @return a Json serialization of the event.
     */
    virtual auto serializeToJson() -> boost::json::object;
};

}  // namespace streamdeck::internal::event

#endif  // STREAMDECK_COMMAND_SENTEVENT_H
