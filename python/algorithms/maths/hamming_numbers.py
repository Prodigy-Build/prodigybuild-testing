The updated code for the file "python/algorithms/maths/hamming_numbers.py" with added unit test cases is as follows:

```python
"""
A Hamming number is a positive integer of the form 2^i*3^j*5^k, for some
non-negative integers i, j, and k. They are often referred to as regular numbers.
More info at: https://en.wikipedia.org/wiki/Regular_number.
"""

from typing import List


def hamming(n_element: int) -> List[int]:
    """
    This function creates an ordered list of n length as requested, and afterwards
    returns the last value of the list. It must be given a positive integer.

    :param n_element: The number of elements on the list
    :return: The nth element of the list
    """
    n_element = int(n_element)
    if n_element < 1:
        raise ValueError("n_element should be a positive number")

    hamming_list = [1]
    i, j, k = (0, 0, 0)
    index = 1
    while index < n_element:
        while hamming_list[i] * 2 <= hamming_list[-1]:
            i += 1
        while hamming_list[j] * 3 <= hamming_list[-1]:
            j += 1
        while hamming_list[k] * 5 <= hamming_list[-1]:
            k += 1
        hamming_list.append(
            min(hamming_list[i] * 2, hamming_list[j] * 3, hamming_list[k] * 5)
        )
        index += 1
    return hamming_list


if __name__ == "__main__":
    n = input("Enter the last number (nth term) of the Hamming Number Series: ")
    print("Formula of Hamming Number Series => 2^i * 3^j * 5^k")
    hamming_numbers = hamming(int(n))
    print("-----------------------------------------------------")
    print(f"The list with nth numbers is: {hamming_numbers}")
    print("-----------------------------------------------------")
```

Unit test cases:

```python
import unittest
from hamming_numbers import hamming

class TestHamming(unittest.TestCase):
    def test_hamming(self):
        self.assertEqual(hamming(5), [1, 2, 3, 4, 5])
        self.assertEqual(hamming(10), [1, 2, 3, 4, 5, 6, 8, 9, 10, 12])
        self.assertEqual(hamming(15), [1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24])
        self.assertEqual(hamming(1), [1])
        self.assertEqual(hamming(0), [])
        self.assertRaises(ValueError, hamming, -5)

if __name__ == '__main__':
    unittest.main()
```

Note: Please make sure to update the import statement in the unit test file to match the correct file path of the "hamming_numbers.py" file.