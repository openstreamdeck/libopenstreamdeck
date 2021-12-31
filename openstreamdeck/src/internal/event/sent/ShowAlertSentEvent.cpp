//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "ShowAlertSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kShowAlertSentEvent[] = "showAlert";

ShowAlertSentEvent::ShowAlertSentEvent(std::string context) : SentEvent(kShowAlertSentEvent, std::move(context)) {
}

}  // namespace openstreamdeck::internal::event
