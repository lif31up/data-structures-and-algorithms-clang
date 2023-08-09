class node{
  constructor(data, left=null, right=null) {
    this.data = data; this.left = left; this.right = right;
  }//constructor
}//tree
class tree{
  constructor(root=null, compare, destroy) {
    this.size = 0; this.compare= compare; this.destroy = destroy; this.root = root;
  }//constructor
}//tree

enum ERROR{FAIL=1, SUCCESS=0, FAIL_INIT=2}
function destroy_tree(tree){
  if(tree == null || tree.destroy == null){ return ERROR.FAIL_INIT; }
  let return_value = ERROR.FAIL;
  bst_rem_left(tree, tree.root);
  tree.destroy(tree.root.data); delete tree.root;
  return return_value;
}//destroy_tree
function bst_ins_left(tree, node, content){
  let return_value = ERROR.FAIL;
  let position;
  if(node == null){
    if(tree.size > 0){ return ERROR.FAIL; }
    position = tree.root;
  }//if
  else{
    if(node.left != null){ return ERROR.FAIL; }
    position = tree.left;
  }//else
  position = new node(data); return_value = ERROR.SUCCESS;
  tree.size++;
  return return_value;
}//bst_ins_left
function bst_ins_right(tree, node, data){
  let return_value = ERROR.FAIL;
  let position;
  if(node === null){
    if(tree.size > 0){ return ERROR.FAIL; }
    position = tree.root();
  }//if
  else{
    if(node.right !== null){ return ERROR.FAIL; }
    position = node.left;
  }//else

  position = new node(data); return_value = ERROR.SUCCESS;
  tree.size++;
  return return_value;
}//bst_ins_right
function bst_rem_left(tree, node){
  if(tree.size === 0){ return ERROR.FAIL_INIT; }

  let position;
  if(node === null){ position = tree.root; }
  else{ position = node.left; }

  if(position != null){
    bst_rem_left(tree, position); bst_rem_right(tree, position);
    tree.destroy(position.data); delete position;
    tree.size--;
  }//if

  return ERROR.SUCCESS;
}// bst_rem_left
function bst_rem_right(tree, node){
  if(tree.size === 0){ return ERROR.FAIL; }

  let position;
  if(node === null){ position = tree.root; }
  else{ position = node.right; }

  if(position !== null){
    bst_rem_left(tree, position); bst_rem_right(tree, position);
    tree.destroy(position.data); delete position;
    tree.size--;
  }//if

  return ERROR.SUCCESS;
}//bst_rem_right(tree, node):