/*
#include "HashMapString.h"
#include "HashMap.c"
#include <stdio.h>

int compareString(char *str, char *strRef){
  return strcmp(str,strRef);
}

void hashMapAddString(HashTable *table, char* str,uint32_t key){
  _hashMapAdd(table, (void *)str,hashUsingModulo(key,table->size)/*,(Compare)compareString);
}
*/
