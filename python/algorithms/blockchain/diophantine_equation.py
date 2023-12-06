from __future__ import annotations

def test_diophantine():
    assert diophantine(10, 6, 14) == (-7.0, 14.0)
    assert diophantine(391, 299, -69) == (9.0, -12.0)

def test_diophantine_all_soln():
    diophantine_all_soln(10, 6, 14)
    diophantine_all_soln(10, 6, 14, 4)
    diophantine_all_soln(391, 299, -69, n=4)

def test_greatest_common_divisor():
    assert greatest_common_divisor(7, 5) == 1
    assert greatest_common_divisor(121, 11) == 11

def test_extended_gcd():
    assert extended_gcd(10, 6) == (2, -1, 2)
    assert extended_gcd(7, 5) == (1, -2, 3)

test_diophantine()
test_diophantine_all_soln()
test_greatest_common_divisor()
test_extended_gcd()