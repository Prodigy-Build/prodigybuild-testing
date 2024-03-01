from __future__ import annotations

from dataclasses import dataclass


@dataclass
class TreeNode:
    data: float
    left: TreeNode | None = None
    right: TreeNode | None = None


def is_binary_search_tree(root: TreeNode | None) -> bool:
    """
    >>> is_binary_search_tree(TreeNode(data=2,
    ...                                left=TreeNode(data=1),
    ...                                right=TreeNode(data=3))
    ...                                )
    True

    >>> is_binary_search_tree(TreeNode(data=0,
    ...                                left=TreeNode(data=-11),
    ...                                right=TreeNode(data=3))
    ...                                )
    True

    >>> is_binary_search_tree(TreeNode(data=5,
    ...                                left=TreeNode(data=1),
    ...                                right=TreeNode(data=4, left=TreeNode(data=3)))
    ...                      )
    False

    >>> is_binary_search_tree(TreeNode(data='a',
    ...                                left=TreeNode(data=1),
    ...                                right=TreeNode(data=4, left=TreeNode(data=3)))
    ...                      )
    Traceback (most recent call last):
     ...
    ValueError: Each node should be type of TreeNode and data should be float.

    >>> is_binary_search_tree(TreeNode(data=2,
    ...                                left=TreeNode([]),
    ...                                right=TreeNode(data=4, left=TreeNode(data=3)))
    ...                                )
    Traceback (most recent call last):
     ...
    ValueError: Each node should be type of TreeNode and data should be float.
    """

    # Validation
    def is_valid_tree(node: TreeNode | None) -> bool:
        """
        >>> is_valid_tree(None)
        True
        >>> is_valid_tree('abc')
        False
        >>> is_valid_tree(TreeNode(data='not a float'))
        False
        >>> is_valid_tree(TreeNode(data=1, left=TreeNode('123')))
        False
        """
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
        node: TreeNode | None, left_bound: float, right_bound: float
    ) -> bool:
        """
        >>> is_binary_search_tree_recursive_check(None)
        True
        >>> is_binary_search_tree_recursive_check(TreeNode(data=1), 10, 20)
        False
        """

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


if __name__ == "__main__":
    import doctest

    doctest.testmod()