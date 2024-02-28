import unittest
import random
import string
from sorts import bubble_sort

class TestBubbleSort(unittest.TestCase):
  
  def test_sorted(self):
    self.assertEqual(bubble_sort([0, 5, 2, 3, 2]), sorted([0, 5, 2, 3, 2]))
    self.assertEqual(bubble_sort([-2, -45, -5]), sorted([-2, -45, -5]))
    self.assertEqual(bubble_sort([-23, 0, 6, -4, 34]), sorted([-23, 0, 6, -4, 34]))
    self.assertEqual(bubble_sort(['d', 'a', 'b', 'e', 'c']), sorted(['d', 'a', 'b', 'e', 'c']))

  def test_empty(self):
    self.assertEqual(bubble_sort([]), [])

  def test_random(self):
    collection = random.sample(range(-50, 50), 100)
    self.assertEqual(bubble_sort(collection), sorted(collection))
    collection = random.choices(string.ascii_letters + string.digits, k=100)
    self.assertEqual(bubble_sort(collection), sorted(collection))

if __name__ == "__main__":
    unittest.main()