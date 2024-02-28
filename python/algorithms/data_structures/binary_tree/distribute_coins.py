import unittest

class DistributeCoinsTestCase(unittest.TestCase):
    def test_distribute_coins(self):
        self.assertEqual(distribute_coins(TreeNode(3, TreeNode(0), TreeNode(0))), 2)
        self.assertEqual(distribute_coins(TreeNode(0, TreeNode(3), TreeNode(0))), 3)
        self.assertEqual(distribute_coins(TreeNode(0, TreeNode(0), TreeNode(3))), 3)
        self.assertEqual(distribute_coins(None), 0)
        
        with self.assertRaises(ValueError):
            distribute_coins(TreeNode(0, TreeNode(0), TreeNode(0)))
        
        with self.assertRaises(ValueError):
            distribute_coins(TreeNode(0, TreeNode(1), TreeNode(1)))

    def test_count_nodes(self):
        self.assertEqual(count_nodes(TreeNode(0, TreeNode(0), TreeNode(0))), 3)
        self.assertEqual(count_nodes(None), 0)

    def test_count_coins(self):
        self.assertEqual(count_coins(TreeNode(1, TreeNode(1), TreeNode(1))), 3)
        self.assertEqual(count_coins(None), 0)

    def test_get_distrib(self):
        self.assertEqual(get_distrib(None), CoinsDistribResult(0, 1))


if __name__ == "__main__":
    unittest.main()