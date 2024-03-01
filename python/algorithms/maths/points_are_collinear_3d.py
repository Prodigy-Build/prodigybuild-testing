from typing import Tuple

def test_create_vector():
    assert create_vector((0, 0, 0), (1, 1, 1)) == (1, 1, 1)
    assert create_vector((45, 70, 24), (47, 32, 1)) == (2, -38, -23)
    assert create_vector((-14, -1, -8), (-7, 6, 4)) == (7, 7, 12)

def test_get_3d_vectors_cross():
    assert get_3d_vectors_cross((3, 4, 7), (4, 9, 2)) == (-55, 22, 11)
    assert get_3d_vectors_cross((1, 1, 1), (1, 1, 1)) == (0, 0, 0)
    assert get_3d_vectors_cross((-4, 3, 0), (3, -9, -12)) == (-36, -48, 27)
    assert get_3d_vectors_cross((17.67, 4.7, 6.78), (-9.5, 4.78, -19.33)) == (-123.2594, 277.15110000000004, 129.11260000000001)

def test_is_zero_vector():
    assert is_zero_vector((0, 0, 0), accuracy=10) == True
    assert is_zero_vector((15, 74, 32), accuracy=10) == False
    assert is_zero_vector((-15, -74, -32), accuracy=10) == False

def test_are_collinear():
    assert are_collinear((4.802293498137402, 3.536233125455244, 0),
                          (-2.186788107953106, -9.24561398001649, 7.141509524846482),
                          (1.530169574640268, -2.447927606600034, 3.343487096469054)) == True
    assert are_collinear((-6, -2, 6),
                          (6.200213806439997, -4.930157614926678, -4.482371908289856),
                          (-4.085171149525941, -2.459889509029438, 4.354787180795383)) == True
    assert are_collinear((2.399001826862445, -2.452009976680793, 4.464656666157666),
                          (-3.682816335934376, 5.753788986533145, 9.490993909044244),
                          (1.962903518985307, 3.741415730125627, 7)) == False
    assert are_collinear((1.875375340689544, -7.268426006071538, 7.358196269835993),
                          (-3.546599383667157, -4.630005261513976, 3.208784032924246),
                          (-2.564606140206386, 3.937845170672183, 7)) == False