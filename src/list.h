#pragma once

typedef struct List List;

List* listCreate();
void listDestroy(List*);

void listAdd(List*, char*);
char* listGet(List*, int);
int listCount(List*);