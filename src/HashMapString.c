#include "HashMapString.h"
#include "HashMap.c"
#include "Data.h"
#include "Compare.h"
#include "linkedlist.h"
#include "integerCompare.h"
#include <stdio.h>

int compareString(char *str, char *strRef){
  return strcmp(str,strRef);
}

int stringKeyCompare(uint32_t key,Data *data){
  return key == data->key;
}

void hashMapAddString(HashTable *table, char* data,uint32_t key){
  Data *intdata = dataCreate(key,data);
  _hashMapAdd(table, (Data *)intdata,key,hashUsingModulo(key,table->size),(Compare) compareString);
}

void hashMapSearchString(HashTable *table, char *data,uint32_t key){
  // Compute hash value
  // hashValue = hash ( ... );
  Data *intdata = dataCreate(key,data);
  _hashMapSearch(table,key,hashUsingModulo(intdata->value, table->size),(Compare) compareString);
  // _hashMapSearch(table,data,hashvalue,integerCompare);
}

void hashMapRemoveString(HashTable *table, char *data,uint32_t key){
  // Compute hash value
  // hashValue = hash ( ... );
  Data *intdata = intCreate(key,data);
  uint32_t index = hashUsingModulo(intdata->value, table->size);
  _hashMapRemove(table,key,index, (Compare) compareString);
  // _hashMapRemove(table,data,hashvalue,integerCompare);
}
