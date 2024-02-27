def binary_tree_mirror(binary_tree: dict, root: int = 1) -> dict:
    if not binary_tree:
        raise ValueError("binary tree cannot be empty")
    if root not in binary_tree:
        msg = f"root {root} is not present in the binary_tree"
        raise ValueError(msg)
    
    def mirror_helper(node):
        if not node:
            return
        left_child, right_child = binary_tree[node][:2]
        binary_tree[node] = [right_child, left_child]
        mirror_helper(left_child)
        mirror_helper(right_child)
    
    binary_tree_mirror_dictionary = dict(binary_tree)
    mirror_helper(root)
    return binary_tree_mirror_dictionary