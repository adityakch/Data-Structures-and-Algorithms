class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def in_order(root):
    if not root:
        return []
    
    return in_order(root.left) + [root.val] + in_order(root.right)

def pre_order(root):
    if not root:
        return []
    
    return [root.val] + pre_order(root.left) + pre_order(root.right)

def post_order(root):
    if not root:
        return []
    
    return post_order(root.left) + post_order(root.right) + [root.val]

def level_order(root):
    if not root:
        return None
    
    res = []
    queue = [root]

    while queue:
        curr_lvl = []
        lvl_len = len(queue)

        for _ in range(lvl_len):
            node = queue.pop(0)
            curr_lvl.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        res.append(curr_lvl) 
    
    return res

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(5)
root.left.left = TreeNode(3) 
root.right.right = TreeNode(7)
root.left.right = TreeNode(4)
root.right.left = TreeNode(6)

print(in_order(root))
print(pre_order(root))
print(post_order(root))
print(level_order(root))