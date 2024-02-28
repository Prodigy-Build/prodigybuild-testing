import unittest

class TestTopologicalSort(unittest.TestCase):
    
    def setUp(self):
        self.edges = {"a": ["c", "b"], "b": ["d", "e"], "c": [], "d": [], "e": []}
        self.vertices = ["a", "b", "c", "d", "e"]
    
    def test_topological_sort(self):
        self.assertEqual(topological_sort("a", [], []), ['e', 'd', 'b', 'c', 'a'])
        self.assertEqual(topological_sort("b", [], []), ['e', 'd', 'b', 'a', 'c'])
        self.assertEqual(topological_sort("c", [], []), ['a', 'b', 'e', 'd', 'c'])

if __name__ == "__main__":
    unittest.main()