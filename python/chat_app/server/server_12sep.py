```python
import unittest
from unittest.mock import patch, Mock

# Import the `server` module from the chat_app folder
from chat_app.server import server

class TestServer(unittest.TestCase):
    def setUp(self):
        self.app = server.QApplication.instance()
        if self.app is None:
            self.app = server.QApplication(sys.argv)
        self.form = server.ServerWindow()

    def tearDown(self):
        self.form.close()

    @patch('socket.socket')
    def test_setupServer(self, mock_socket):
        mock_socket.return_value = Mock()
        self.form.setupServer()
        self.assertTrue(mock_socket.called)

    @patch('socket.socket')
    def test_handle_socket(self, mock_socket):
        mock_socket.return_value = Mock()
        mock_socket.return_value.recv.return_value = pickle.dumps("NAME: test")
        mock_socket.return_value.fileno.return_value = 1
        self.form.setupServer()
        self.form.handle_socket(self.form.thread_event)
        self.assertTrue(mock_socket.called)

    def test_close_server(self):
        self.form.setupServer()
        self.form.close_server()
        self.assertTrue(self.form.thread_event.isSet())

if __name__ == "__main__":
    unittest.main()
```
