The required code updates for writing unit test cases for the above script are as follows:

[python/chat_app/server/test_server.py]

python
import unittest
import server
from unittest.mock import patch, Mock

class TestServer(unittest.TestCase):

    @patch("socket.socket")
    def setUp(self, mock_socket):
        self.server = server.ServerWindow("127.0.0.1", 1100)
        self.server.server = mock_socket

    def test_setup_server(self):
        with patch.object(self.server, 'handle_socket') as mock_handle_socket:
            self.server.setupServer()
            self.assertEqual(self.server.server.bind.call_count, 1)
            self.assertEqual(self.server.server.listen.call_count, 1)
            mock_handle_socket.assert_called_once()

    def test_handle_socket(self):
        with patch.object(self.server, 'receive') as mock_receive, patch.object(self.server, 'updateTableWidget') as mock_update:
            mock_receive.return_value = "NAME: Test"
            self.server.handle_socket(Mock())
            self.assertEqual(self.server.updateTableWidget.call_count, 1)

    def test_create_room(self):
        self.server.create_room(Mock(), "-create test_room")
        self.assertTrue("test_room" in self.server.rooms)
        
    def test_join_room(self):
        self.server.rooms = {"test_room": []}
        self.server.join_room(Mock(), "-join test_room")
        self.assertNotEqual(self.server.rooms["test_room"], [])

    def test_leave_room(self):
        sock = Mock()
        self.server.rooms = {"test_room": ["User1"]}
        self.server.room_map = {"test_room": [server.UserMap(sock, "User1")]}
        self.server.client_map[sock] = ("127.0.0.1", "User1", None)
        self.server.leave_room(sock, "User1", "test_room")
        self.assertEqual(self.server.rooms["test_room"], [])

    def test_close_server(self):
        with patch.object(self.server, 'close') as mock_close:
            self.server.close_server()
            self.server.server.shutdown.assert_called_once()
            self.server.server.close.assert_called_once()
            mock_close.assert_called_once()

if __name__ == '__main__':
    unittest.main()


