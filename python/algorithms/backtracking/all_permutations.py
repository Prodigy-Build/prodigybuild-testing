from typing import List
import unittest


def generate_all_permutations(sequence: List[int | str]) -> List[List[int | str]]:
    permutations = []
    create_state_space_tree(sequence, [], 0, [False] * len(sequence), permutations)
    return permutations


def create_state_space_tree(
    sequence: List[int | str],
    current_sequence: List[int | str],
    index: int,
    index_used: List[bool],
    permutations: List[List[int | str]],
) -> None:
    if index == len(sequence):
        permutations.append(current_sequence.copy())
        return

    for i in range(len(sequence)):
        if not index_used[i]:
            current_sequence.append(sequence[i])
            index_used[i] = True
            create_state_space_tree(sequence, current_sequence, index + 1, index_used, permutations)
            current_sequence.pop()
            index_used[i] = False


class TestAllPermutations(unittest.TestCase):
    def test_generate_all_permutations(self):
        # Test case 1
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
            [4, 2, 1, 3],
        ]
        self.assertCountEqual(generate_all_permutations(sequence_1), expected_1)

        # Test case 2
        sequence_2 = ["A", "B", "C"]
        expected_2 = [
            ["A", "B", "C"],
            ["A", "C", "B"],
            ["B", "A", "C"],
            ["B", "C", "A"],
            ["C", "A", "B"],
            ["C", "B", "A"],
        ]
        self.assertCountEqual(generate_all_permutations(sequence_2), expected_2)


if __name__ == "__main__":
    unittest.main()