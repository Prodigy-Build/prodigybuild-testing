import random
import unittest

from algorithms.maths.binary_exp_mod import bin_exp_mod


def is_prime_big(n, prec=1000):
    if n < 2:
        return False

    if n % 2 == 0:
        return n == 2

    d = n - 1
    exp = 0
    while d % 2 == 0:
        d //= 2
        exp += 1

    count = 0
    while count < prec:
        a = random.randint(2, n - 1)
        b = bin_exp_mod(a, d, n)
        if b != 1:
            flag = True
            for _ in range(exp):
                if b == n - 1:
                    flag = False
                    break
                b = b * b
                b %= n
            if flag:
                return False
            count += 1
    return True


class TestIsPrimeBig(unittest.TestCase):
    def test_is_prime_big(self):
        self.assertFalse(is_prime_big(0))
        self.assertFalse(is_prime_big(1))
        self.assertTrue(is_prime_big(2))
        self.assertTrue(is_prime_big(3))
        self.assertFalse(is_prime_big(4))
        self.assertTrue(is_prime_big(5))
        self.assertFalse(is_prime_big(6))
        self.assertTrue(is_prime_big(7))
        self.assertFalse(is_prime_big(8))
        self.assertFalse(is_prime_big(9))
        self.assertFalse(is_prime_big(10))
        self.assertTrue(is_prime_big(11))
        self.assertFalse(is_prime_big(12))
        self.assertTrue(is_prime_big(13))
        self.assertFalse(is_prime_big(14))
        self.assertFalse(is_prime_big(15))
        self.assertFalse(is_prime_big(16))
        self.assertTrue(is_prime_big(17))
        self.assertFalse(is_prime_big(18))
        self.assertTrue(is_prime_big(19))
        self.assertFalse(is_prime_big(20))
        self.assertFalse(is_prime_big(21))
        self.assertFalse(is_prime_big(22))
        self.assertTrue(is_prime_big(23))
        self.assertFalse(is_prime_big(24))
        self.assertFalse(is_prime_big(25))
        self.assertFalse(is_prime_big(26))
        self.assertFalse(is_prime_big(27))
        self.assertFalse(is_prime_big(28))
        self.assertTrue(is_prime_big(29))
        self.assertFalse(is_prime_big(30))
        self.assertFalse(is_prime_big(31))
        self.assertFalse(is_prime_big(32))
        self.assertFalse(is_prime_big(33))
        self.assertFalse(is_prime_big(34))
        self.assertFalse(is_prime_big(35))
        self.assertFalse(is_prime_big(36))
        self.assertFalse(is_prime_big(37))
        self.assertFalse(is_prime_big(38))
        self.assertFalse(is_prime_big(39))
        self.assertFalse(is_prime_big(40))
        self.assertFalse(is_prime_big(41))
        self.assertFalse(is_prime_big(42))
        self.assertFalse(is_prime_big(43))
        self.assertFalse(is_prime_big(44))
        self.assertFalse(is_prime_big(45))
        self.assertFalse(is_prime_big(46))
        self.assertFalse(is_prime_big(47))
        self.assertFalse(is_prime_big(48))
        self.assertFalse(is_prime_big(49))
        self.assertFalse(is_prime_big(50))
        self.assertFalse(is_prime_big(51))
        self.assertFalse(is_prime_big(52))
        self.assertFalse(is_prime_big(53))
        self.assertFalse(is_prime_big(54))
        self.assertFalse(is_prime_big(55))
        self.assertFalse(is_prime_big(56))
        self.assertFalse(is_prime_big(57))
        self.assertFalse(is_prime_big(58))
        self.assertFalse(is_prime_big(59))
        self.assertFalse(is_prime_big(60))
        self.assertFalse(is_prime_big(61))
        self.assertFalse(is_prime_big(62))
        self.assertFalse(is_prime_big(63))
        self.assertFalse(is_prime_big(64))
        self.assertFalse(is_prime_big(65))
        self.assertFalse(is_prime_big(66))
        self.assertFalse(is_prime_big(67))
        self.assertFalse(is_prime_big(68))
        self.assertFalse(is_prime_big(69))
        self.assertFalse(is_prime_big(70))
        self.assertFalse(is_prime_big(71))
        self.assertFalse(is_prime_big(72))
        self.assertFalse(is_prime_big(73))
        self.assertFalse(is_prime_big(74))
        self.assertFalse(is_prime_big(75))
        self.assertFalse(is_prime_big(76))
        self.assertFalse(is_prime_big(77))
        self.assertFalse(is_prime_big(78))
        self.assertFalse(is_prime_big(79))
        self.assertFalse(is_prime_big(80))
        self.assertFalse(is_prime_big(81))
        self.assertFalse(is_prime_big(82))
        self.assertFalse(is_prime_big(83))
        self.assertFalse(is_prime_big(84))
        self.assertFalse(is_prime_big(85))
        self.assertFalse(is_prime_big(86))
        self.assertFalse(is_prime_big(87))
        self.assertFalse(is_prime_big(88))
        self.assertFalse(is_prime_big(89))
        self.assertFalse(is_prime_big(90))
        self.assertFalse(is_prime_big(91))
        self.assertFalse(is_prime_big(92))
        self.assertFalse(is_prime_big(93))
        self.assertFalse(is_prime_big(94))
        self.assertFalse(is_prime_big(95))
        self.assertFalse(is_prime_big(96))
        self.assertFalse(is_prime_big(97))
        self.assertFalse(is_prime_big(98))
        self.assertFalse(is_prime_big(99))
        self.assertFalse(is_prime_big(100))


if __name__ == "__main__":
    unittest.main()