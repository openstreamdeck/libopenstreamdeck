//
// Created by Cyril Vlaminck on 24/12/2021.
//

#include "StreamDeckPlugin.h"

#include "internal/StreamDeckPluginImpl.h"

namespace openstreamdeck {

auto initializePlugin(int argc, const char* argv[]) -> std::shared_ptr<StreamDeckPlugin> {
    return std::make_shared<internal::StreamDeckPluginImpl>(argc, argv);
}

}  // namespace streamdeck
