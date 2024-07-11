#include <string.h>
#include <stdbool.h>

#include "csv.h"

const char* columnEnd(const char *column, char delimiter) {
    const char *ptr = column;
    bool inQuote = false;

    while (*ptr) {
        if (*ptr == '"') inQuote = !inQuote;
        else if (*ptr == delimiter && !inQuote) return ptr;

        ptr++;
    }

    return NULL;
}