import unittest
from timeit import timeit


def least_common_multiple_slow(first_num: int, second_num: int) -> int:
    max_num = first_num if first_num >= second_num else second_num
    common_mult = max_num
    while (common_mult % first_num > 0) or (common_mult % second_num > 0):
        common_mult += max_num
    return common_mult


def greatest_common_divisor(a: int, b: int) -> int:
    return b if a == 0 else greatest_common_divisor(b % a, a)


def least_common_multiple_fast(first_num: int, second_num: int) -> int:
    return first_num // greatest_common_divisor(first_num, second_num) * second_num


class TestLeastCommonMultiple(unittest.TestCase):
    test_inputs = [
        (10, 20),
        (13, 15),
        (4, 31),
        (10, 42),
        (43, 34),
        (5, 12),
        (12, 25),
        (10, 25),
        (6, 9),
    ]
    expected_results = [20, 195, 124, 210, 1462, 60, 300, 50, 18]

    def test_lcm_function(self):
        for i, (first_num, second_num) in enumerate(self.test_inputs):
            slow_result = least_common_multiple_slow(first_num, second_num)
            fast_result = least_common_multiple_fast(first_num, second_num)
            with self.subTest(i=i):
                self.assertEqual(slow_result, self.expected_results[i])
                self.assertEqual(fast_result, self.expected_results[i])


if __name__ == "__main__":
    unittest.main()