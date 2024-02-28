import unittest

class TestInfixConversion(unittest.TestCase):
    def test_infix_2_postfix(self):
        self.assertEqual(infix_2_postfix("a+b^c"), "cb^a+")
        self.assertEqual(infix_2_postfix("a*(b+c)"), "abc+*")
        self.assertEqual(infix_2_postfix("a/b+(c*d-e)^f"), "ab/cd*e-f^+")

    def test_infix_2_prefix(self):
        self.assertEqual(infix_2_prefix("a+b^c"), "+a^bc")
        self.assertEqual(infix_2_prefix("a*(b+c)"), "*a+bc")
        self.assertEqual(infix_2_prefix("a/b+(c*d-e)^f"), "/a+b-cd*ef^")

if __name__ == '__main__':
    unittest.main()