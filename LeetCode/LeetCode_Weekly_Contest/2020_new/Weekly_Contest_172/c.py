class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if root == None:
            return None 
        
        # connect, to check child existence
        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)

        if root.val == target and root.left == None and root.right == None:
                return None
        return root