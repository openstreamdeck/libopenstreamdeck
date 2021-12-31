//
// Created by Cyril Vlaminck on 24/12/2021.
//

#ifndef STREAMDECK_COMMAND_STREAMDECKPLUGIN_H
#define STREAMDECK_COMMAND_STREAMDECKPLUGIN_H

#include <functional>
#include <utility>

#include "Actions.h"
#include "Events.h"
#include "StreamDeckPluginStatus.h"
#include "event/Event.h"
#include "internal/Registration.h"

namespace openstreamdeck {

class StreamDeckPlugin {
   public:
    using StatusChangedCallback = std::function<void(StreamDeckPlugin&, StreamDeckPluginStatus)>;

    virtual ~StreamDeckPlugin() = default;

    virtual auto setStatusChangedCallback(StatusChangedCallback statusChangedCallback) -> void = 0;

    virtual auto getActions() -> Actions& = 0;

    /**
     * Return an object allowing to subscribe all events send by the Stream deck application to the plugin.
     */
    virtual auto getEvents() -> Events& = 0;

    virtual auto run() -> void = 0;
};

auto initializePlugin(int argc, const char* argv[]) -> std::shared_ptr<StreamDeckPlugin>;

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_STREAMDECKPLUGIN_H
