#ifndef _HASHMAP_H
#define _HASHMAP_H
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "linkedlist.h"       // LinkedList file

#define SIZE_FACTOR 3

typedef int (*Compare)(void *data, void *refData);

typedef struct HashTable HashTable;

struct HashTable {
  LinkedList *list;
  int size;
  int sizeFactor;
};

void hashMapInit(HashTable *table, int size);
void _hashMapAdd(HashTable *table, void *data,int index);
Item *_hashMapSearch(HashTable *table,uint32_t key, int index, Compare compareFunc);
void *_hashMapRemove(HashTable *table,uint32_t key, int index, Compare compareFunc);
uint32_t hashUsingModulo(uint32_t value,uint32_t range);
uint32_t hashFunction(void *data, uint32_t key);
void hashMapAddInteger(HashTable *table, void *data,uint32_t key);

#endif // _HASHMAP_H
