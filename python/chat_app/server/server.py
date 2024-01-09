The provided instructions pertain to a different language and thus cannot be applied for this Python code block. The following are some examples of units tests for the python/chat_app/server/server.py file.

```python
import unittest
from unittest.mock import patch, MagicMock
from server import ServerWindow, QApplication

class TestChatAppServer(unittest.TestCase):

    @patch('socket.socket')
    @patch('PyQt5.uic.loadUi')
    def setUp(self, mock_loadUi, mock_socket):
        self.app = QApplication.instance()
        if not self.app:
            self.app = QApplication(sys.argv)
        self.server = ServerWindow()

    def test_server_window_init(self):
        self.assertEqual(self.server.host, "127.0.0.1")
        self.assertEqual(self.server.port, 1100)
        self.assertIsNotNone(self.server.client_map)
        self.assertIsNotNone(self.server.socket_list)

    @patch('server.socket.socket')
    @patch('server.receive')
    @patch('server.uic.loadUi')
    def test_handle_socket_new_connection(self, mock_loadUi, mock_receive, mock_socket):
        self.app = QApplication.instance()
        if not self.app:
            self.app = QApplication(sys.argv)
        self.server = ServerWindow()

        client_socket = MagicMock()
        client_socket.fileno.return_value = 1001
        mock_socket.return_value.accept.return_value = [client_socket, ('localhost', 5000)]
        mock_receive.return_value = "NAME: test name"
        mock_socket.return_value.fileno.return_value = 1000

        self.server.setupServer()
        self.server.handle_socket(thread_event=MagicMock())

        client_socket.fileno.assert_called_once()
        client_socket.recv.assert_called()
        mock_receive.assert_called()

    @patch('server.socket.socket')
    @patch('server.send')
    @patch('server.receive')
    @patch('server.ServerWindow.get_just_name')
    @patch('server.ServerWindow.get_address')
    @patch('server.uic.loadUi')
    def test_handle_socket_already_connected(self, mock_loadUi, mock_get_address, mock_get_just_name, mock_receive, mock_send, mock_socket):
        self.app = QApplication.instance()
        if not self.app:
            self.app = QApplication(sys.argv)
        self.server = ServerWindow()

        client_socket = MagicMock()
        mock_socket.return_value.accept.return_value = [client_socket, ('localhost', 5000)]
        mock_receive.return_value = "-create room_name"
        mock_get_just_name.return_value = "test name"
        mock_get_address.return_value = "localhost"

        self.server.setupServer()
        self.server.handle_socket(thread_event=MagicMock())

        mock_send.assert_called()
        mock_receive.assert_called()

if __name__ == '__main__':
    unittest.main()
```

This is just an example. Depending on the actual functionality of the methods in the server server, it may be necessary to add more tests, or modify these. The examples cover only some of the methods such as `__init__`, `setupServer`, and `handle_socket`.