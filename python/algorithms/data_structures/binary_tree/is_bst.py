from typing import Union

class TreeNode:
    def __init__(self, data: Union[float, str]) -> None:
        self.data = data
        self.left = None
        self.right = None

def is_binary_search_tree(root: TreeNode) -> bool:
    def is_valid_tree(node: TreeNode) -> bool:
        if node is None:
            return True

        if not isinstance(node, TreeNode):
            return False

        try:
            float(node.data)
        except (TypeError, ValueError):
            return False

        return is_valid_tree(node.left) and is_valid_tree(node.right)

    if not is_valid_tree(root):
        raise ValueError(
            "Each node should be type of TreeNode and data should be float."
        )

    def is_binary_search_tree_recursive_check(
        node: TreeNode, left_bound: float, right_bound: float
    ) -> bool:
        if node is None:
            return True

        return (
            left_bound < node.data < right_bound
            and is_binary_search_tree_recursive_check(node.left, left_bound, node.data)
            and is_binary_search_tree_recursive_check(
                node.right, node.data, right_bound
            )
        )

    return is_binary_search_tree_recursive_check(root, -float("inf"), float("inf"))