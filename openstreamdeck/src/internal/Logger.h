//
// Created by Cyril Vlaminck on 25/12/2021.
//

#ifndef STREAMDECK_COMMAND_LOGGER_H
#define STREAMDECK_COMMAND_LOGGER_H

#include <fstream>
#include <boost/format.hpp>

namespace openstreamdeck::internal {

/**
 * Internal logger
 */
class Logger {
   private:
    std::unique_ptr<std::ostream> outputStream;

   public:
    Logger();

    auto isLogEnabled() -> bool;

    auto log(boost::basic_format<char> format) -> void;
    auto log(const std::exception& exception) -> void;
};

}  // namespace openstreamdeck::internal

#endif  // STREAMDECK_COMMAND_LOGGER_H
