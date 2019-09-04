#ifndef HASH_H
#define HASH_H

#include "sll.h"

typedef struct Sll* HashTable[length];

void InitHashTable(HashTable h);

unsigned int Hash(char* word);

void ChainedInsert(HashTable h, char* word);

int ChainedSearch(HashTable h, char* word);

void LoadDictionary(HashTable h);

void Searching(HashTable h, char* file);

void PrintHashTable(HashTable h);

void DestroyHashTable(HashTable h);

void EndProgram(HashTable h, char* word);

#endif // HASH_H
