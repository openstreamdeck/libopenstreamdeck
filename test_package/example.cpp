#include <boost/json/src.hpp>

#include "StreamDeckPlugin.h"

using namespace openstreamdeck;

void onKeyDown(std::shared_ptr<StreamDeckPlugin> plugin, std::unique_ptr<KeyDownEvent> event) {
    plugin->getActions().showOk(event->context);
}

int main(int argc, const char* argv[]) {
    auto plugin = openstreamdeck::initializePlugin(argc, argv);
    plugin->getEvents().setKeyDownCallback(onKeyDown);
    plugin->run();
    return 0;
}
