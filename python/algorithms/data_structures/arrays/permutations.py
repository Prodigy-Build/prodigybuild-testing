import unittest
from itertools import permutations

def permute(nums: list[int]) -> list[list[int]]:
    result = []
    if len(nums) == 1:
        return [nums.copy()]
    for _ in range(len(nums)):
        n = nums.pop(0)
        permutations = permute(nums)
        for perm in permutations:
            perm.append(n)
        result.extend(permutations)
        nums.append(n)
    return result

def permute2(nums):
    def backtrack(start):
        if start == len(nums) - 1:
            output.append(nums[:])
        else:
            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[i], nums[start]
                backtrack(start + 1)
                nums[start], nums[i] = nums[i], nums[start]  # backtrack

    output = []
    backtrack(0)
    return output

class TestPermutations(unittest.TestCase):

    def test_permute(self):
        numbers = [1,2,3]
        self.assertTrue(all(list(nums) in permute(numbers) for nums in permutations(numbers)))

    def test_permute2(self):
        result = permute2([1, 2, 3])
        expected = [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 2, 1], [3, 1, 2]]
        self.assertEqual(result, expected)

if __name__ == "__main__":
    unittest.main()
