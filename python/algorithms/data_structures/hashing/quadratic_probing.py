import unittest
from quadratic_probing import QuadraticProbing

class TestQuadraticProbing(unittest.TestCase):

    def setUp(self):
        self.qp = QuadraticProbing()

    def test_collision_resolution(self):
        self.qp.add("test_key", "test_val")
        hashed_key = self.qp.hash_function("test_key")
        self.qp.values[hashed_key] = "test_key"
        new_key = self.qp._collision_resolution("test_key")
        self.assertNotEqual(hashed_key, new_key)
        
    def test_collision_resolution_none(self):
        self.qp.add("test_key", "test_val")
        hashed_key = self.qp.hash_function("test_key")
        self.qp.values[hashed_key] = "test_key"
        self.qp.lim_charge = 0.5
        new_key = self.qp._collision_resolution("test_key")
        self.assertIsNone(new_key)

    def test_collision_resolution_same_key(self):
        self.qp.add("test_key", "test_val")
        hashed_key = self.qp.hash_function("test_key")
        new_key = self.qp._collision_resolution("test_key")
        self.assertEqual(new_key, hashed_key)

if __name__ == '__main__':
    unittest.main()