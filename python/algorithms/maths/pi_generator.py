def calculate_pi(limit: int) -> str:
    q = 1
    r = 0
    t = 1
    k = 1
    n = 3
    l = 3
    decimal = limit
    counter = 0

    result = ""

    while counter != decimal + 1:
        if 4 * q + r - t < n * t:
            result += str(n)
            if counter == 0:
                result += "."

            if decimal == counter:
                break

            counter += 1
            nr = 10 * (r - n * t)
            n = ((10 * (3 * q + r)) // t) - 10 * n
            q *= 10
            r = nr
        else:
            nr = (2 * q + r) * l
            nn = (q * (7 * k) + 2 + (r * l)) // (t * l)
            q *= k
            t *= l
            l += 2
            k += 1
            n = nn
            r = nr
    return result


def test_calculate_pi() -> None:
    import math

    assert float(calculate_pi(15)) == math.pi
    assert math.isclose(float(calculate_pi(50)), math.pi)
    assert math.isclose(float(calculate_pi(100)), math.pi)
    assert calculate_pi(50) == '3.14159265358979323846264338327950288419716939937510'
    assert calculate_pi(80) == '3.14159265358979323846264338327950288419716939937510582097494459230781640628620899'


if __name__ == "__main__":
    test_calculate_pi()