from typing import List

def is_square_free(factors: List[int]) -> bool:
    return len(set(factors)) == len(factors)