import unittest

class TestServer(unittest.TestCase):

    def setUp(self):
        self.serverWindow = ServerWindow()

    def test_get_just_name(self):
        client = {"name": "John"}
        self.serverWindow.client_map[client] = ("client address", "John", "pubkey")
        result = self.serverWindow.get_just_name(client)
        self.assertEqual(result, "John")

    def test_get_address(self):
        client = {"name": "John"}
        self.serverWindow.client_map[client] = ("client address", "John", "pubkey")
        result = self.serverWindow.get_address(client)
        self.assertEqual(result, "client address")
    
    def test_formatResult(self):
        result = formatResult("black", "Hello, world!")
        self.assertEqual(result, '<font color="black">Hello, world!</font>')

if __name__ == "__main__":
    unittest.main()