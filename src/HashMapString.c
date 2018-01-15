#include "HashMapString.h"
#include <stdio.h>
#include "Exception.h"
#include "CException.h"
CEXCEPTION_T ex;

int compareString(char *str, char *strRef){
  return strcmp(str,strRef);
}

int stringKeyCompare(uint32_t key,Data *data){
  return key == data->key;
}

void hashMapAddString(HashTable *table, char* data,uint32_t key){
  Try{
  Data *intdata = dataCreate(key,data);
  _hashMapAdd(table, (Data *)intdata,key,hashUsingModulo(key,table->size),(Compare) compareString);
  }
  Catch(ex){
    Throw(ex);
  }
}

void* hashMapSearchString(HashTable *table, char *data,uint32_t key){
  // Compute hash value
  // hashValue = hash ( ... );
  Try{
  Data *intdata = dataCreate(key,data);
  _hashMapSearch(table,key,hashUsingModulo(intdata->value, table->size),(Compare) compareString);
  }
  Catch(ex){
    Throw(ex);
  }
  // _hashMapSearch(table,data,hashvalue,integerCompare);
}

void hashMapRemoveString(HashTable *table, char *data,uint32_t key){
  // Compute hash value
  // hashValue = hash ( ... );
  Try{
  Data *intdata = dataCreate(key,data);
  _hashMapRemove(table,key,hashUsingModulo(intdata->value, table->size), (Compare) compareString);
  }
  Catch(ex){
    Throw(ex);
  }
  // _hashMapRemove(table,data,hashvalue,integerCompare);
}
