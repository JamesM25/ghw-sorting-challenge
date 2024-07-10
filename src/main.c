#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "list.h"

#define CSV_PATH "../hackathons.csv"
#define COLUMN_DELIMITER ','

static void trimNewline(char *str) {
    int end = strlen(str) - 1;
    if (str[end] == '\n') {
        str[end] = '\0';
    }
}

static List *getColumnsList(const char *columns) {
    const char *ptr = columns;
    List *list = listCreate();

    while (1) {
        const char *end = strchr(ptr, COLUMN_DELIMITER);
        if (end == NULL) break;

        int columnLength = (int)(end - ptr);
        
        char *column = malloc(columnLength + 1);
        memcpy(column, ptr, columnLength);
        column[columnLength] = '\0';
        listAdd(list, column);

        ptr = end + 1;
    }

    int columnLength = strlen(ptr);
    char *column = malloc(columnLength + 1);
    memcpy(column, ptr, columnLength);
    column[columnLength] = '\0';
    trimNewline(column);
    listAdd(list, column);

    return list;
}

int main(int argc, char **argv) {
    
    FILE *fp = fopen(CSV_PATH, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", CSV_PATH);
        return 1;
    }
    
    char line[1000];

    // Read column names
    char *result = fgets(line, sizeof(line), fp);
    assert(result != NULL);
    List *columns = getColumnsList(line);

    // Read rows
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
    

    return 0;
}