```python
import unittest
from unittest.mock import patch, Mock
import server as chat_app_server

class TestChatAppServer(unittest.TestCase):

    def setUp(self):
        self.server_window = chat_app_server.ServerWindow()

    def test_formatResult(self):
        result = self.server_window.formatResult("green", "Test")
        self.assertIn("[", result)
        self.assertIn("]*", result)

    def test_get_just_name(self):
        mock_socket = Mock()
        self.server_window.client_map[mock_socket] = ("address", "test_name", "pubkey")
        self.assertEqual(self.server_window.get_just_name(mock_socket), "test_name")

    def test_get_address(self):
        mock_socket = Mock()
        self.server_window.client_map[mock_socket] = ("address", "test_name", "pubkey")
        self.assertEqual(self.server_window.get_address(mock_socket), "address")

    @patch.object(chat_app_server.ServerWindow, 'send')
    def test_send_encrypted(self, mock_send):
        mock_socket = Mock()
        message = "Test message"
        name = "test_name"
        self.server_window.client_map[mock_socket] = ("address", name, Mock())
        self.server_window.send_encrypted(mock_socket, message, name)
        mock_send.assert_called()

    @patch.object(chat_app_server.ServerWindow, 'send')
    def test_join_room(self, mock_send):
        room_name = "test_room"
        user_name = "test_user"

        self.server_window.rooms[room_name] = []
        self.server_window.room_map[room_name] = []

        mock_socket = Mock()
        self.server_window.client_map[mock_socket] = (("address", "pubkey"), user_name, "pubkey")

        self.server_window.join_room(mock_socket, "-join " + room_name)
        self.assertTrue(room_name in self.server_window.room_map)
        self.assertTrue(user_name in self.server_window.rooms[room_name])

    @patch.object(chat_app_server.ServerWindow, 'send')
    def test_leave_room(self, mock_send):
        room_name = "test_room"
        user_name = "test_user"

        self.server_window.rooms[room_name] = [user_name]
        self.server_window.room_map[room_name] = [chat_app_server.UserMap(Mock(), user_name)]

        mock_socket = Mock()
        self.server_window.client_map[mock_socket] = (("address", "pubkey"), user_name, "pubkey")

        self.server_window.leave_room(mock_socket, user_name, room_name)
        self.assertFalse(user_name in self.server_window.rooms[room_name])

if __name__ == '__main__':
    unittest.main()
```