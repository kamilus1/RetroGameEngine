#include "error_codes.h"

char * get_error_message(ErrorCode code) {
    switch (code) {
        case ERROR_NONE:
            return "No error.";
        case ERROR_OUT_OF_MEMORY:
            return "Out of memory.";
        case ERROR_FILE_NOT_FOUND:
            return "File not found.";
        case ERROR_INVALID_ARGUMENT:
            return "Invalid argument.";
        case ERROR_UNKNOWN:
        default:
            return "Unknown error.";
    }
}