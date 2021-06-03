class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def traverse(self, root: TreeNode, targetSum: int):
        if root is None:
            return 0
        l = self.traverse(root.left, targetSum)
        r = self.traverse(root.right, targetSum)
        return l + r + self.countSum(root, targetSum)

    def countSum(self, node: TreeNode, targetSum: int) -> int:
        if node is None:
            return 0
        now = 1 if node.val==targetSum else 0
        return now + self.countSum(node.left, targetSum - node.val) + self.countSum(node.right,
                targetSum-node.val)

    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        return self.traverse(root, targetSum)
