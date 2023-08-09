class node{
  constructor(data, next=null){
    this.data = data; this.next = next;
  }//constructor
}/*node: node is element of list*/
class list{
  constructor(head = null, destroy){
    this.head = head; this.size = 0; this.destroy = destroy;
  }//constructor
}/*list: list is linked list having nodes*/

enum ERROR{SUCCESS=0, FAIL=1, FAIL_INIT=2}
function list_ins_next(list, curr, data){
  let return_value = ERROR.FAIL;

  const new_node = new node(data, null);

  if(list.size === 0){
    list.head = new_node;
    list.size = 1;
    return_value = ERROR.SUCCESS;
  }//if
  else{
    new_node.next = curr.next; curr.next = new_node;
    list.size++;
    return_value = ERROR.SUCCESS;
  }//else
  
  return return_value;
}/*ins_node_next(list, curr, data): insert a node next to curr*/
function list_rem_next(list, curr){
  if(curr === null || curr.next === null){ return ERROR.FAIL_INIT; }
  let return_value = ERROR.FAIL;
  
  let buff = curr.next.next;
  return_value = curr.next.data; list.destroy(curr.next.data);
  delete curr.next; curr.next = buff;
  
  return return_value;
}/*rem_node_next(list, curr): remove a node next to curr*/
function destroy_list(list){
  let cnt = 0;
  while(rem_node_next(list, list.head) !== ERROR.SUCCESS){ cnt++; }
  delete list.head; cnt++; list.size = 0;
  return ERROR.SUCCESS;
}/* destroy_list(list): destroy whole elements inside of list*/
