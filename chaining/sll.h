#ifndef SLL_H
#define SLL_H

#define length 22000
#define words 1000

#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Sll {

    struct Node* head;
    struct Node* tail;
    int size;
};

struct Node {

    char* word;
    struct Node* next;

    char palavra[words];
};

void Prepend(struct Sll* list, char* word);

void Append(struct Sll* list, char* word);

void DestroyList(struct Sll* list);

void PrintList(struct Sll* list, int index);

void Delete(struct Sll* list, struct Node* node);

void WrongWords(struct Sll* list, char* word);

struct Sll* CreateNode(void);

#endif // SLL_H
