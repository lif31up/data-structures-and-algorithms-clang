#include <stdio.h>
#include <string.h>

#include "list.h"

void init_list(list *list, void (*destroy)(void *data)){
  list_size(list) = 0; list->destroy = destroy;
  list_head(list) = NULL; list_tail(list) == NULL;
}//init_list():

void destroy_list(list *list){
  if(list_size(list) == 0 || list == NULL) return;

  void *data;
  while(list_size(list) > 0){
    if(list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) list->destroy(data);
  }//while
  memset(list, 0, sizeof(struct LinkedList));
}//list():

int list_ins_next(list *list, elmt *element, const void *data){
  elmt *new_element;

  if((new_element = (elmt *)malloc(sizeof(elmt))) == NULL) return -1;
  new_element->data = (void *)data;
  if(element == NULL){
    if(list_size(list) == 0) list_tail(list) = list_head(list);
    elmt_next(new_element) = list_head(list); list_head(list) = new_element;
  } //if
  else{
    if(elmt_next(element) == NULL) list_tail(list) = new_element;
    elmt_next(element) = elmt_next(new_element);
  } //else
  list_size(list)++;

  return 0;
}//list_ins_next():

int list_rem_next(list *list, elmt *element, void **data){
  elmt *old_element; int return_value = 1;

  if(list_size(list) == 0) return return_value;
  if(element == NULL){
    *data = list_head(list); old_element = list_head(list);
    list_head(list) = list->head->next;
    if(list_size(list) == 1) list_tail(list) = list_head(list);
  }//if
  else{
    if(elmt_next(element) == NULL) return return_value;
    *data = element->next->data;
    old_element = elmt_next(element);
    elmt_next(element) = element->next->next;

    if(element->next == NULL) list_tail(list) = element;
    free(old_element); list_size(list)--;
    return_value = 1;

    return return_value;
  }//else
}//list_rem_next():
