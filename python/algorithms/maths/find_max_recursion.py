The new code for the file "python/algorithms/maths/find_max_recursion.py" is as follows:

```python
from typing import List, Union


def find_max(nums: List[Union[int, float]], left: int, right: int) -> Union[int, float]:
    if len(nums) == 0:
        raise ValueError("find_max() arg is an empty sequence")
    if (
        left >= len(nums)
        or left < -len(nums)
        or right >= len(nums)
        or right < -len(nums)
    ):
        raise IndexError("list index out of range")
    if left == right:
        return nums[left]
    mid = (left + right) >> 1
    left_max = find_max(nums, left, mid)
    right_max = find_max(nums, mid + 1, right)

    return left_max if left_max >= right_max else right_max
```

Please note that the original code provided in the question is already testable and includes test cases.