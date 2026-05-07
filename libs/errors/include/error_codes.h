#ifndef __ERROR_CODES_H__
#define __ERROR_CODES_H__

typedef enum {
    ERROR_NONE = 0,
    ERROR_OUT_OF_MEMORY,
    ERROR_FILE_NOT_FOUND,
    ERROR_INVALID_ARGUMENT,
    ERROR_OFFSET_OUT_OF_BOUNDS,
    ERROR_ARGUMENT_NULL,
    ERROR_UNKNOWN
} ErrorCode;

char * get_error_message(ErrorCode code);

#endif // __ERROR_CODES_H__