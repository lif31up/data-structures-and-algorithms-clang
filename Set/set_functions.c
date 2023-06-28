#include <stdlib.h>
#include <string.h>

#include "set.h"

void set_init_set(Set *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data)) {
  list_init_list(set, destroy); list_match(set) = match; return;
}  // init_set(1):

int set_insert(Set *set, const void *data) {
  if ( set_is_member(set, data) ) { return 1; }
  return list_ins_next(set, list_tail(set), data);
}  // set_insert(1)

int set_remove(Set *set, void **data) {
  Elmt *member, *prev;
  prev = NULL;

  for ( member = list_head(set); member != NULL; member = elmt_next(member) ) {
    if ( list_match(set)(*data, elmt_data(member)) ) { break; }
    prev = member;
  }  // for

  return list_rem_next(set, prev, data);
}  // set_remove(n)

int set_union(Set *setu, const Set *set1, const Set *set2) {
  Elmt *member; void *data;

  set_init_set(setu, list_match(set1), NULL);
  for ( member = list_head(set1); member != NULL; member = elmt_next(member) ) {
    data = elmt_data(member);
    if ( list_ins_next(setu, list_tail(setu), data) != 0 ) {
      set_destroy_set(setu);
      return -1;
    }  // if
  }  // for

  for ( member = list_head(set2); member != NULL; member = elmt_next(member) ) {
    if ( set_is_member(set1, elmt_data(member)) ) { continue; }
    else { data = elmt_data(member);
      if ( list_ins_next(setu, list_tail(setu), data) != 0 ) {
	set_destroy_set(setu);
	return -1;
      }  // if
    }  // else
  }  // for

  return 0;
}  // set_union(n)

int set_intersection(Set *seti, const Set *set1, const Set *set2) {
  Elmt *member; void *data;

  set_init_set(seti, list_match(set1), NULL);
  for ( member = list_head(set1); member != NULL; member = elmt_next(member) ) {
    if ( set_is_member(set2, elmt_data(member)) ) {
      data = elmt_data(member);

      if ( list_ins_next(seti, list_tail(seti), data) != 0 ) {
	set_destroy_set(seti);
	return -1;
      }  // if
    }  // if
  }  // for

  return 0;
}  // set_intersection()

int set_difference(Set *setd, const Set *set1, const Set *set2) {
  Elmt *member; void *data;

  set_init_set(setd, list_match(set1), NULL);
  for ( member = list_head(set1); member != NULL; member = elmt_next(member) ){
    if ( !set_is_member(set2, elmt_data(member)) ) {
      data = elmt_data(member);
      if ( list_ins_next(setd, list_tail(setd), data) != 0 ) {
	set_destroy_set(setd);
	return -1;
      }  // if
    }  // if
  }  // for

  return 0;
}  // set_difference()

int set_is_member(const Set *set, const void *data) {
  Elmt *member;

  for ( member = list_head(set); member != NULL; member = elmt_next(member) ) {
    if ( list_match(set)(data, elmt_data(member)) ) { return 1; }
  }  // for

  return 0;
}  // set_is_member

int set_is_subset(const Set *set1, const Set *set2) {
  Elmt *member;

  if ( list_size(set1) > list_size(set2) ) { return 0; }

  return 1;
}  // set_is_subset()

int set_is_equal(const Set *set1, const Set *set2) {
  if ( list_size(set1) != list_size(set2) ) { return 0; }
  return set_is_subset(set1, set2);
}  // set_is_equal()
