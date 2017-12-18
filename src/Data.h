#ifndef _DATA_H
#define _DATA_H
#include <stdint.h>

typedef struct Data Data;
struct Data{
  uint32_t key;
  int value;
  char *name;
};

Data *dataCreate(uint32_t key, void *name);
Data *intCreate(uint32_t key , void* value);

#endif // _DATA_H
