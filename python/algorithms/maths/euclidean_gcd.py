def euclidean_gcd(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return a


def euclidean_gcd_recursive(a: int, b: int) -> int:
    return a if b == 0 else euclidean_gcd_recursive(b, a % b)


def test_euclidean_gcd():
    assert euclidean_gcd(3, 5) == 1
    assert euclidean_gcd(6, 3) == 3
    assert euclidean_gcd(10, 25) == 5
    assert euclidean_gcd(21, 14) == 7


def test_euclidean_gcd_recursive():
    assert euclidean_gcd_recursive(3, 5) == 1
    assert euclidean_gcd_recursive(6, 3) == 3
    assert euclidean_gcd_recursive(10, 25) == 5
    assert euclidean_gcd_recursive(21, 14) == 7


test_euclidean_gcd()
test_euclidean_gcd_recursive()