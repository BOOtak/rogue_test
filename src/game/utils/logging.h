//
// Created by k.leyfer on 06.07.2018.
//

#ifndef ROGUETEST_LOGGING_H
#define ROGUETEST_LOGGING_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/file_sinks.h>
#include "LogWrapper.h"

#define MAIN_LOG_FILENAME "log.log"

#define INIT_LOGGER(name) std::shared_ptr<spdlog::logger> logger = LogWrapper::GetLogger(name)

#define SET_LEVEL(level) logger->set_level(level)

#define LOG_DEBUG(...) { logger->debug(__VA_ARGS__); }
#define LOG_INFO(...) { logger->info(__VA_ARGS__); }
#define LOG_WARN(...) { logger->warn(__VA_ARGS__); }
#define LOG_ERROR(...) { logger->error(__VA_ARGS__); }

#endif //ROGUETEST_LOGGING_H
