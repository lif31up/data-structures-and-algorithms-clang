cmake_minimum_required(VERSION 3.26)
project(data_structures_and_algorithms_clang C)

set(CMAKE_C_STANDARD 11)

include_directories("AVL Tree")
include_directories("Binary Tree")
include_directories(Graph)
include_directories(Hash)
include_directories("Linked List")
include_directories(Set)

add_executable(data_structures_and_algorithms_clang
        "AVL Tree/avltree.h"
        "AVL Tree/avltree_functions.c"
        "Binary Tree/bst.h"
        "Binary Tree/bst_functions.c"
        "Binary Tree/bst_traverse.c"
        "Binary Tree/bst_traverse.h"
        Graph/graph.h
        Graph/graph_functions.c
        Hash/hashtable.h
        "Linked List/list.h"
        "Linked List/list_functions.c"
        Set/set.h
        Set/set_functions.c)
