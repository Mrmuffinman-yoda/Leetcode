class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.value = val
        self.left = left
        self.right = right


class Tree:
    def __init__(self, rootVal):
        self.root = TreeNode(rootVal)
