def test_valid_coloring():
    neighbours = [0,1,0,1,0]
    colored_vertices = [0, 2, 1, 2, 0]
    color = 1
    assert valid_coloring(neighbours, colored_vertices, color) == True
    color = 2
    assert valid_coloring(neighbours, colored_vertices, color) == False

def test_util_color():
    graph = [[0, 1, 0, 0, 0],
             [1, 0, 1, 0, 1],
             [0, 1, 0, 1, 0],
             [0, 1, 1, 0, 0],
             [0, 1, 0, 0, 0]]
    max_colors = 3
    colored_vertices = [0, 1, 0, 0, 0]
    index = 3
    assert util_color(graph, max_colors, colored_vertices, index) == True
    max_colors = 2
    assert util_color(graph, max_colors, colored_vertices, index) == False

def test_color():
    graph = [[0, 1, 0, 0, 0],
             [1, 0, 1, 0, 1],
             [0, 1, 0, 1, 0],
             [0, 1, 1, 0, 0],
             [0, 1, 0, 0, 0]]
    max_colors = 3
    assert color(graph, max_colors) == [0, 1, 0, 2, 0]
    max_colors = 2
    assert color(graph, max_colors) == []

test_valid_coloring()
test_util_color()
test_color()