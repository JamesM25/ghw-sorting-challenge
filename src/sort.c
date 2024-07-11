#include <stdlib.h>
#include <string.h>

#include <assert.h>

#include "sort.h"
#include "csv.h"

static void getColumn(char *buffer, size_t bufferSize, const char *row, int column) {
    const char *ptr = row;
    for (int i = 0; i < column; i++) {
        ptr = strchr(ptr, COLUMN_DELIMITER) + 1;
        assert(ptr != NULL);
    }

    const char *end = strchr(ptr, COLUMN_DELIMITER);
    int columnLength = end == NULL ? strlen(ptr) : (int)(end - ptr);
    if (columnLength >= bufferSize) columnLength = bufferSize - 1;

    memcpy(buffer, ptr, columnLength);
    buffer[columnLength] = '\0';
}
static int compareRows(const char *a, const char *b, int column) {
    char strA[1000];
    char strB[1000];

    getColumn(strA, sizeof(strA), a, column);
    getColumn(strB, sizeof(strB), b, column);

    return strcmp(strA, strB);
}

static void sink(List *rows, int size, int index, int column) {
    int lastIndexWithChild = size / 2 - 1;

    while (index <= lastIndexWithChild) {
        int leftIndex  = index * 2 + 1;
        int rightIndex = index * 2 + 2;

        int smallestIndex = leftIndex;
        if (rightIndex < size && compareRows(listGet(rows, leftIndex), listGet(rows, rightIndex), column) < 0) {
            smallestIndex = rightIndex;
        }

        if (compareRows(listGet(rows, index), listGet(rows, smallestIndex), column) >= 0) {
            break;
        }

        listSwap(rows, index, smallestIndex);
        index = smallestIndex;
    }
}
static void buildHeap(List *rows, int column) {
    int size = listCount(rows);
    int lastIndexWithChild = size / 2 - 1;

    for (int i = lastIndexWithChild; i >= 0; i--) {
        sink(rows, size, i, column);
    }

    // Validate heap property
    for (int i = 1; i < size; i++) {
        int parentIndex = (i - 1) / 2;
        int cmp = compareRows(listGet(rows, i), listGet(rows, parentIndex), column);
        assert(cmp <= 0);
    }
}

void sortRows(List *rows, int column) {
    buildHeap(rows, column);

    for (int i = listCount(rows) - 1; i > 0; i--) {
        listSwap(rows, 0, i);
        sink(rows, i, 0, column);
    }

    // Validate that the list is sorted
    for (int i = 1; i < listCount(rows); i++) {
        int cmp = compareRows(listGet(rows, i-1), listGet(rows, i), column);
        assert(cmp <= 0);
    }
}