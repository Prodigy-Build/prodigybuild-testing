The updated code for "python/algorithms/maths/decimal_isolate.py" is as follows:

```python
def decimal_isolate(number: float, digit_amount: int) -> float:
    """
    Isolates the decimal part of a number.
    If digitAmount > 0 round to that decimal place, else print the entire decimal.
    >>> decimal_isolate(1.53, 0)
    0.53
    >>> decimal_isolate(35.345, 1)
    0.3
    >>> decimal_isolate(35.345, 2)
    0.34
    >>> decimal_isolate(35.345, 3)
    0.345
    >>> decimal_isolate(-14.789, 3)
    -0.789
    >>> decimal_isolate(0, 2)
    0
    >>> decimal_isolate(-14.123, 1)
    -0.1
    >>> decimal_isolate(-14.123, 2)
    -0.12
    >>> decimal_isolate(-14.123, 3)
    -0.123
    """
    if digit_amount > 0:
        return round(number - int(number), digit_amount)
    return number - int(number)
```

Please note that the original code provided is already testable and includes test cases.