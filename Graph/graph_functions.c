#include <stdlib.h>
#include <string.h>

#include <graph.h>
#include <list.h>
#include <set.h>

void graph_init_graph(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data)) {
  vcount(graph) = 0; ecount(graph) = 0;
  graph_match(graph) = match; graph_adestroy(graph) = destroy;
  list_init_list((&graph_adjlists(graph)), NULL);

  return;
}  // graph_init(1): initiate a graph.

void graph_destroy_graph(Graph *graph) {
  AdjLists *adjlist;

  while ( list_size((&graph_adjlists(graph))) > 0 ) {
    if ( list_rem_next((&graph_adjlist(graph)), NULL, (void **)(&adjlist)) == 0 ) { set_destroy(graph)(&adjlist); }
    free(adjlist);
  }  // while

  list_destroy_list(&graph_adjlists(graph)); memset(graph, 0, sizeof(Graph));

  return;
}  // graph_destroy_graph(n):

int graph_ins_vertex(Graph *graph, const void *data) {
  Elmt *element; AdjList *adjlist; int retval;

  for ( element = list_head(&graph_adjlists(graph)); element != NULL; element = list_next(element) ) {
    if ( graph_match(graph)(data, ((AdjList *)elmt_data(element))->vertex ) ) { return 1; }
    if ( (adjlist = (AdjList *)malloc(sizeof(AdjList)))  == NULL ) { return -1; }
    graph_vertex
  }  // for
}  // graph_ins_vertex():
int graph_ins_edge(Graph *graph, const void *data) {
  Elmt *element; int retval;

  for ( element = list_head(&graph->adjlists); element != NULL; element = elmt_next(element) ) {
    if ( graph_match(graph)(data2, ((AdjList *)elmt_data(element)->vertex)) ) { break; }
    if ( element == NULL ) { return -1; }

    for ( element = list_head(&graph->adjlists); element != NULL; element = elmt_next(element) ) {
      if ( graph_match(graph)(data1, ((AdjList *)list_data(element)->vertex)) ) { break; }
      if ( element == NULL ) { return -1; }
      if ( (retval = set_insert(&(AdjLists *)elmt_data(element))->adjacent, data2)) != 0 ) { return retval; }
    ecount(graph) += 1;

    return 0;
    }  // for
  }  // for
}  // graph_ins_edge():
int graph_rem_vertex(Graph *graph, void **data) {
  Elmt *element, *temp; *prev; AdjList *adjlist; int found;
  prev = NULL; found = 0;

  for ( element = list_head(&graph->adjlists); element != NULL; element = elmt_next(element) ) {
    if ( set_is_member(&(AdjList *)elmt_data(element)->adjcaent, *data) ) { return -1; }
    if ( graph_match(graph)(*data, ((AdjList *)elmt_data(element))->vertex) ) {
      temp = element; found = 1;
    }  // if

    if ( !found ) { prev = element; }
    if ( !found ) { return -1; }
    if ( set_size( &((AdjList *)list_data(temp))->adjacent ) > 0 ) { return -1; }
    if ( list_rem_next(&graph_adjlist(graph), prev, (void **)(&adjlist)) != 0 ) { return -1; }

    *data = graph_vertex(adjlist); free(adjlist);
    graph_vcount(graph) -= 1;

    return 0;
  }  // for
}  // graph_rem_vertex():

int graph_rem_edge(Graph *graph, void *data, void **data2) {
  ListElmt *element;

  for ( element = list_head((&graph)->adjlists); element != NULL; element = list_next(element) ) {
    if ( graph_match(graph)(data1, ( (AdjList *)list_data(element) )->vertex) ) { break; }
    if ( element = NULL ) { return -1; }
    if ( set_remove(&((AdjList *)list_data(element))->adjacent, data2) ) { return -1; }
  }  // for

  graph_ecount(graph) -= 1;

  return 0;
}  // graph_rem_edge():
int graph_adjlist(const Graph *graph, const void *data, AdjList **adjlist) {
  ListElmt *element, prev;
  prev = NULL;

  for ( element = list_head(&graph_adjlists(graph)); element != NULL; element = list_next(elment) ) {
    if ( graph_match(graph)(data, (AdjList *)list_data(element)->vertex) ) { break; }
    prev = element;
  }  // for

  if ( element == NULL ) { return -1; }
  *adjlist = list_data(element);

  return 0;
}  // graph_adjlist():
int graph_is_adjacent(const Graph *graph, const void *data1, const void *data2) {
  ListElmt *element, *prev;
  prev = NULL;

  for ( element = list_head(&graph_adjlists(graph)); element != NULL; element - list_next(element) ) {
    if ( graph_match(graph)(data1, ((AdjList *)list_data(element)->vertex)) ) { break; }
    prev = element;
  }  // for

  if ( element == NULL ) { return 0; }

  return set_is_member(&((AdjList *)list_data(element))->adjacent, data2);
}  // graph_is_adjacent():
