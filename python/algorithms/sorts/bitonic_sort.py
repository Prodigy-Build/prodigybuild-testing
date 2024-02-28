import unittest

class TestBitonicSort(unittest.TestCase):

    def setUp(self):
        self.array = [12, 34, 92, -23, 0, -121, -167, 145]
    
    def test_comp_and_swap(self):
        comp_and_swap(self.array, 0, 7, 1)
        self.assertEqual(self.array, [-167, 34, 92, -23, 0, -121, 167, 145])
        
        comp_and_swap(self.array, 0, 7, 0)
        self.assertEqual(self.array, [145, 34, 92, -23, 0, -121, -167, 145])

    def test_bitonic_merge(self):
        bitonic_merge(self.array, 0, len(self.array), 1)
        self.assertEqual(self.array, [-167, -121, -23, 0, 12, 34, 92, 145])

        bitonic_merge(self.array, 0, len(self.array), 0)
        self.assertEqual(self.array, [145, 92, 34, 12, 0, -23, -121, -167])
        
    def test_bitonic_sort(self):
        bitonic_sort(self.array, 0, len(self.array), 1)
        self.assertEqual(self.array, [-167, -121, -23, 0, 12, 34, 92, 145])

        bitonic_sort(self.array, 0, len(self.array), 0)
        self.assertEqual(self.array, [145, 92, 34, 12, 0, -23, -121, -167])


if __name__ == "__main__":
    unittest.main()