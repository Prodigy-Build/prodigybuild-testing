from typing import List

def collatz_sequence(n: int) -> List[int]:
    if not isinstance(n, int) or n < 1:
        raise Exception("Sequence only defined for natural numbers")

    sequence = [n]
    while n != 1:
        n = 3 * n + 1 if n & 1 else n // 2
        sequence.append(n)
    return sequence