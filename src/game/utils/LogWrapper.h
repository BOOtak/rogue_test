//
// Created by k.leyfer on 06.07.2018.
//

#ifndef ROGUETEST_LOGWRAPPER_H
#define ROGUETEST_LOGWRAPPER_H

#include <spdlog/sinks/file_sinks.h>
#include <spdlog/logger.h>

class LogWrapper {
    static std::shared_ptr<spdlog::sinks::simple_file_sink_st> sink;

public:
    static std::shared_ptr<spdlog::logger> GetLogger(const char *name);
};


#endif //ROGUETEST_LOGWRAPPER_H
