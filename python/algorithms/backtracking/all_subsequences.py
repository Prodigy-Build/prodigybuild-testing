"""
In this problem, we want to determine all possible subsequences
of the given sequence. We use backtracking to solve this problem.

Time complexity: O(2^n),
where n denotes the length of the given sequence.
"""
from __future__ import annotations
from typing import Any, List


class SubsequenceGenerator:

    def __init__(self, sequence: List[Any]):
        self.sequence = sequence

    def generate_all_subsequences(self) -> None:
        self._create_state_space_tree([], 0)
        
    def _create_state_space_tree(self, current_subsequence: List[Any], index: int) -> None:
        """
        Creates a state space tree to iterate through each branch using DFS.
        We know that each state has exactly two children.
        It terminates when it reaches the end of the given sequence.
        """
        if index == len(self.sequence):
            print(current_subsequence)
            return

        self._create_state_space_tree(current_subsequence, index + 1)
        current_subsequence.append(self.sequence[index])
        self._create_state_space_tree(current_subsequence, index + 1)
        current_subsequence.pop()


def main():
    generator = SubsequenceGenerator([3, 1, 2, 4])
    generator.generate_all_subsequences()

    generator = SubsequenceGenerator(["A", "B", "C"])
    generator.generate_all_subsequences()


if __name__ == "__main__":
    main()

