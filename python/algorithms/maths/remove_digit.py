import unittest

def remove_digit(num: int) -> int:
    if not isinstance(num, int):
        raise TypeError("only integers accepted as input")
    else:
        num_str = str(abs(num))
        num_transpositions = [list(num_str) for char in range(len(num_str))]
        for index in range(len(num_str)):
            num_transpositions[index].pop(index)
        return max(
            int("".join(list(transposition))) for transposition in num_transpositions
        )

class TestRemoveDigit(unittest.TestCase):
    def test_remove_digit(self):
        self.assertEqual(remove_digit(152), 52)
        self.assertEqual(remove_digit(6385), 685)
        self.assertEqual(remove_digit(-11), 1)
        self.assertEqual(remove_digit(2222222), 222222)
        with self.assertRaises(TypeError):
            remove_digit("2222222")
        with self.assertRaises(TypeError):
            remove_digit("string input")

if __name__ == "__main__":
    unittest.main()