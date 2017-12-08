#ifndef _INTEGERCOMPARE_H
#define _INTEGERCOMPARE_H

#include "Compare.h"
#include "Data.h"
#include <stdio.h>

int integerKeyCompare(uint32_t key,Data *data);
int integerCompare(void *data,void *refData);
#endif // _INTEGERCOMPARE_H
