//
// Created by Cyril Vlaminck on 24/12/2021.
//

#ifndef STREAMDECK_COMMAND_REGISTRATIONPARSER_H
#define STREAMDECK_COMMAND_REGISTRATIONPARSER_H

#include "Registration.h"

namespace openstreamdeck::internal {

class RegistrationParser {
   public:
    auto parse(int argc, const char** argv) -> std::shared_ptr<Registration> const;

   private:
    auto parsePort(int parameterIndex, int argc, const char** argv) -> uint16_t const;
    auto checkParameterPosition(int parameterIndex, int argc, const char** argv) -> void const;
};

}  // namespace streamdeck::internal

#endif  // STREAMDECK_COMMAND_REGISTRATIONPARSER_H
