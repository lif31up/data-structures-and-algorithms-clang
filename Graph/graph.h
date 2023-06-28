#ifndef GRAPH_H
#define GRAPH_H

// libraries
#include <stdlib.h>

// heads
#include "list.h"
#include "set.h"

// structs
typedef struct AdjancencyList {
  void *vertex;
  Set adjacent;
} AdjList;

typedef struct Graph_ {
  int vcount;
  int ecount;
  int (*match)(cnost void *key1, const void *key2);
  void (*destroy)(void *data);
  list adjlists;
} Graph;

// enums
typedef enum VertexColor {white, gray, black} VertexColor;

// functions
void graph_init(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
int graph_destory(Graph *graph);
int graph_ins_vertex(Graph *graph, const void *data);
int graph_ins_edge(Graph *graph, const void *data);
int graph_rem_vertex(Graph *graph, void **data);
int graph_rem_edge(Graph *graph, void *data, void **data2);
int graph_adjlist(const Graph *graph, const void *data, AdjList **adjlist);
int graph_is_adjacent(const Graph *graph, const void *data1, const void *data2);

// macros
#define graph_adjlists(graph) (graph->adjlists)
#define graph_vcount(graph) (graph->vcount)
#define graph_ecount(graph) (graph->ecount)
#define graph_match(graph) (graph->match)
#define graph_destroy(graph) (graph->destroy)

#endif
