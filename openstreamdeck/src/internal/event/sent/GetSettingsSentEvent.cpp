//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "GetSettingsSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kGetSettingsSentEvent[] = "getSettings";

GetSettingsSentEvent::GetSettingsSentEvent(std::string context) : SentEvent(kGetSettingsSentEvent, std::move(context)) {
}

}  // namespace openstreamdeck::internal::event
