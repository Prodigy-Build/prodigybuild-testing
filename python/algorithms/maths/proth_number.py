The updated code for the file "python/algorithms/maths/proth_number.py" with added unit test cases is as follows:

```python
"""
Calculate the nth Proth number
Source:
    https://handwiki.org/wiki/Proth_number
"""

import math
import unittest


def proth(number: int) -> int:
    """
    :param number: nth number to calculate in the sequence
    :return: the nth number in Proth number
    Note: indexing starts at 1 i.e. proth(1) gives the first Proth number of 3
    >>> proth(6)
    25
    >>> proth(0)
    Traceback (most recent call last):
        ...
    ValueError: Input value of [number=0] must be > 0
    >>> proth(-1)
    Traceback (most recent call last):
        ...
    ValueError: Input value of [number=-1] must be > 0
    >>> proth(6.0)
    Traceback (most recent call last):
        ...
    TypeError: Input value of [number=6.0] must be an integer
    """

    if not isinstance(number, int):
        msg = f"Input value of [number={number}] must be an integer"
        raise TypeError(msg)

    if number < 1:
        msg = f"Input value of [number={number}] must be > 0"
        raise ValueError(msg)
    elif number == 1:
        return 3
    elif number == 2:
        return 5
    else:
        """
        +1 for binary starting at 0 i.e. 2^0, 2^1, etc.
        +1 to start the sequence at the 3rd Proth number
        Hence, we have a +2 in the below statement
        """
        block_index = int(math.log(number // 3, 2)) + 2

        proth_list = [3, 5]
        proth_index = 2
        increment = 3
        for block in range(1, block_index):
            for _ in range(increment):
                proth_list.append(2 ** (block + 1) + proth_list[proth_index - 1])
                proth_index += 1
            increment *= 2

    return proth_list[number - 1]


class ProthNumberTestCase(unittest.TestCase):
    def test_proth(self):
        self.assertEqual(proth(1), 3)
        self.assertEqual(proth(2), 5)
        self.assertEqual(proth(3), 9)
        self.assertEqual(proth(4), 13)
        self.assertEqual(proth(5), 17)
        self.assertEqual(proth(6), 25)
        self.assertEqual(proth(7), 33)
        self.assertEqual(proth(8), 41)
        self.assertEqual(proth(9), 49)
        self.assertEqual(proth(10), 65)
        self.assertEqual(proth(11), 81)

    def test_proth_invalid_input(self):
        with self.assertRaises(TypeError):
            proth(6.0)
        with self.assertRaises(ValueError):
            proth(0)
        with self.assertRaises(ValueError):
            proth(-1)


if __name__ == "__main__":
    unittest.main()
```
