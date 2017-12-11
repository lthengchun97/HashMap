#include "integerCompare.h"
#include "Data.h"

int integerKeyCompare(uint32_t key,Data *data){
  return key == data->key;
}

int integerCompare(void *data,void *refData){
  if(data < refData)
  return -1;
  else if( data > refData)
  return 0;
  else
  return 1;
}
