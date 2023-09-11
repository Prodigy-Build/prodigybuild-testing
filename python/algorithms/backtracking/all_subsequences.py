"""
Backtracking algorithm to generate all possible subsequences
of a given sequence.
"""

from typing import List, Any


def generate_all_subsequences(sequence: List[Any], index: int = 0, subsequence: List[Any] = None) -> None:
    if subsequence is None:
        subsequence = []

    if index == len(sequence):
        print(subsequence)
        return

    generate_all_subsequences(sequence, index + 1, subsequence)
    generate_all_subsequences(sequence, index + 1, subsequence + [sequence[index]])


if __name__ == "__main__":
    seq: List[Any] = [3, 1, 2, 4]
    generate_all_subsequences(seq)

    seq = ["A", "B", "C"]
    generate_all_subsequences(seq)