#ifndef _HASHMAPSTRING_H
#define _HASHMAPSTRING_H

#include "HashMap.h"
#include "Data.h"
#include "Compare.h"
#include "linkedlist.h"
#include "integerCompare.h"

void hashMapSearchString(HashTable *table, char *data,uint32_t key);
void hashMapRemoveString(HashTable *table, char *data,uint32_t key);
void hashMapAddString(HashTable *table, char* data,uint32_t key);
int stringKeyCompare(uint32_t key,Data *data);
int compareString(char *str, char *strRef);

#endif // _HASHMAPSTRING_H
