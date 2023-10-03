import unittest
from typing import List, Type
from unittest.mock import patch
import math

from python.algorithms.arithmetic_analysis.newton_forward_interpolation import (
    ucal,
    main
)


class TestNewtonForwardInterpolation(unittest.TestCase):

    def test_ucal(self):
        self.assertEqual(ucal(1, 2), 0)
        self.assertEqual(ucal(1.1, 2), 0.11000000000000011)
        self.assertEqual(ucal(1.2, 2), 0.23999999999999994)

    @patch('builtins.input', side_effect=['3', '1 2 3', '1', '2', '3', '2'])
    def test_main(self, mock_input):
        with patch('builtins.input', side_effect=['3', '1 2 3', '1', '2', '3', '2']):
            main()


if __name__ == "__main__":
    unittest.main()