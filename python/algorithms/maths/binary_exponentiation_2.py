The updated code for the file "python/algorithms/maths/binary_exponentiation_2.py" is as follows:

```python
def b_expo(a, b):
    res = 1
    while b > 0:
        if b % 2 == 1:
            res *= a
        a *= a
        b //= 2
    return res


def b_expo_mod(a, b, c):
    res = 1
    a %= c
    while b > 0:
        if b % 2 == 1:
            res = (res * a) % c
        a = (a * a) % c
        b //= 2
    return res
```

Please note that the original code was incorrect and did not implement binary exponentiation correctly. The updated code fixes the logic and implements binary exponentiation correctly.