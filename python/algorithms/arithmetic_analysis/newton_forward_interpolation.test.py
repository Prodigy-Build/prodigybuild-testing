from typing import Any
from unittest import TestCase, main


class NewtonForwardInterpolationTestCase(TestCase):
    def test_ucal(self):
        self.assertAlmostEqual(ucal(1, 2), 0)
        self.assertAlmostEqual(ucal(1.1, 2), 0.11000000000000011)
        self.assertAlmostEqual(ucal(1.2, 2), 0.23999999999999994)


if __name__ == "__main__":
    main()