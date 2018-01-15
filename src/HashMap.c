#include "HashMap.h"
#include "Data.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "linkedlist.h"
#include "Data.h"
#include "Compare.h"
#include "integerCompare.h"

CEXCEPTION_T ex;

void hashMapInit(HashTable *table, int size){
  table->list = (LinkedList *)calloc(size *SIZE_FACTOR,sizeof(LinkedList));
  table->size = size;
  table->sizeFactor = SIZE_FACTOR;
  int i;
  for (i = 0; i < size; i++) {
  listInit (&table->list[i]);
  }
}

void _hashMapAdd(HashTable *table, void *data,uint32_t key,int index, Compare compareFunc){
  if(data ==NULL)
  {
    Throw(createException("Out of bound",DATA_ERROR));
  }
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,data,NULL);
  if( index < table->size){
    listReplace(&table->list[index],newItem,key,compareFunc);
  }
  else
    Throw(createException("Out of bound",BOUNDARY_ERROR));
  //&table->list[index].head->data->key == 1;
}

Item *_hashMapSearch(HashTable *table,uint32_t key, int index, Compare compareFunc){
  if( index > table->size){
    Throw(createException("Out of bound", BOUNDARY_ERROR));
  }
  return listSearch(&(table->list[index]),key,compareFunc);
}

void *_hashMapRemove(HashTable *table,uint32_t key, int index, Compare compareFunc){
  if( index > table->size){
    Throw(createException("Out of bound", BOUNDARY_ERROR));
  }
  return listRemove(&(table->list[index]),key,compareFunc);
}

uint32_t hashUsingModulo(uint32_t value,uint32_t range){
  return value % range;
}

// For current information , the hashValue is the location of the storing data.
// Means that the data (int) will write in to the hashValue.
void hashMapAddInteger(HashTable *table, void *data,uint32_t key){
  // Compute hash value
  // hashValue = hash ( ... );
  Try{
    Data *intdata = intCreate(key,data);
    uint32_t index = hashUsingModulo(intdata->value, table->size);
    _hashMapAdd(table,(Data *)intdata,key,index,(Compare) integerKeyCompare);
  }
  Catch(ex){
    Throw(ex);
  }
}

void *hashMapSearchInteger(HashTable *table, void *data,uint32_t key){
  // Compute hash value
  // hashValue = hash ( ... );
  Try{
  Data *intdata = intCreate(key,data);
  uint32_t index = hashUsingModulo(intdata->value, table->size);
  _hashMapSearch(table,key,index,(Compare) integerKeyCompare);
  }
  Catch(ex){
    Throw(ex);
  }
}

void hashMapRemoveInteger(HashTable *table, void *data,uint32_t key){
  // Compute hash value
  // hashValue = hash ( ... );
  Try{
  Data *intdata = intCreate(key,data);
  uint32_t index = hashUsingModulo(intdata->value, table->size);
  _hashMapRemove(table,key,index, (Compare) integerKeyCompare);
  }
  Catch(ex){
    Throw(ex);
  }
  // _hashMapRemove(table,data,hashvalue,integerCompare);
}
