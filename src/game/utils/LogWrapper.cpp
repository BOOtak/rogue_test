//
// Created by k.leyfer on 06.07.2018.
//

#include "LogWrapper.h"
#include "logging.h"

std::shared_ptr<spdlog::sinks::simple_file_sink_st> LogWrapper::sink =
        std::make_shared<spdlog::sinks::simple_file_sink_st>(MAIN_LOG_FILENAME);

std::shared_ptr<spdlog::logger> LogWrapper::GetLogger(const char *name) {
    return std::make_shared<spdlog::logger>(name, sink);
}
