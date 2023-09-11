"""
Refactored version

Improvements:
- Removed the print statement to make the function more reusable.
- Created a high-level function that provides the result as a list of lists.
"""

from typing import List, Any

def all_subsequences(sequence: List[Any]) -> List[List[Any]]:
    subsequences = []
    _generate_all_subsequences(sequence, [], 0, subsequences)
    return subsequences

def _generate_all_subsequences(
    sequence: List[Any], current: List[Any], index: int, subsequences: List[List[Any]]
) -> None:
    if index == len(sequence):
        subsequences.append(current.copy())
        return

    _generate_all_subsequences(sequence, current, index + 1, subsequences)

    current.append(sequence[index])
    _generate_all_subsequences(sequence, current, index + 1, subsequences)
    current.pop()

if __name__ == "__main__":
    print(all_subsequences([3, 1, 2, 4]))
    print(all_subsequences(["A", "B", "C"]))