#include <stdio.h>
#include <malloc.h>
#include "Data.h"

Data *dataCreate(uint32_t key , void* name){
  Data *data =(Data *)malloc(sizeof(Data));
  data->key = key;
  data->name = name;
  return data;
}


Data *intCreate(uint32_t key , void* value){
  Data *data =(Data *)malloc(sizeof(Data));
  data->key = key;
  data->value = value;
  return data;
}
