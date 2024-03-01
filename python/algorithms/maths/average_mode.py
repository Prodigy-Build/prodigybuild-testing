from typing import Any
import unittest

def mode(input_list: list) -> list[Any]:
    if not input_list:
        return []
    result = [input_list.count(value) for value in input_list]
    y = max(result)
    return sorted({input_list[i] for i, value in enumerate(result) if value == y})

class TestMode(unittest.TestCase):
    def test_mode_with_integers(self):
        self.assertEqual(mode([2, 3, 4, 5, 3, 4, 2, 5, 2, 2, 4, 2, 2, 2]), [2])
        self.assertEqual(mode([3, 4, 5, 3, 4, 2, 5, 2, 2, 4, 4, 2, 2, 2]), [2])
        self.assertEqual(mode([3, 4, 5, 3, 4, 2, 5, 2, 2, 4, 4, 4, 2, 2, 4, 2]), [2, 4])

    def test_mode_with_strings(self):
        self.assertEqual(mode(["x", "y", "y", "z"]), ['y'])
        self.assertEqual(mode(["x", "x" , "y", "y", "z"]), ['x', 'y'])

    def test_mode_with_empty_list(self):
        self.assertEqual(mode([]), [])

if __name__ == "__main__":
    unittest.main()