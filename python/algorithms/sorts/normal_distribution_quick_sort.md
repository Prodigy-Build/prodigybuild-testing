```python
import unittest
import numpy as np
from tempfile import TemporaryFile

class TestQuickSort(unittest.TestCase):

    def test_normal_distribution(self):
        outfile = TemporaryFile()
        p = 100
        mu, sigma = 0, 1
        X = np.random.normal(mu, sigma, p)
        np.save(outfile, X)
        self.assertEqual(len(X), 100)
        self.assertTrue(np.all(np.abs(X) <= (mu + 3*sigma)))

    def test_plot_distribution(self):
        p = 100
        mu, sigma = 0, 1 
        s = np.random.normal(mu, sigma, p)
        count, bins = np.histogram(s, 30)
        self.assertEqual(len(bins), 31)
        self.assertTrue(np.all(bins >= (mu - 3*sigma)))
        self.assertTrue(np.all(bins <= (mu + 3*sigma)))

    def test_compare_quick_sort(self):
        quick_sort_nd = [1,1,6,15,43,136,340,800,2156,6821,16325]
        quick_sort_ord = [1,1,4,16,67,122,362,949,2131,5086,12866]
        self.assertEqual(len(quick_sort_nd), 11)
        self.assertEqual(len(quick_sort_ord), 11)
        self.assertGreater(max(quick_sort_nd), max(quick_sort_ord))


if __name__ == '__main__':
    unittest.main()
```