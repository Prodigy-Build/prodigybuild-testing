"""
Test cases for the comb_sort function can be written by extending the Python's built-in unittest.TestCase class
and adding methods that will be run by the testing framework.
"""
import unittest

class TestCombSort(unittest.TestCase): 
    def test_comb_sort(self): 
        self.assertEqual(comb_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(comb_sort([]), [])
        self.assertEqual(comb_sort([99, 45, -7, 8, 2, 0, -15, 3]), [-15, -7, 0, 2, 3, 8, 45, 99])
        self.assertEqual(comb_sort([1, 0]), [0, 1])
        self.assertEqual(comb_sort([6, 3, 8, 5, 7]), [3, 5, 6, 7, 8])
        self.assertEqual(comb_sort([5]), [5])

if __name__ == "__main__":
    import doctest
    doctest.testmod()
  
    # Run python's built-in unittest module
    unittest.main()