#include "logger.h"

ErrorCode logger_init(Logger * logger, LogLevel level) {
    if(logger == NULL) {
        return ERROR_ARGUMENT_NULL;
    }
    logger->level = level;
    return ERROR_NONE;
}

ErrorCode logger_log(Logger * logger, LogLevel level, const char * format, ...) {
    if(logger == NULL) {
        return ERROR_ARGUMENT_NULL;
    }
    if(format == NULL) {
        return ERROR_ARGUMENT_NULL;
    }
    if(level < logger->level) {
        return ERROR_NONE; // Don't log messages below the current log level
    }
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
    return ERROR_NONE;
}