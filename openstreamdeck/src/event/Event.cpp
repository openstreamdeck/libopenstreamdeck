//
// Created by Cyril Vlaminck on 25/12/2021.
//

#include "Event.h"

namespace openstreamdeck {

Event::Event(std::string &&event, std::string &&action, std::string &&context, std::string &&device)
    : event(event), action(action), context(context), device(device) {
}

Event::~Event() = default;

}  // namespace openstreamdeck
