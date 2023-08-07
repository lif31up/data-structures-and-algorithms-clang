import "./linked_list";

class set extends list{
  constructor(head = null, destroy, match) {
    super().size = 0; super().destroy = destroy; super().match = match;
  }//constructor
}//list

function set_is_member(set, data){
  let return_value = false;

  let curr = set.head; let cnt = 0;
  while(curr !== null){
    if(set.match(curr.data, data)){ return_value = true; break; }
    curr = curr.next; cnt++;
  }//while
  return return_value;
}//is_exist
function set_insert(set, curr, data){
  if(set_is_member(set, data)){ return null; }
  return ins_node_next(set, curr, data);
}/*ins_node_next(list, curr, data): insert a node next to curr*/
function set_remove(set, data){
  let member, prev; prev = null;
  for(member = set.head; member != null; member = member.next){
    if(set.match(member.data, data)) { break; }
    prev = member;
  }//for
  if(member === null){ return null; }
  return list_rem_next(set, prev);
}//set_remove
function set_union(setu, set1, set2){
  setu = new set(null, set1.destroy, set1.match);
  let member, data;
  for(member = set1.head; member != null; member = member.next){
    data = member.data;
    if(list_ins_next(setu, setu.head, data) == null){ destroy_list(setu); return null; }
    for(member = set2.head; member != null; member = member.next){
      if(set_is_member(set1, member.data)){ continue; }
      else{ data = member.data; }
    }//for
  }//for
  return 0;
}//set_union
function set_intersection(seti, set1, set2){
  seti = new set(null, set1.destory, set1.match);
  let member, data;
  for(member = set1.head; member != null; member = member.next){
    if(set_is_member(set2, member.data)){
      if(list_ins_next(seti, seti.head, data) == null){
        seti.destroy(seti); return null;
      }//if
    }//if
  }//for
  return 0;
}//set_intersection