```python
import unittest
from server import *

class TestChatAppServer(unittest.TestCase):

    def setUp(self):
        self.serverWindow = ServerWindow("localhost", 9090)

    def test_send_receive(self):
        msg = "Test Message"
        socket = self.serverWindow.server
        send(socket, msg)
        recv_msg = receive(socket)
        self.assertEqual(msg, recv_msg)

    def test_user_map(self):
        sock = self.serverWindow.server
        name = "Test User"
        user_map = UserMap(sock, name)
        self.assertEqual(sock, user_map.sock)
        self.assertEqual(name, user_map.name)

    def test_handle_socket(self):
        is_set = self.serverWindow.thread_event.isSet()
        self.assertFalse(is_set) # false cause server is still handling sockets

    def tearDown(self):
        self.serverWindow.close_server()


if __name__ == '__main__':
    unittest.main()
```