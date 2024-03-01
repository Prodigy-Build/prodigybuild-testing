def test_greatest_common_divisor():
    assert greatest_common_divisor(24, 40) == 8
    assert greatest_common_divisor(1, 1) == 1
    assert greatest_common_divisor(1, 800) == 1
    assert greatest_common_divisor(11, 37) == 1
    assert greatest_common_divisor(3, 5) == 1
    assert greatest_common_divisor(16, 4) == 4
    assert greatest_common_divisor(-3, 9) == 3
    assert greatest_common_divisor(9, -3) == 3
    assert greatest_common_divisor(3, -9) == 3
    assert greatest_common_divisor(-3, -9) == 3


def test_gcd_by_iterative():
    assert gcd_by_iterative(24, 40) == 8
    assert gcd_by_iterative(24, 40) == greatest_common_divisor(24, 40)
    assert gcd_by_iterative(-3, -9) == 3
    assert gcd_by_iterative(3, -9) == 3
    assert gcd_by_iterative(1, -800) == 1
    assert gcd_by_iterative(11, 37) == 1