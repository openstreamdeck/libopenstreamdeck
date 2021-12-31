//
// Created by Cyril Vlaminck on 25/12/2021.
//

#include "Logger.h"

namespace openstreamdeck::internal {

Logger::Logger() {
    this->outputStream = std::make_unique<std::ofstream>("log_file.txt", std::ios_base::out | std::ios_base::app);
}

auto Logger::isLogEnabled() -> bool {
    return true; // FIXME
}

auto Logger::log(boost::basic_format<char> format) -> void {
    *this->outputStream << format.str() << "\n";
    this->outputStream->flush();
}

auto Logger::log(const std::exception &exception) -> void {
    *this->outputStream << exception.what() << "\n";
    this->outputStream->flush();
}

}
