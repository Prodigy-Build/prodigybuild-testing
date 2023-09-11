"""
In this problem, we want to determine all possible subsequences
of the given sequence. We use backtracking to solve this problem.

Time complexity: O(2^n),
where n denotes the length of the given sequence.
"""

from __future__ import annotations
from typing import Any, List

def generate_all_subsequences(sequence: List[Any]) -> None:
    _explore_subsequences(sequence, [], 0)

def _explore_subsequences(sequence: List[Any], current_subsequence: List[Any], index: int) -> None:
    if index == len(sequence):
        print(current_subsequence)
        return

    _explore_subsequences(sequence, current_subsequence.copy(), index + 1)
    current_subsequence.append(sequence[index])
    _explore_subsequences(sequence, current_subsequence, index + 1)

if __name__ == "__main__":
    generate_all_subsequences([3, 1, 2, 4])
    generate_all_subsequences(["A", "B", "C"])