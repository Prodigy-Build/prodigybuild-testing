Here is the new content of the files:

[python/chat_app/server/server.py]:
python
import unittest
from server import ServerWindow, UserMap

class TestServerWindow(unittest.TestCase):
    def setUp(self):
        self.window = ServerWindow()

    def test_get_just_name(self):
        mock_sock = ('192.168.1.1', 5000)
        self.window.client_map[mock_sock] = (1, 'John', 'public_key')
        name = self.window.get_just_name(mock_sock)
        self.assertEqual(name, 'John')

    def test_get_address(self):
        mock_sock = ('192.168.1.2', 4000)
        self.window.client_map[mock_sock] = (2, 'Jane', 'public_key')
        address = self.window.get_address(mock_sock)
        self.assertEqual(address, 2)

    def test_create_room(self):
        mock_sock = ('192.168.3.3', 6000)
        self.window.create_room(mock_sock, '-create TestRoom')
        self.assertIn('TestRoom', self.window.rooms)

    def test_join_room(self):
        mock_sock = ('192.168.4.4', 7000)
        self.window.rooms = {"TestRoom": []}
        self.window.room_map = {"TestRoom": []}
        self.window.client_map[mock_sock] = (('192.168.4.4', 7000), "John", "public_key")
        self.window.join_room(mock_sock, '-join TestRoom')
        self.assertIn('John', self.window.rooms["TestRoom"])

    def test_leave_room(self):
        mock_sock = ('192.168.5.5', 8000)
        self.window.rooms = {"TestRoom": ["John"]}
        self.window.room_map = {"TestRoom": [UserMap(mock_sock, "John")]}
        self.window.client_map[mock_sock] = (('192.168.5.5', 8000), "John", "public_key")
        self.window.leave_room(mock_sock, 'John', 'TestRoom')
        self.assertNotIn('John', self.window.rooms["TestRoom"])

if __name__ == '__main__':
    unittest.main()

•••••••••••••••••••••••••