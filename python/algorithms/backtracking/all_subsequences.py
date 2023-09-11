

"""
In this problem, we want to identify all possible subsequences
of the provided sequence. It will be solved using backtracking.

Time complexity: O(2^n),
Where n is the length of the given sequence.
"""
from typing import Any, List


def generate_all_subsequences(sequence: List[Any]) -> None:
    _create_state_space_tree(sequence, [], 0)


def _create_state_space_tree(
    sequence: List[Any], current_subsequence: List[Any], index: int
) -> None:
    """
    Creating a state space tree to iterate through each branch by using DFS.
    Each state has exactly two children. It will stop 
    when it reaches the end of the given sequence.
    """

    if index == len(sequence):
        print(current_subsequence)
        return

    _create_state_space_tree(sequence, current_subsequence, index + 1)
    current_subsequence.append(sequence[index])
    _create_state_space_tree(sequence, current_subsequence, index + 1)
    current_subsequence.pop()


if __name__ == "__main__":
    seq: List[Any] = [3, 1, 2, 4]
    generate_all_subsequences(seq)

    seq.clear()
    seq.extend(["A", "B", "C"])
    generate_all_subsequences(seq)

