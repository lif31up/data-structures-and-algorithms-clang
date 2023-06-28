// anti-overlap
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

// Element
typedef struct ListElement {
  void *data;
  struct ListElement *next;
} Elmt;
// List
typedef struct LinkedList {
  int size;
  Elmt *head, *tail;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
} List;

// element macro
#define elmt_data(element) (element->data)
#define elmt_next(element) (element->next)

#define list_size(list) (list->size)
#define list_head(list) (list->head)
#define list_tail(list) (list->tail)
#define list_destroy(list) (list->destroy)

// functions
void list_init_list(List *list, void (*destroy)(void *data));
void list_destroy_list(List *list);
int list_ins_next(List *list, Elmt *element, const void *data);
int list_rem_next(List *list, Elmt *element, void **data);

#endif
