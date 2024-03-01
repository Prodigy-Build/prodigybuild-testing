The updated code for the file "python/algorithms/maths/kadanes.py" with added unit test cases is as follows:

```python
import unittest

def negative_exist(arr: list) -> int:
    arr = arr or [0]
    max_number = arr[0]
    for i in arr:
        if i >= 0:
            return 0
        elif max_number <= i:
            max_number = i
    return max_number

def kadanes(arr: list) -> int:
    max_sum = negative_exist(arr)
    if max_sum < 0:
        return max_sum

    max_sum = 0
    max_till_element = 0

    for i in arr:
        max_till_element += i
        max_sum = max(max_sum, max_till_element)
        max_till_element = max(max_till_element, 0)
    return max_sum

class KadanesTestCase(unittest.TestCase):
    def test_negative_exist(self):
        self.assertEqual(negative_exist([-2, -8, -9]), -2)
        self.assertEqual(negative_exist([2, 8, 9]), 0)
        self.assertEqual(negative_exist([-1, 0, 1]), 0)
        self.assertEqual(negative_exist([0, 0]), 0)
        self.assertEqual(negative_exist([]), 0)

    def test_kadanes(self):
        self.assertEqual(kadanes([2, 3, -9, 8, -2]), 8)
        self.assertEqual(kadanes([-2, -8, -9]), -2)
        self.assertEqual(kadanes([2, 8, 9]), 19)
        self.assertEqual(kadanes([-1, 0, 1]), 1)
        self.assertEqual(kadanes([0, 0]), 0)
        self.assertEqual(kadanes([]), 0)

if __name__ == "__main__":
    unittest.main()
```

Please note that the code provided above includes the original code and the added unit test cases.