class TreeNode:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None

def same_tree(root1, root2):
    if not root1 and not root2:
        return True
    
    if not root1 or not root2:
        return False
    
    return root1.val == root2.val and (same_tree(root1.left, root2.left)) and (same_tree(root1.right, root2.right))

def is_subtree(root, subRoot):
    if not root:
        return False
    
    if not subRoot:
        return True
    
    if same_tree(root, subRoot):
        return True
    
    return is_subtree(root.left, subRoot) or is_subtree(root.right, subRoot)

def is_symmetric(root):
    if not root:
        return True
    
    def dfs(root1,root2):
        if not root1 and not root2:
            return True
        
        if not root1 or not root2:
            return False
        
        return root1.val == root2.val and dfs(root1.left, root2.right) and dfs(root1.right, root2.left)
    
    return dfs(root.left, root.right)


# tree 1
root1 = TreeNode(1)
# root1.left = TreeNode(2)
root1.right = TreeNode(2)

#tree 2
root2 = TreeNode(1)
# root2.left = TreeNode(2)
root2.right = TreeNode(3)

print(same_tree(root1, root2))

#for symmetric tree
root3 = TreeNode(1)
root3.left = TreeNode(2)
root3.right = TreeNode(2)
root3.left.left = TreeNode(3)
root3.right.right = TreeNode(3)

print(is_symmetric(root3))