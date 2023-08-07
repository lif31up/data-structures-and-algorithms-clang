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

function list_ins_next(list, curr, data){
  const new_node = new node(data, null); let return_value = null;
    if(list.size === 0){
	list.head = new_node;
	list.size = 1;
	return_value = 0;
    }//if
    else{
	new_node.next = curr.next; curr.next = new_node;
	list.size++;
	return_value = 0;
    }//else
    
    return return_value;
}/*ins_node_next(list, curr, data): insert a node next to curr*/
function list_rem_next(list, curr){
    if(curr === null || curr.next === null){ return null; }
	let return_value = null;
    
    let buff = curr.next.next;
    return_value = curr.next.data; list.destroy(curr.next.data);
    delete curr.next; curr.next = buff;
    
    return return_value;
}/*rem_node_next(list, curr): remove a node next to curr*/
function destroy_list(list){
    let cnt = 0;
    while(rem_node_next(my_list, my_list.head) != null){ cnt++; }
    delete list.head; cnt++; list.size = 0;
    console.log(cnt + " elements got deleted.");
}/* destroy_list(list): destroy whole elements inside of list*/
