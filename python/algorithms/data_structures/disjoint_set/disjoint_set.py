def test_make_set():
    vertex = [Node(i) for i in range(6)]
    for v in vertex:
        make_set(v)
    assert vertex[0].rank == 0
    assert vertex[0].parent == vertex[0]
    assert vertex[1].rank == 0
    assert vertex[1].parent == vertex[1]
    assert vertex[2].rank == 0
    assert vertex[2].parent == vertex[2]
    assert vertex[3].rank == 0
    assert vertex[3].parent == vertex[3]
    assert vertex[4].rank == 0
    assert vertex[4].parent == vertex[4]
    assert vertex[5].rank == 0
    assert vertex[5].parent == vertex[5]


def test_union_set():
    vertex = [Node(i) for i in range(6)]
    for v in vertex:
        make_set(v)

    union_set(vertex[0], vertex[1])
    assert vertex[0].parent == vertex[0]
    assert vertex[1].parent == vertex[0]
    assert vertex[0].rank == 1
    assert vertex[1].rank == 0

    union_set(vertex[1], vertex[2])
    assert vertex[0].parent == vertex[0]
    assert vertex[1].parent == vertex[0]
    assert vertex[2].parent == vertex[0]
    assert vertex[0].rank == 2
    assert vertex[1].rank == 0
    assert vertex[2].rank == 0

    union_set(vertex[3], vertex[4])
    assert vertex[3].parent == vertex[3]
    assert vertex[4].parent == vertex[3]
    assert vertex[3].rank == 1
    assert vertex[4].rank == 0

    union_set(vertex[3], vertex[5])
    assert vertex[3].parent == vertex[3]
    assert vertex[4].parent == vertex[3]
    assert vertex[5].parent == vertex[3]
    assert vertex[3].rank == 2
    assert vertex[4].rank == 0
    assert vertex[5].rank == 0


def test_find_set():
    vertex = [Node(i) for i in range(6)]
    for v in vertex:
        make_set(v)

    union_set(vertex[0], vertex[1])
    union_set(vertex[1], vertex[2])
    union_set(vertex[3], vertex[4])
    union_set(vertex[3], vertex[5])

    assert find_set(vertex[0]) == vertex[0]
    assert find_set(vertex[1]) == vertex[0]
    assert find_set(vertex[2]) == vertex[0]
    assert find_set(vertex[3]) == vertex[3]
    assert find_set(vertex[4]) == vertex[3]
    assert find_set(vertex[5]) == vertex[3]


def test_find_python_set():
    vertex = [Node(i) for i in range(6)]
    for v in vertex:
        make_set(v)

    union_set(vertex[0], vertex[1])
    union_set(vertex[1], vertex[2])
    union_set(vertex[3], vertex[4])
    union_set(vertex[3], vertex[5])

    assert find_python_set(vertex[0]) == {0, 1, 2}
    assert find_python_set(vertex[1]) == {0, 1, 2}
    assert find_python_set(vertex[2]) == {0, 1, 2}
    assert find_python_set(vertex[3]) == {3, 4, 5}
    assert find_python_set(vertex[4]) == {3, 4, 5}
    assert find_python_set(vertex[5]) == {3, 4, 5}


def test_disjoint_set():
    vertex = [Node(i) for i in range(6)]
    for v in vertex:
        make_set(v)

    union_set(vertex[0], vertex[1])
    union_set(vertex[1], vertex[2])
    union_set(vertex[3], vertex[4])
    union_set(vertex[3], vertex[5])

    for node0 in vertex:
        for node1 in vertex:
            if find_python_set(node0).isdisjoint(find_python_set(node1)):
                assert find_set(node0) != find_set(node1)
            else:
                assert find_set(node0) == find_set(node1)


test_make_set()
test_union_set()
test_find_set()
test_find_python_set()
test_disjoint_set()