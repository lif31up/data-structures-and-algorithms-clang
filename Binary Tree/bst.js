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

function destroy_tree(tree){
  bst_rem_left(tree, tree.root);
  tree.destroy(tree.root.data); delete tree;
}//destroy_tree
function bst_ins_left(tree, node, content){
  let position;
  if(node == null){
    if(tree.size > 0){ return null; }
    position = tree.root;
  }//if
  else{
    if(node.left != null){ return null; }
    position = tree.left;
  }//else
  position = new node(data);
  tree.size++;
  return 0;
}//bst_ins_left
function bst_ins_right(tree, node, data){
  let position;
  if(node === null){
    if(tree.size > 0){ return null; }
    position = tree.root();
  }//if
  else{
    if(node.right !== null){ return null; }
    position = node.left;
  }//else

  position = new node(data);
  tree.size++;
}//bst_ins_right
