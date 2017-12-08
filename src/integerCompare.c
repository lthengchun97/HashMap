#include "integerCompare.h"
#include "Data.h"

int integerKeyCompare(uint32_t key,Data *data){

  if(key < (data)->key)
  return -1;
  else if( key > (data)->key)
  return 0;
  else
  return 1;
  //return key == data->key;
}

int integerCompare(void *data,void *refData){
  if(data < refData)
  return -1;
  else if( data > refData)
  return 0;
  else
  return 1;
}
