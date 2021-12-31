//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "ShowOkSentEvent.h"

#include <utility>

namespace openstreamdeck::internal::event {

constexpr char kShowOkSentEvent[] = "showOk";

ShowOkSentEvent::ShowOkSentEvent(std::string context) : SentEvent(kShowOkSentEvent, std::move(context)) {
}

}  // namespace openstreamdeck::internal::event
