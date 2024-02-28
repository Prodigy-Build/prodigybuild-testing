```python
import unittest
from radix_tree import RadixNode

class TestRadixTree(unittest.TestCase):
    def setUp(self):
        self.root = RadixNode()
        self.words = "banana bananas bandanas bandana band apple all beast".split()
        self.root.insert_many(self.words)

    def test_find_existing_word(self):
        for word in self.words:
            self.assertTrue(self.root.find(word))

    def test_find_non_existing_word(self):
        self.assertFalse(self.root.find("bandanas"))
        self.assertFalse(self.root.find("apps"))

    def test_delete_existing_word(self):
        self.assertTrue(self.root.find("all"))
        self.root.delete("all")
        self.assertFalse(self.root.find("all"))

    def test_delete_non_existing_word(self):
        self.assertFalse(self.root.delete("banana"))
        self.assertTrue(self.root.find("banana"))

    def test_delete_word_with_common_prefix(self):
        self.assertTrue(self.root.find("banana"))
        self.assertTrue(self.root.find("bananas"))
        self.root.delete("banana")
        self.assertFalse(self.root.find("banana"))
        self.assertTrue(self.root.find("bananas"))

if __name__ == '__main__':
    unittest.main()
```