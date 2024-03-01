def test_preorder():
    tree = make_tree()
    assert preorder(tree) == [1, 2, 4, 5, 3]

def test_postorder():
    tree = make_tree()
    assert postorder(tree) == [4, 5, 2, 3, 1]

def test_inorder():
    tree = make_tree()
    assert inorder(tree) == [4, 2, 5, 1, 3]

def test_height():
    assert height(None) == 0
    tree = make_tree()
    assert height(tree) == 3

def test_level_order():
    tree = make_tree()
    assert level_order(tree) == [1, 2, 3, 4, 5]

def test_get_nodes_from_left_to_right():
    tree = make_tree()
    assert get_nodes_from_left_to_right(tree, 1) == [1]
    assert get_nodes_from_left_to_right(tree, 2) == [2, 3]
    assert get_nodes_from_left_to_right(tree, 3) == [4, 5]

def test_get_nodes_from_right_to_left():
    tree = make_tree()
    assert get_nodes_from_right_to_left(tree, 1) == [1]
    assert get_nodes_from_right_to_left(tree, 2) == [3, 2]
    assert get_nodes_from_right_to_left(tree, 3) == [5, 4]

def test_zigzag():
    tree = make_tree()
    assert zigzag(tree) == [[1], [3, 2], [4, 5]]

test_preorder()
test_postorder()
test_inorder()
test_height()
test_level_order()
test_get_nodes_from_left_to_right()
test_get_nodes_from_right_to_left()
test_zigzag()