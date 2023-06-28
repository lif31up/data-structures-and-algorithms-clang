#include "list.h"

#include <stdio.h>
#include <string.h>

void list_init_list(List *list, void (*destroy)(void *data)) {
  list_size(list) = 0; list_destroy(list) = destroy;
  list_head(list) = NULL; list_tail(list) = NULL;

  return;
}  // init_list(): initiate a list. O(1)

void list_destroy_list(List *list) {
  void *data;

  while ( list_size(list) > 0 ) {
    if ( list_rem_next(list, NULL,(void**)&data) == 0 && list_destroy(list) != NULL ) { list_destroy(list)(data); }
  }  // while

  memset(list, 0, sizeof(List));

  return;
}  // destroy(): earse all the element in list. O(n)

int list_ins_next(List *list, Elmt *element, const void *data) {
  Elmt *new;

  if ( ( new = (Elmt *)malloc(sizeof(Elmt)) ) == NULL ) { printf("error: 02\n"); return -1; }
  elmt_data(new) = (void *)data;

  if ( element == NULL ) {
    if ( list_size(list) == 0 ) { list_tail(list) = new; }
  }  // if
  else {
    if ( elmt_next(element) == NULL ) { list_tail(list) = new; }
    elmt_next(new) = elmt_next(element); elmt_next(element) = new;
  }  // else

  list_size(list) += 1;

  return 0;
}  // ins_next(): insert an element the next. O(1)

int list_rem_next(List *list, Elmt *element, void **data) {
  if ( list_size(list) == 0 ) { printf("error: 03\n"); return -1; }

  Elmt *old;

  if ( element == NULL ) {
    *data = elmt_data( list_head(list) ); old = list_head(list); list_head(list) = elmt_next( list_head(list) );
    if ( list_size(list) == 1 ) { list_tail(list) = NULL; }
  }  // if
  else {
    if ( elmt_next(element) == NULL ) { printf("error: 03\n"); return -1; }

    *data = elmt_data( elmt_next(element) ); old = elmt_next(element); elmt_next(element) = elmt_next( elmt_next(element) );

    if ( elmt_next(element) == NULL ) { list_tail(list) = element; }
  }  // else

  free(old);
  list_size(list) -= 1;

  return 0;
}  // rem_next(): remove the element. O(1)
