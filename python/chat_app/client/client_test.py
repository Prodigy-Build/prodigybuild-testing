



# client_test.py

import unittest
from client import Client

class TestClient(unittest.TestCase):
    def setUp(self):
        self.client = Client('127.0.0.1', 5000)

    def test_client_object_created(self):
        self.assertIsInstance(self.client, Client)

    def test_client_connects_to_server(self):
        self.assertTrue(self.client.connect())

if __name__ == '__main__':
    unittest.main()

