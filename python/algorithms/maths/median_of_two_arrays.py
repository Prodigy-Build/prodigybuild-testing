from typing import List

def median_of_two_arrays(nums1: List[float], nums2: List[float]) -> float:
    all_numbers = sorted(nums1 + nums2)
    div, mod = divmod(len(all_numbers), 2)
    if mod == 1:
        return all_numbers[div]
    else:
        return (all_numbers[div] + all_numbers[div - 1]) / 2

# Test Cases
assert median_of_two_arrays([1, 2], [3]) == 2
assert median_of_two_arrays([0, -1.1], [2.5, 1]) == 0.5
assert median_of_two_arrays([], [2.5, 1]) == 1.75
assert median_of_two_arrays([], [0]) == 0