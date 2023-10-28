#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include "../Linked List/list.h"

typedef struct HashTable_{
    int bucket, size;
    int (*h)(const void *key);
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    list *table;
} htbl;
int htbl_init(htbl *htbl, int bucket, int (*h)(const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
int htbl_destroy(htbl *htbl);
int htbl_insert(htbl *htbl, const void *data);
int htbl_remove(htbl *htbl, void **data);
int htbl_lookup(const htbl *htbl, void **data);
#endif