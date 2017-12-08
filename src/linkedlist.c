#include <stdio.h>
#include "linkedlist.h"
#include "Compare.h"
#include "integerCompare.h"


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
    list->tail->next=item;
    list->tail = item;
  }
  list->len += 1 ;
  item->next = NULL;
}

void createItem(Item *item,void * data,Item *next){
  item->data=data;
  item->next=next;
}

Item listSearch(LinkedList *list, void* data, Compare integerCompare){
    Item *before = NULL;
    Item *now = list->head;
    if(now == NULL)
      return NULL;
    else
      while(integerCompare(now->data,data)!= 1)
      {
        before = now;
        now = now->next;
        break;
      }
      return now;
}
