from unittest import TestCase, main


class TestNewtonForwardInterpolation(TestCase):
    def test_ucal(self) -> None:
        self.assertEqual(ucal(1, 2), 0)
        self.assertAlmostEqual(ucal(1.1, 2), 0.11000000000000011)
        self.assertAlmostEqual(ucal(1.2, 2), 0.23999999999999994)


# Add more test cases if necessary


if __name__ == "__main__":
    main()