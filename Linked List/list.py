class Element:
  data, next = dict(), None
  def __init__(self, data, next): self.data, self.next = data, next
# Element

class LinkedList:
  size = 0
  head, tail = None, None
  def match(self, key1, key2): return key1 == key2 # 후에 다른 자료구조를 구현하기위해서 사용될 수 있습니다.
# LinkedList

def list_ins_next(list, element, data):
  if not list.size or not list.head: return 0  # 리스트의 크기가 0일 때, 거짓을 반환합니다.
  new_element = Element(data, element.next)
  element.next = new_element
  list.size += 1
  return 0
# list_ins_next()

def list_rem_next(list, element):
  if not list.size or not list.head: return 0
  buffer = element.next.next
  del element.next
  element.next = buffer
  list.size -= 1
  return 0
# list_rem_next()