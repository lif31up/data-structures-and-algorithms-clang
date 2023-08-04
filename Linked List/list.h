#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct ListElement {
  void *data;
  struct ListElement *next;
} elmt;
typedef struct LinkedList {
  int size;
  elmt *head, *tail;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
} list;

#define elmt_data(element) (element->data)
#define elmt_next(element) (element->next)

#define list_size(list) (list->size)
#define list_head(list) (list->head)
#define list_tail(list) (list->tail)
#define list_destroy(list) (list->destroy)

void init_list(list *list, void (*destroy)(void *data));
void list_destroy(list *list);
int list_ins_next(list *list, elmt *element, const void *data);
int list_rem_next(list *list, elmt *element, void **data);

#endif
