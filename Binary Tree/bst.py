class BSTNode:
  left, right = None, None
  data = None
  def __init__(self, data): self.data = data
# BSTNode

class BSTTree:
  size, root = 0, None
  def bst_ins_left(self, parent: BSTNode, child: BSTNode):
    if parent is None or child is None: return 1
# BSTTree