//
// Created by Cyril Vlaminck on 29/12/2021.
//

#include "GetGlobalSettingsSentEvent.h"

namespace openstreamdeck::internal::event {

constexpr char kGetGlobalSettingsSentEvent[] = "getGlobalSettings";

GetGlobalSettingsSentEvent::GetGlobalSettingsSentEvent(std::string context) : SentEvent(kGetGlobalSettingsSentEvent, std::move(context)) {
}

}  // namespace openstreamdeck::internal::event
