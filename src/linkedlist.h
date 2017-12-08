#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct LinkedList LinkedList;
typedef struct Item Item;

struct Item{
  Item *next;
  void *data;
};
struct LinkedList{
  Item *head;
  Item *tail;
  int len;
};
void listInit ( LinkedList *list);
void listAdd(LinkedList *list, Item*item);
void createItem(Item *item,void * data,Item *next);
Item listSearch(LinkedList *list, void* data, Compare integerKeyCompare);
#endif // _LINKEDLIST_H
