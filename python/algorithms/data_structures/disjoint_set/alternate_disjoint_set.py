import unittest

class TestDisjointSet(unittest.TestCase):
    def test_merge(self):
        A = DisjointSet([1, 1, 1])
        self.assertTrue(A.merge(1, 2))
        self.assertTrue(A.merge(0, 2))
        self.assertFalse(A.merge(0, 1))

    def test_get_parent(self):
        A = DisjointSet([1, 1, 1])
        A.merge(1, 2)
        self.assertEqual(A.get_parent(0), 0)
        self.assertEqual(A.get_parent(1), 2)

if __name__ == '__main__':
    unittest.main()