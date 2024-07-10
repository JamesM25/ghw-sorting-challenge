#include "list.h"

#include <stdlib.h>
#include <assert.h>

#define INITIAL_CAPACITY 8

struct List {
    int capacity;
    int size;
    char **elements;
};

static void listGrow(List *list, int newCapacity) {
    if (list->capacity >= newCapacity) return;

    char **newElements = realloc(list->elements, sizeof(*list->elements) * newCapacity);
    assert(newElements != NULL);

    list->elements = newElements;
    list->capacity = newCapacity;
}

List *listCreate() {
    List *list = malloc(sizeof(List));

    list->size = 0;

    list->elements = malloc(sizeof(*list->elements) * INITIAL_CAPACITY);
    assert(list->elements != NULL);

    list->capacity = INITIAL_CAPACITY;
}
void listDestroy(List *list) {
    free(list->elements);
    free(list);
}

void listAdd(List *list, char *value) {
    if (list->size >= list->capacity) {
        listGrow(list, list->capacity * 2);
    }

    list->elements[list->size++] = value;
}

char *listGet(List *list, int index) {
    assert(index >= 0);
    assert(index < list->size);
    return list->elements[index];
}

int listCount(List *list) {
    return list->size;
}