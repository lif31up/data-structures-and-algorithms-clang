class Element:
  data, next = dict(), None
  def __init__(self, data, next): self.data, self.next = data, next
# Element

class LinkedList:
  size = 0
  head, tail = None, None

  def match(self, key1, key2):
    return key1 == key2

  def list_ins_next(self, element, data):
    if not self.size or not self.head: return 0
    new_element = Element(data, element.next);
    element.next = new_element
    self.size += 1
    return 0
  # list_ins_next()

  def list_rem_next(self, element):
    if not self.size or not self.head: return 0
    buffer = element.next.next;
    del element.next;
    element.next = buffer
    self.size -= 1
    return 0
  # list_rem_next()
# LinkedList
