from typing import List

def test_next_greatest_element_slow():
    arr = [-10, -5, 0, 5, 5.1, 11, 13, 21, 3, 4, -21, -10, -5, -1, 0]
    expect = [-5, 0, 5, 5.1, 11, 13, 21, -1, 4, -1, -10, -5, -1, 0, -1]
    assert next_greatest_element_slow(arr) == expect

def test_next_greatest_element_fast():
    arr = [-10, -5, 0, 5, 5.1, 11, 13, 21, 3, 4, -21, -10, -5, -1, 0]
    expect = [-5, 0, 5, 5.1, 11, 13, 21, -1, 4, -1, -10, -5, -1, 0, -1]
    assert next_greatest_element_fast(arr) == expect

def test_next_greatest_element():
    arr = [-10, -5, 0, 5, 5.1, 11, 13, 21, 3, 4, -21, -10, -5, -1, 0]
    expect = [-5, 0, 5, 5.1, 11, 13, 21, -1, 4, -1, -10, -5, -1, 0, -1]
    assert next_greatest_element(arr) == expect

test_next_greatest_element_slow()
test_next_greatest_element_fast()
test_next_greatest_element()