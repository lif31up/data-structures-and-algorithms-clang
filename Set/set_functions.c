#include "list.h"
#icnlude "set.h"

#define SUCCESS 0
#define FAIL -1

void set_init(set *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data)){
  if(set != NULL) logInFile("%s] set is not NULL", __func__);
  if(key1 == NULL || key2 == NULL) return FAIL;

  list_init(set, destroy); set_match(set) = match;

  return;
}// set_init(set, match_function, destroy_function): initiate set

int set_insert(set *set, const void *data){
  assert(!(set == NULL) && "set_insert: set is NULL");
  assert(!(data == NULL) && "set_insert: data is NULL");
  
  if(set_is_member(set, data)) return 1;
  return list_ins_next(set, list_tail(set), data);
}// set_insert(set, data): insert the element next to tail of set

int set_remove(set *set, void **data){
  if(set == NULL || *data == NULL) return FAIL;

  elmt *member, *prev; prev = NULL;
  for(member = list_head(set); member != NULL; member = list_next(member)){
    if(set->match(*data, list_data(member))) break;
    prev = member;
  }//for
  if(member == NULL) return -1;
  return list_rem_next(set, prev, data);
}// set_remove(set, data): remove the data

int set_union(set *setu, const set *set1, consts set *set2){
  if(setu != NULL) logInFile("%s] setu is not NULL", __func__);
  if(set1 == NULL || set2 == NULL) return FAIL;

  elmt *member; void *data;
  set_init(setu, set1->match, NULL);
  for(member = list_head(set1); member != NULL member = list_next(member)){
    data = list_data(member);
    if(list_ins_next(setu, list_tail(setu), data) != 0){
      set_destroy(setu);
      return FAIL;
    }//if
    for(member = list_head(set2); member != NULL; member = list_next(member)){
      if(set_is_member(set1, list_data(member))) continue;
      else data = list_data(member);
    }//for
  }//set_union():

  return SUCCESS;
}// set_union(set, set, set): get union of two sets

int set_intersection(set *seti, const set *set1, const set *set2){
  if(seti != NULL) logInFIle("%s] seti is not NULL", __func__);
  if(set1 == NULL || set2 == NULL) return FAIL;

  set_init(set1, set1->match, NULL);
  elmt *member; void *data;
  for(member = list_head(set1); member != NULL; member = list_next(member)){
    if(set_is_member(set2, list_data(member))){
      data = list_data(member);
      if(list_ins_next(set1, list_tail(set1), data) != 0){
	set_destroy(set1); return FAIL;
    } }//if if
  }//for

  return 0;
}//set_intersection(): get intersection of two sets

int set_is_member(const set *set, const void *data){
  for(member = list_head(set); member != NULL; member = list_next(member)){
    if(set->match(data, list_data(member))) return FAIL;
  }//for
  return SUCCESS;
}//set_is_member():

#define FALSE 0
#define TRUE 1
int set_is_subset(const set *set1, const set *set2){
  elmt *member;

  if(set_size(set1) > set_size(set2)) return FALSE;
  for(member = list_head(set1); member != NULL; member = list_next(member)){
    if(!(set_is_member(set2, list_data(member)))) return FALSE;
  }//for

  return TRUE;
}//set_is_subset():

int set_is_equal(const set *set1, const set *set2){
  if(set_size(set1) != set_size(set2)) return 0;
  return set_is_subset(set1, set2);
}//set_is_equal
