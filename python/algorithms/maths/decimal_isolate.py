The updated code with unit test cases is as follows:

```python
def decimal_isolate(number: float, digit_amount: int) -> float:
    """
    Isolates the decimal part of a number.
    If digitAmount > 0 round to that decimal place, else print the entire decimal.
    """
    if digit_amount > 0:
        return round(number - int(number), digit_amount)
    return number - int(number)


import unittest


class DecimalIsolateTestCase(unittest.TestCase):
    def test_decimal_isolate_with_zero_digit_amount(self):
        self.assertEqual(decimal_isolate(1.53, 0), 0.53)
        self.assertEqual(decimal_isolate(35.345, 0), 0.345)
        self.assertEqual(decimal_isolate(-14.789, 0), -0.789)
        self.assertEqual(decimal_isolate(0, 0), 0)

    def test_decimal_isolate_with_positive_digit_amount(self):
        self.assertEqual(decimal_isolate(35.345, 1), 0.3)
        self.assertEqual(decimal_isolate(35.345, 2), 0.34)
        self.assertEqual(decimal_isolate(35.345, 3), 0.345)
        self.assertEqual(decimal_isolate(-14.123, 1), -0.1)
        self.assertEqual(decimal_isolate(-14.123, 2), -0.12)
        self.assertEqual(decimal_isolate(-14.123, 3), -0.123)


if __name__ == "__main__":
    unittest.main()
```
