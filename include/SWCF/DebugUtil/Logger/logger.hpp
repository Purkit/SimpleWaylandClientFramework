#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <mutex>
#include <stdio.h>
#include <stdarg.h>

#include<SWCF/defines.h>

namespace DebugUtil {
    
    enum class LogLevel {
        LOG_LEVEL_FATAL = 0,
        LOG_LEVEL_CRITICAL = 1,
        LOG_LEVEL_WARN = 2,
        LOG_LEVEL_DEBUG = 3,
        LOG_LEVEL_TRACE = 4,
        LOG_LEVEL_INFO = 5,
        LOG_LEVEL_VERBOSE = 6
    };

    class Logger {
        public:
            static void setPrirority(LogLevel log_level);
            static void log_to_console(LogLevel level, const char* fromFile, const char* fromFunction, int atLine, const char *msg, ...);
        
        private:
            static LogLevel current_log_level;
            static std::mutex logger_mutex;
    };

    
}

#define INFO(message, ...) DebugUtil::Logger::log_to_console(DebugUtil::LogLevel::LOG_LEVEL_INFO, __FILE__, __func__, __LINE__, message, ##__VA_ARGS__)
#define TRACE(message, ...) DebugUtil::Logger::log_to_console(DebugUtil::LogLevel::LOG_LEVEL_TRACE, __FILE__, __func__, __LINE__, message, ##__VA_ARGS__)
#define DEBUG(message, ...) DebugUtil::Logger::log_to_console(DebugUtil::LogLevel::LOG_LEVEL_DEBUG, __FILE__, __func__, __LINE__, message, ##__VA_ARGS__)
#define WARN(message, ...) DebugUtil::Logger::log_to_console(DebugUtil::LogLevel::LOG_LEVEL_WARN, __FILE__, __func__, __LINE__, message, ##__VA_ARGS__)
#define CRITICAL(message, ...) DebugUtil::Logger::log_to_console(DebugUtil::LogLevel::LOG_LEVEL_CRITICAL, __FILE__, __func__, __LINE__, message, ##__VA_ARGS__)
#define FATAL(message, ...) DebugUtil::Logger::log_to_console(DebugUtil::LogLevel::LOG_LEVEL_FATAL, __FILE__, __func__, __LINE__, message, ##__VA_ARGS__)
#define ERROR(message, ...) DebugUtil::Logger::log_to_console(DebugUtil::LogLevel::LOG_LEVEL_FATAL, __FILE__, __func__, __LINE__, message, ##__VA_ARGS__)
#define VERBOSE(message, ...) DebugUtil::Logger::log_to_console(DebugUtil::LogLevel::LOG_LEVEL_VERBOSE, __FILE__, __func__, __LINE__, message, ##__VA_ARGS__)



#endif // ! LOGGER_HPP