from typing import List
from collections import deque

class TreeNode:
    def __init__(self, val: int = 0, left: TreeNode = None, right: TreeNode = None):
        self.val = val
        self.left = left
        self.right = right

def binary_tree_right_side_view(root: TreeNode) -> List[int]:
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        
        for i in range(level_size):
            current_node = queue.popleft()
            
            if i == level_size - 1:
                result.append(current_node.val)
            
            if current_node.left:
                queue.append(current_node.left)
            
            if current_node.right:
                queue.append(current_node.right)
    
    return result

def binary_tree_left_side_view(root: TreeNode) -> List[int]:
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        
        for i in range(level_size):
            current_node = queue.popleft()
            
            if i == 0:
                result.append(current_node.val)
            
            if current_node.left:
                queue.append(current_node.left)
            
            if current_node.right:
                queue.append(current_node.right)
    
    return result

def binary_tree_top_side_view(root: TreeNode) -> List[int]:
    if not root:
        return []
    
    result = []
    queue = deque([(root, 0)])
    lookup = {}
    
    while queue:
        current_node, level = queue.popleft()
        
        if level not in lookup:
            lookup[level] = current_node.val
        
        if current_node.left:
            queue.append((current_node.left, level - 1))
        
        if current_node.right:
            queue.append((current_node.right, level + 1))
    
    for level in sorted(lookup.keys()):
        result.append(lookup[level])
    
    return result

def binary_tree_bottom_side_view(root: TreeNode) -> List[int]:
    if not root:
        return []
    
    result = []
    queue = deque([(root, 0)])
    lookup = {}
    
    while queue:
        current_node, level = queue.popleft()
        
        lookup[level] = current_node.val
        
        if current_node.left:
            queue.append((current_node.left, level - 1))
        
        if current_node.right:
            queue.append((current_node.right, level + 1))
    
    for level in sorted(lookup.keys()):
        result.append(lookup[level])
    
    return result