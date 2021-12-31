//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_LOGMESSAGESENTEVENT_H
#define STREAMDECK_COMMAND_LOGMESSAGESENTEVENT_H

#include "SentEvent.h"

namespace openstreamdeck::internal::event {

/**
 * The plugin can use the logMessage event to write a debug message to the logs file.
 */
class LogMessageSentEvent : public SentEvent {
   private:
    const std::string message;

   public:
    LogMessageSentEvent(std::string message);
    auto serializeToJson() -> boost::json::object override;
};

}  // namespace openstreamdeck::internal::event

#endif  // STREAMDECK_COMMAND_LOGMESSAGESENTEVENT_H
