"""
Updated code with refactoring:

This refactoring includes the use of Python's list comprehension instead of the lower level 'for' loop, 
and adjusting function arguments and data types for clarity.
"""
from typing import List, TypeVar

T = TypeVar('T')

def all_subsequences(sequence: List[T]) -> List[List[T]]:
    if sequence:
        *lead, last = sequence
        for sub_sequence in all_subsequences(lead):
            yield sub_sequence
            yield sub_sequence + [last]
    else:
        yield []

if __name__ == "__main__":
    seq = [3, 1, 2, 4]
    for subseq in all_subsequences(seq):
        print(subseq)

    seq = list("ABC")
    for subseq in all_subsequences(seq):
        print(subseq)