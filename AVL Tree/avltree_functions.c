#include <stdlib.h>
#include <string.h>

#include "avltree.h"

void avl_rotate_left(AvlNode **node) {
  AvlNode *left, *grandchild;

  left = avlNode_left( (*node) );
  if ( ( (AvlNode *)avlNode_data(left) )->factor == LEFT ) {
    // LL Roatation
    avlNode_left( (*node) ) = avlNode_right(left);
    avlNode_right(left) = (*node);
    ( (AvlNode *)avlNode_data( (*node) ) )->factor = CENTER;
    ( (AvlNode *)avlNode_data(left) )->factor = CENTER;
    *node = left;
  }  // if
  else {
    // LR Rotation
    grandchild = avlNode_right(left);
    avlNode_right(left) = avlNode_left(grandchild);
    avlNode_left(grandchild) = left;
    avlNode_left( (*node) ) = avlNode_right(grandchild);
    avlNode_right(grandchild) = *node;

    switch ( ( (AvlNode *)avlNode_data(grandchild) )->factor ) {
    case LEFT:
      ( (AvlNode *)avlNode_data( (*node) ) )->factor = CENTER;
      ( (AvlNode *)avlNode_data(left) )->factor = CENTER;
      break;
    case CENTER:
      ( (AvlNode *)avlNode_data( (*node) ) )->factor = CENTER;
      ( (AvlNode *)avlNode_data(left) )->factor = LEFT;
      break;
    case RIGHT:
      ( (AvlNode *)avlNode_data( (*node) ) )->factor = CENTER;
      ( (AvlNode *)avlNode_data(left) )->factor = RIGHT;
      break;
    }  // switch

    ( (AvlNode *)avlNode_data(grandchild) )->factor = CENTER;
    (*node) = grandchild;
  }  // else

  return;
}  // rotate_left(): O(1)

void avl_rotate_right(AvlNode **node) {
  AvlNode *right, *grandchild;

  right = avlNode_right( (*node) );
  if ( ( (AvlNode *)avlNode_data(right) )->factor == RIGHT ) {
    avlNode_right( (*node) ) = avlNode_left(right);
    avlNode_left(right) = (*node);
    ( (AvlNode *)avlNode_data( (*node) ) )->factor = CENTER;
    ( (AvlNode *)avlNode_data(right) )->factor = CENTER;
    (*node) = right;
  }  // if
  else {
    grandchild = avlNode_left(right);
    avlNode_left(right) = avlNode_right(grandchild);
    avlNode_right(grandchild) = right;
    avlNode_right( (*node) ) = avlNode_left(grandchild);
    avlNode_left(grandchild) = *node;

    switch ( ( (AvlNode *)avlNode_data( (*node) ) )->factor ) {
    case LEFT:
      ( (AvlNode *)avlNode_data( (*node) ) )->factor = CENTER;
      ( (AvlNode *)avlNode_data(right) )->factor = RIGHT;
      break;
    case CENTER:
      ( (AvlNode *)avlNode_data( (*node) ) )->factor = CENTER;
      ( (AvlNode *)avlNode_data(right) )->factor = CENTER;
      break;
    case RIGHT:
      ( (AvlNode *)avlNode_data( (*node) ) )->factor = LEFT;
      ( (AvlNode *)avlNode_data(right) )->factor = CENTER;
      break;
    }  // switch

    ( (AvlNode *)avlNode_data(grandchild) )->factor = CENTER;
    (*node) = grandchild;
  }  // else

  return;
}  // roatate_right(): O(1)
