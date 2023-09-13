```python
import unittest
from unittest.mock import patch, Mock
from server import *

# Test Case for the server-side code of chat application
class ServerTests(unittest.TestCase):

    @patch('socket.socket', return_value=Mock())
    def test_setup_server(self, mock_socket):
        sw = ServerWindow()

        # Test if socket is created.
        mock_socket.assert_called_with(socket.AF_INET, socket.SOCK_STREAM)

    def test_send_receive(self):
        sw = ServerWindow()
        mock_send = Mock()
        mock_receive = Mock()

        with patch('server.send', mock_send), patch('server.receive', mock_receive):
            mock_receive.return_value = 'Hello, client!'
            mock_send.return_value = True

            result = receive(sw)
            send(sw, 'Hello, world')

            # Test if the sent message is received correctly
            self.assertEqual(result, 'Hello, client!')

    def test_Create_Join_Leave_Room(self):
        sw = ServerWindow()

        # Create sample socket and data
        mock_sock = Mock()
        sw.create_room(mock_sock, "-create TestRoom")
        self.assertIn('TestRoom', sw.rooms, msg = "TestRoom not created")

        mock_sock = Mock()
        sw.join_room(mock_sock, "-join TestRoom")
        self.assertIn('TestRoom', sw.room_map, msg = "Did not join TestRoom")

        user_name = sw.get_just_name(mock_sock)
        sw.leave_room(mock_sock, user_name, 'TestRoom')
        self.assertNotIn('TestRoom', sw.room_map, msg = "Did not leave TestRoom")


if __name__ == '__main__':
    unittest.main()
```
