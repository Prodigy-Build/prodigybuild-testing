```python
import unittest
from unittest.mock import patch, MagicMock
from server import *

HOST = "127.0.0.1"
PORT = 8000

class TestServer(unittest.TestCase):
    def setUp(self):
        self.server = ServerWindow(HOST, PORT)
        
    def tearDown(self):
        self.server.close_server()

    def test_send_receive(self):
        """Test that messages are sent and received correctly."""
        message = "test message"
        with patch('socket.socket', spec=True) as mock_socket:
            sock_instance = mock_socket.return_value
            sock_instance.recv.return_value = marshall(message)
            
            print(self.server.server)
            self.server.server.send(repr(message).encode('utf-8'))
            received_message = receive(self.server.server)
            
            self.assertEqual(message, received_message)
            
    def test_join_room(self):
        sock = MagicMock()
        sock.recv.return_value = "-join room1".encode('utf-8')
        self.server.join_room(sock, "-join room1")
        self.assertIn('room1', self.server.rooms)
        self.assertIn(sock, self.server.room_map['room1'])

    def test_leave_room(self):
        sock = MagicMock()
        sock.recv.return_value = "-leave room1".encode('utf-8')
        self.server.leave_room(sock, "test_client", "room1")
        self.assertNotIn('room1', self.server.rooms)
        self.assertNotIn(sock, self.server.room_map['room1'])

    def test_create_room(self):
        sock = MagicMock()
        sock.recv.return_value = "-create room1".encode('utf-8')
        self.server.create_room(sock, "-create room1")
        self.assertIn('room1', self.server.rooms)
        self.assertIn(sock, self.server.room_map['room1'])

    def test_get_just_name(self):
        sock = MagicMock()
        name = "test_client"
        self.server.client_map[sock] = None, name, None
        result = self.server.get_just_name(sock)
        self.assertEqual(name, result)

    def test_get_address(self):
        sock = MagicMock()
        address = ("127.0.0.1", 12345)
        self.server.client_map[sock] = address, None, None
        result = self.server.get_address(sock)
        self.assertEqual(address, result)

if __name__ == "__main__":
    unittest.main()
```
