class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def max_depth(root):
    if not root:
        return 0
    else:
        left = max_depth(root.left)
        right = max_depth(root.right)
    
    return max(left, right) + 1

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(5)
root.left.left = TreeNode(3) 
root.right.right = TreeNode(7)
root.left.right = TreeNode(4)
root.right.left = TreeNode(6)

print(max_depth(root))