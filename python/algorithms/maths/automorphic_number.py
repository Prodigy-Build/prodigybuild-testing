def test_is_automorphic_number():
    assert is_automorphic_number(-1) == False
    assert is_automorphic_number(0) == True
    assert is_automorphic_number(5) == True
    assert is_automorphic_number(6) == True
    assert is_automorphic_number(7) == False
    assert is_automorphic_number(25) == True
    assert is_automorphic_number(259918212890625) == True
    assert is_automorphic_number(259918212890636) == False
    assert is_automorphic_number(740081787109376) == True
    try:
        is_automorphic_number(5.0)
    except TypeError:
        pass
    else:
        raise AssertionError("Expected TypeError")