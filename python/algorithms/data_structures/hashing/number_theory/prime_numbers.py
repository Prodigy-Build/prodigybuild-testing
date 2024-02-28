def test_is_prime():
    assert is_prime(0) == False
    assert is_prime(1) == False
    assert is_prime(2) == True
    assert is_prime(3) == True
    assert is_prime(27) == False
    assert is_prime(87) == False
    assert is_prime(563) == True
    assert is_prime(2999) == True
    assert is_prime(67483) == False

def test_next_prime():
    assert next_prime(0) == 2
    assert next_prime(1) == 2
    assert next_prime(2) == 3
    assert next_prime(3) == 5
    assert next_prime(27) == 29
    assert next_prime(87) == 89
    assert next_prime(563) == 569
    assert next_prime(2999) == 3001
    assert next_prime(67483) == 67489