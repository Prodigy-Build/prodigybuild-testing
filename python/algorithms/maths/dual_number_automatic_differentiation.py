from math import factorial

"""
https://en.wikipedia.org/wiki/Automatic_differentiation#Automatic_differentiation_using_dual_numbers
https://blog.jliszka.org/2013/10/24/exact-numeric-nth-derivatives.html

Note this only works for basic functions, f(x) where the power of x is positive.
"""


class Dual:
    def __init__(self, real, rank):
        self.real = real
        if isinstance(rank, int):
            self.duals = [1] * rank
        else:
            self.duals = rank

    def __repr__(self):
        return (
            f"{self.real}+"
            f"{'+'.join(str(dual)+'E'+str(n+1)for n,dual in enumerate(self.duals))}"
        )

    def reduce(self):
        cur = self.duals.copy()
        while cur[-1] == 0:
            cur.pop(-1)
        return Dual(self.real, cur)

    def __add__(self, other):
        if not isinstance(other, Dual):
            return Dual(self.real + other, self.duals)
        s_dual = self.duals.copy()
        o_dual = other.duals.copy()
        if len(s_dual) > len(o_dual):
            o_dual.extend([1] * (len(s_dual) - len(o_dual)))
        elif len(s_dual) < len(o_dual):
            s_dual.extend([1] * (len(o_dual) - len(s_dual)))
        new_duals = []
        for i in range(len(s_dual)):
            new_duals.append(s_dual[i] + o_dual[i])
        return Dual(self.real + other.real, new_duals)

    __radd__ = __add__

    def __sub__(self, other):
        return self + other * -1

    def __mul__(self, other):
        if not isinstance(other, Dual):
            new_duals = []
            for i in self.duals:
                new_duals.append(i * other)
            return Dual(self.real * other, new_duals)
        new_duals = [0] * (len(self.duals) + len(other.duals) + 1)
        for i, item in enumerate(self.duals):
            for j, jtem in enumerate(other.duals):
                new_duals[i + j + 1] += item * jtem
        for k in range(len(self.duals)):
            new_duals[k] += self.duals[k] * other.real
        for index in range(len(other.duals)):
            new_duals[index] += other.duals[index] * self.real
        return Dual(self.real * other.real, new_duals)

    __rmul__ = __mul__

    def __truediv__(self, other):
        if not isinstance(other, Dual):
            new_duals = []
            for i in self.duals:
                new_duals.append(i / other)
            return Dual(self.real / other, new_duals)
        raise ValueError

    def __floordiv__(self, other):
        if not isinstance(other, Dual):
            new_duals = []
            for i in self.duals:
                new_duals.append(i // other)
            return Dual(self.real // other, new_duals)
        raise ValueError

    def __pow__(self, n):
        if n < 0 or isinstance(n, float):
            raise ValueError("power must be a positive integer")
        if n == 0:
            return 1
        if n == 1:
            return self
        x = self
        for _ in range(n - 1):
            x *= self
        return x


def differentiate(func, position, order):
    """
    >>> differentiate(lambda x: x**2, 2, 2)
    2
    >>> differentiate(lambda x: x**2 * x**4, 9, 2)
    196830
    >>> differentiate(lambda y: 0.5 * (y + 3) ** 6, 3.5, 4)
    7605.0
    >>> differentiate(lambda y: y ** 2, 4, 3)
    0
    >>> differentiate(8, 8, 8)
    Traceback (most recent call last):
        ...
    ValueError: differentiate() requires a function as input for func
    >>> differentiate(lambda x: x **2, "", 1)
    Traceback (most recent call last):
        ...
    ValueError: differentiate() requires a float as input for position
    >>> differentiate(lambda x: x**2, 3, "")
    Traceback (most recent call last):
        ...
    ValueError: differentiate() requires an int as input for order
    """
    if not callable(func):
        raise ValueError("differentiate() requires a function as input for func")
    if not isinstance(position, (float, int)):
        raise ValueError("differentiate() requires a float as input for position")
    if not isinstance(order, int):
        raise ValueError("differentiate() requires an int as input for order")
    d = Dual(position, 1)
    result = func(d)
    if order == 0:
        return result.real
    return result.duals[order - 1] * factorial(order)


if __name__ == "__main__":
    import doctest

    doctest.testmod()

    def f(y):
        return y**2 * y**4

    print(differentiate(f, 9, 2))

# Test Cases

def test_dual_init():
    d = Dual(2, 3)
    assert d.real == 2
    assert d.duals == [1, 1, 1]

def test_dual_repr():
    d = Dual(2, 3)
    assert repr(d) == "2+1E1+1E2+1E3"

def test_dual_reduce():
    d = Dual(2, [1, 1, 0, 0])
    reduced = d.reduce()
    assert reduced.real == 2
    assert reduced.duals == [1, 1]

def test_dual_add():
    d1 = Dual(2, 3)
    d2 = Dual(3, [1, 2, 3])
    result = d1 + d2
    assert result.real == 5
    assert result.duals == [2, 3, 3]

def test_dual_sub():
    d1 = Dual(2, 3)
    d2 = Dual(3, [1, 2, 3])
    result = d1 - d2
    assert result.real == -1
    assert result.duals == [-1, -2, -3]

def test_dual_mul():
    d1 = Dual(2, 3)
    d2 = Dual(3, [1, 2, 3])
    result = d1 * d2
    assert result.real == 6
    assert result.duals == [2, 7, 12, 11, 6]

def test_dual_div():
    d1 = Dual(6, [2, 7, 12, 11, 6])
    result = d1 / 3
    assert result.real == 2
    assert result.duals == [2.0/3, 7.0/3, 4.0, 11.0/3, 2.0]

def test_dual_pow():
    d = Dual(2, 3)
    result = d ** 3
    assert result.real == 8
    assert result.duals == [12, 12, 8]

def test_differentiate():
    result = differentiate(lambda x: x**2, 2, 2)
    assert result == 2

    result = differentiate(lambda x: x**2 * x**4, 9, 2)
    assert result == 196830

    result = differentiate(lambda y: 0.5 * (y + 3) ** 6, 3.5, 4)
    assert result == 7605.0

    result = differentiate(lambda y: y ** 2, 4, 3)
    assert result == 0

    try:
        differentiate(8, 8, 8)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        differentiate(lambda x: x **2, "", 1)
        assert False, "Expected ValueError"
    except ValueError:
        pass

    try:
        differentiate(lambda x: x**2, 3, "")
        assert False, "Expected ValueError"
    except ValueError:
        pass

test_dual_init()
test_dual_repr()
test_dual_reduce()
test_dual_add()
test_dual_sub()
test_dual_mul()
test_dual_div()
test_dual_pow()
test_differentiate()