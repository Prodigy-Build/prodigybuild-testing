```python
import unittest

from algorithms.backtracking.all_permutations import generate_all_permutations


class TestAllPermutations(unittest.TestCase):
    def test_generate_all_permutations(self):
        sequence_1 = [3, 1, 2, 4]
        expected_1 = [
            [3, 1, 2, 4],
            [3, 1, 4, 2],
            [3, 2, 1, 4],
            [3, 2, 4, 1],
            [3, 4, 1, 2],
            [3, 4, 2, 1],
            [1, 3, 2, 4],
            [1, 3, 4, 2],
            [1, 2, 3, 4],
            [1, 2, 4, 3],
            [1, 4, 3, 2],
            [1, 4, 2, 3],
            [2, 3, 1, 4],
            [2, 3, 4, 1],
            [2, 1, 3, 4],
            [2, 1, 4, 3],
            [2, 4, 3, 1],
            [2, 4, 1, 3],
            [4, 3, 1, 2],
            [4, 3, 2, 1],
            [4, 1, 3, 2],
            [4, 1, 2, 3],
            [4, 2, 3, 1],
            [4, 2, 1, 3]
        ]
        result_1 = []
        
        def collect_result(sequence):
            result_1.append(sequence.copy())
        
        generate_all_permutations(sequence_1, collect_result)
        
        self.assertEqual(result_1, expected_1)
        
        sequence_2 = ["A", "B", "C"]
        expected_2 = [
            ["A", "B", "C"],
            ["A", "C", "B"],
            ["B", "A", "C"],
            ["B", "C", "A"],
            ["C", "A", "B"],
            ["C", "B", "A"]
        ]
        result_2 = []
        
        generate_all_permutations(sequence_2, collect_result)
        
        self.assertEqual(result_2, expected_2)


if __name__ == "__main__":
    unittest.main()
```