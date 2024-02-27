from __future__ import annotations

from dataclasses import dataclass


@dataclass
class TreeNode:
    data: float
    left: TreeNode | None = None
    right: TreeNode | None = None


def is_binary_search_tree(root: TreeNode | None) -> bool:
    def is_valid_tree(node: TreeNode | None, left_bound: float, right_bound: float) -> bool:
        if node is None:
            return True

        if not isinstance(node, TreeNode):
            return False

        if not isinstance(node.data, float):
            return False

        if not (left_bound < node.data < right_bound):
            return False

        return (
            is_valid_tree(node.left, left_bound, node.data)
            and is_valid_tree(node.right, node.data, right_bound)
        )

    return is_valid_tree(root, -float("inf"), float("inf"))