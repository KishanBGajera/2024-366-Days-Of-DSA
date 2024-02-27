from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def _level_order(self, root, level):
        if root:
            if level in self.level_wise_elems:
                self.level_wise_elems[level].append(root.val)
            else:
                self.level_wise_elems[level] = [root.val]

            if root.left:
                self._level_order(root.left, level + 1)
                
            if root.right:
                self._level_order(root.right, level + 1)

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.level_wise_elems = {}
        self._level_order(root, 0)

        return list(self.level_wise_elems.values())
        