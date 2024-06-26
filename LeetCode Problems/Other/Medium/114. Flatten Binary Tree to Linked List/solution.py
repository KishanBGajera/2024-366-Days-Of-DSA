from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self) -> None:
        self.prev = None

    def preorder(self, current) -> None:
        if not current:
            return
        
        if self.prev:
            self.prev.left = None
            self.prev.right = current

        right = current.right
        self.prev = current
        self.preorder(current.left)
        self.preorder(right)
        
    def flatten(self, root: Optional[TreeNode]) -> None:
        self.preorder(root)