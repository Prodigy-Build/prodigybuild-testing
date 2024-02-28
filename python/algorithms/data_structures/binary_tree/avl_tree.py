```python
import unittest
from avl_tree import AVLtree

class AVLTreeTestCase(unittest.TestCase):
    def test_insert(self):
        t = AVLtree()
        t.insert(4)
        self.assertEqual(str(t).replace(" \\n","\\n"), " 4\n*************************************")
        t.insert(2)
        self.assertEqual(str(t).replace(" \\n","\\n").replace(" \\n","\\n"), "  4\n 2  *\n*************************************")
        t.insert(3)
        self.assertEqual(str(t).replace(" \\n","\\n").replace(" \\n","\\n"), "  3\n 2  4\n*************************************")

    def test_get_height(self):
        t = AVLtree()
        t.insert(4)
        self.assertEqual(t.get_height(), 1)
        t.insert(2)
        self.assertEqual(t.get_height(), 2)
        t.insert(3)
        self.assertEqual(t.get_height(), 2)

    def test_del_node(self):
        t = AVLtree()
        t.insert(4)
        t.insert(2)
        t.insert(3)
        t.del_node(3)
        self.assertEqual(str(t).replace(" \\n","\\n").replace(" \\n","\\n"), "  4\n 2  *\n*************************************")

if __name__ == '__main__':
    unittest.main()
```