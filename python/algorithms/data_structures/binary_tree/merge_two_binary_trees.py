def test_merge_two_binary_trees():
    tree1 = Node(5)
    tree1.left = Node(6)
    tree1.right = Node(7)
    tree1.left.left = Node(2)
    tree2 = Node(4)
    tree2.left = Node(5)
    tree2.right = Node(8)
    tree2.left.right = Node(1)
    tree2.right.right = Node(4)
    merged_tree = merge_two_binary_trees(tree1, tree2)
    assert merged_tree.value == 9
    assert merged_tree.left.value == 11
    assert merged_tree.left.left.value == 2
    assert merged_tree.left.left.right.value == 1
    assert merged_tree.right.value == 15
    assert merged_tree.right.right.value == 4

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    assert print_preorder(root) == [1, 2, 3]
    assert print_preorder(root.right) == [3]

    tree1 = Node(1)
    tree1.left = Node(2)
    tree1.right = Node(3)
    tree1.left.left = Node(4)

    tree2 = Node(2)
    tree2.left = Node(4)
    tree2.right = Node(6)
    tree2.left.right = Node(9)
    tree2.right.right = Node(5)

    merged_tree = merge_two_binary_trees(tree1, tree2)
    assert merged_tree.value == 3
    assert merged_tree.left.value == 6
    assert merged_tree.left.left.value == 4
    assert merged_tree.left.right.value == 9
    assert merged_tree.right.value == 9
    assert merged_tree.right.right.value == 5