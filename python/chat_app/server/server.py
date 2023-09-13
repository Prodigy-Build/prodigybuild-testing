```python
import unittest

from server import ServerWindow

class TestServerWindow(unittest.TestCase):

    def setUp(self):
        self.server = ServerWindow()

    def test_get_just_name(self):
        client = "test_client"
        self.server.client_map = {
            client: ("127.0.0.1", "test_name", 55555)
        }
        result = self.server.get_just_name(client)
        self.assertEqual(result, "test_name")

    def test_get_address(self):
        client = "test_client"
        self.server.client_map = {
            client: ("127.0.0.1", "test_name", 55555)
        }
        result = self.server.get_address(client)
        self.assertEqual(result, "127.0.0.1")

    def test_create_room(self):
        sock = "test_sock"
        data = "-create test"
        self.server.create_room(sock, data)
        self.assertIn('test', self.server.rooms)
        self.assertIn('test', self.server.room_map)

    def test_join_room(self):
        self.server.rooms = {"test_room": []}
        self.server.room_map = {"test_room": []}
        sock = "test_sock"
        self.server.client_map = {
            sock: ("127.0.0.1", "test_name", 55555)
        }
        data = "-join test_room"
        self.server.join_room(sock, data)
        self.assertIn("test_name", self.server.rooms["test_room"])

    def test_leave_room(self):
        self.server.rooms = {"test_room": ["test_name"]}
        self.server.room_map = {"test_room": ["test_name"]}
        sock = "test_sock"
        self.server.client_map = {
            sock: ("127.0.0.1", "test_name", 55555)
        }
        self.server.leave_room(sock, "test_name", "test_room")
        self.assertNotIn('test_name', self.server.rooms)

if __name__ == '__main__':
    unittest.main()

```