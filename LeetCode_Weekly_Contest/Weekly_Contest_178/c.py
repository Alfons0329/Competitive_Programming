class Solution:
    def descend(self, head, root):
        if not head:
            return True
        if not root:
            return False
        if root.val == head.val:
            head = head.next
            return self.descend(head, root.left) or self.descend(head, root.right)
        
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if not root:
            return False
        return self.descend(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)