# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        root = self.dfs(root, target)
        return root
    
    def dfs(self, root: TreeNode, target: int):
        if root == None:
            return None 
        
        # connect, to check child existence
        root.left = self.dfs(root.left, target)
        root.right = self.dfs(root.right, target)

        # self destruction
        if root.val == target and root.left == None and root.right == None:
                return None
        return root