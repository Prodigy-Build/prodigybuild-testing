

"""
Determine all possible subsequences of a given sequence using backtracking.

Time complexity: O(2^n),
n represents the length of the input sequence.
"""
from typing import Any, List

def generate_all_subsequences(sequence: List[Any]) -> None:
    _create_state_space_tree(sequence, [], 0)


def _create_state_space_tree(sequence: List[Any], subsequence: List[Any], index: int) -> None:
    """
    Generate a state space tree and perform DFS on it  
    to enumerate each subset, stopping when tree is fully explored.
    """

    if index == len(sequence):
        print(subsequence)
        return

    _create_state_space_tree(sequence, subsequence, index + 1)
    subsequence.append(sequence[index])
    _create_state_space_tree(sequence, subsequence.copy(), index + 1)


if __name__ == "__main__":
    data = [3, 1, 2, 4]
    generate_all_subsequences(data)

    data = ["A", "B", "C"]
    generate_all_subsequences(data)

