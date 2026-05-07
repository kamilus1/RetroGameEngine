#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <stdio.h>
#include <stdarg.h>
#include "error_codes.h"

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
} LogLevel;

typedef struct {
    LogLevel level;
} Logger;

ErrorCode logger_init(Logger * logger, LogLevel level);
ErrorCode logger_log(Logger * logger, LogLevel level, const char * format, ...);


#endif // __LOGGER_H__