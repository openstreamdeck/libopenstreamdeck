//
// Created by Cyril Vlaminck on 24/12/2021.
//

#include "RegistrationParser.h"

namespace openstreamdeck::internal {

constexpr const char *kRegistrationPort = "-port";
constexpr const char *kRegistrationPluginUUID = "-pluginUUID";
constexpr const char *kRegistrationRegisterEvent = "-registerEvent";
constexpr const char *kRegistrationInfo = "-info";

auto RegistrationParser::parse(int argc, const char **argv) -> std::shared_ptr<Registration> const {
    uint16_t port = 0;
    std::string pluginUUID;
    std::string registerEvent;

    int index = 1;
    while (index < argc) {
        std::string parameter(argv[index]);
        if (parameter == kRegistrationPort) {
            port = this->parsePort(++index, argc, argv);
        }
        if (parameter == kRegistrationPluginUUID) {
            this->checkParameterPosition(++index, argc, argv);
            pluginUUID = std::string(argv[index]);
        }
        if (parameter == kRegistrationRegisterEvent) {
            this->checkParameterPosition(++index, argc, argv);
            registerEvent = std::string(argv[index]);
        }
        index++;
    }

    if (port == 0) {
        throw std::invalid_argument("Missing port.");
    }
    if (pluginUUID.empty()) {
        throw std::invalid_argument("Missing plugin UUID.");
    }
    if (registerEvent.empty()) {
        throw std::invalid_argument("Missing register event.");
    }

    return std::make_shared<Registration>(port, pluginUUID, registerEvent);
}

auto RegistrationParser::parsePort(int parameterIndex, int argc, const char **argv) -> uint16_t const {
    this->checkParameterPosition(parameterIndex, argc, argv);
    std::string port(argv[parameterIndex]);
    try {
        return std::stoi(port);
    } catch (std::invalid_argument &e) {
        std::string parameter = std::string(argv[parameterIndex - 1]);
        throw std::invalid_argument("Value for parameter '" + parameter + "' must be numeric: " + port);
    }
}

auto RegistrationParser::checkParameterPosition(int parameterIndex, int argc, const char **argv) -> void const {
    if (parameterIndex >= argc) {
        std::string parameter = std::string(argv[parameterIndex - 1]);
        throw std::invalid_argument("Missing value for parameter '" + parameter + "'");
    }
}

}  // namespace streamdeck::internal
