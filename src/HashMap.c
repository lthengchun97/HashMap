#include "HashMap.h"
#include "Data.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "linkedlist.h"

void hashMapInit(HashTable *table, int size){
  table->list = (LinkedList *)calloc(size *SIZE_FACTOR,sizeof(LinkedList));
  table->size = size;
  table->sizeFactor = SIZE_FACTOR;
  int i;
  for (i = 0; i < size; i++) {
  listInit (&table->list[i]);
  }
}

void _hashMapAdd(HashTable *table, void *data, int index){
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,data,NULL);
  listAdd(&table->list[index],newItem);
}

void *_hashMapSearch(HashTable *table,uint32_t key, int index, Compare compareFunc){
  
}

void *_hashMapRemove(HashTable *table,uint32_t key, int index, Compare compareFunc){


  //free memory
}

uint32_t hashUsingModulo(uint32_t value,uint32_t range){
  uint32_t result;
  result = value % range;
  return result;
}


// For current information , the hashValue is the location of the storing data.
// Means that the data (int) will write in to the hashValue.
void hashMapAddInteger(HashTable *table, int data){
  // Compute hash value
  // hashValue = hash ( ... );

  uint32_t hashValue = hashUsingModulo(data, table->size);
  printf("%d",hashValue);
  _hashMapAdd(table,(void *)data,hashValue);
}

void hashMapSearch(HashTable *table, int data){
  // Compute hash value
  // hashValue = hash ( ... );

  // _hashMapSearch(table,data,hashvalue,integerCompare);
}

void hashMapRemove(HashTable *table, int data){
  // Compute hash value
  // hashValue = hash ( ... );

  // _hashMapRemove(table,data,hashvalue,integerCompare);
}
