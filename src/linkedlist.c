#include <stdio.h>
#include "linkedlist.h"


void listInit ( LinkedList *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void listAdd(LinkedList *list, Item*item)
{
  if(list->len == 0)
  {
  list->head =item;
  list->tail =item;
  }
  else
  {
    list->tail = item;
  }
  list->len += 1 ;
  item->next = NULL;
}