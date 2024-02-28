import unittest

def quick_sort(data: list) -> list:
    if len(data) <= 1:
        return data
    else:
        return [
            *quick_sort([e for e in data[1:] if e <= data[0]]),
            data[0],
            *quick_sort([e for e in data[1:] if e > data[0]]),
        ]

class QuickSortTest(unittest.TestCase):
    
    def test_quick_sort(self):
        self.assertEqual(quick_sort([2, 1, 0]), [0, 1, 2])
        self.assertEqual(quick_sort([2.2, 1.1, 0]), [0, 1.1, 2.2])
        self.assertEqual(quick_sort(list("quick_sort")), list(" _ioqqrtuus"))
        self.assertEqual(quick_sort([]), [])

if __name__ == "__main__":
    unittest.main()