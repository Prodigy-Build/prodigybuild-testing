def test_prime_factors():
    assert prime_factors(100) == [2, 2, 5, 5]
    try:
        prime_factors(0)
    except ValueError as e:
        assert str(e) == "Only positive integers have prime factors"
    try:
        prime_factors(-10)
    except ValueError as e:
        assert str(e) == "Only positive integers have prime factors"


def test_number_of_divisors():
    assert number_of_divisors(100) == 9
    try:
        number_of_divisors(0)
    except ValueError as e:
        assert str(e) == "Only positive numbers are accepted"
    try:
        number_of_divisors(-10)
    except ValueError as e:
        assert str(e) == "Only positive numbers are accepted"


def test_sum_of_divisors():
    assert sum_of_divisors(100) == 217
    try:
        sum_of_divisors(0)
    except ValueError as e:
        assert str(e) == "Only positive numbers are accepted"
    try:
        sum_of_divisors(-10)
    except ValueError as e:
        assert str(e) == "Only positive numbers are accepted"


def test_euler_phi():
    assert euler_phi(100) == 40


test_prime_factors()
test_number_of_divisors()
test_sum_of_divisors()
test_euler_phi()