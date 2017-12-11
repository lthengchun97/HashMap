#ifndef _DATA_H
#define _DATA_H
#include <stdint.h>

typedef struct Data Data;
struct Data{
  uint32_t key;
  char *name;
  int value;
};

Data *dataCreate(uint32_t key, char *name);
Data *intCreate(uint32_t key , int value);

#endif // _DATA_H
