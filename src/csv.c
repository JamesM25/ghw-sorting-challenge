#include <string.h>
#include <stdbool.h>
#include <assert.h>

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

int countColumns(const char *row, char delimiter) {
    const char *ptr = row;

    int count = 0;
    while (ptr != NULL) {
        ptr = columnEnd(ptr, delimiter);
        if (ptr != NULL) ptr += 1;

        count++;
    }

    return count;
}