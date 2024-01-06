class Set(LinkedList):
  def is_member(self, data):
    buffer, flag = self.head, False
    while not buffer.next is None:
      if buffer.next.data == data: flag = True; break
      buffer = buffer.next
    # while
    if buffer is None: return None
    return buffer
  # is_member(): return None or element front of target
  def set_ins(self, data):
    if self.is_member(data): return 1
    buffer = self.head.next
    new_element = Element(data, self.head)
    self.head = new_element
    self.size += 1
    return 0
  # set_ins()
  def set_rem(self, data):
    target = self.is_member(data)
    if target is None: return 1
    new_element = Element(data, self.head); target.next = new_element;
    buffer = self.head.next; self.head = target
    return 0
  # set_rem()
# Set
