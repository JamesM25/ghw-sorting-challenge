#include "list.h"

#include <stdlib.h>
#include <assert.h>

#define INITIAL_CAPACITY 8

#define LIST_INDEX_VALID(LIST, INDEX) (INDEX >= 0 && INDEX < (LIST)->size)

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
    assert(list != NULL);

    list->size = 0;

    list->elements = malloc(sizeof(*list->elements) * INITIAL_CAPACITY);
    assert(list->elements != NULL);

    list->capacity = INITIAL_CAPACITY;

    return list;
}
void listDestroy(List *list) {
    for (int i = 0; i < list->size; i++) free(list->elements[i]);
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
    assert(LIST_INDEX_VALID(list, index));
    return list->elements[index];
}

int listCount(List *list) {
    return list->size;
}

void listSwap(List *list, int a, int b) {
    assert(LIST_INDEX_VALID(list, a));
    assert(LIST_INDEX_VALID(list, b));

    char *temp = list->elements[a];
    list->elements[a] = list->elements[b];
    list->elements[b] = temp;
}