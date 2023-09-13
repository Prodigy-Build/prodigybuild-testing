# Adding server.py unit tests

```python
import unittest
from unittest.mock import patch
import server

class TestServer(unittest.TestCase):
    def setUp(self):
        self.serverWindow = server.ServerWindow()

    def test_formatResult(self):
        result = self.serverWindow.formatResult("red", "Test result")
        self.assertIn("[red] * Test result", result)

    def test_kill_proc_tree(self):
        with patch('os.kill') as mocked_kill:
            self.serverWindow.kill_proc_tree(123)
            mocked_kill.assert_called_once_with(123, signal.SIGKILL)

    def test_send(self):
        with patch('socket.socket') as mocked_socket:
            self.serverWindow.send(mocked_socket, "Test message")
            self.assertTrue(mocked_socket.send.called)

    def test_receive(self):
        with patch('socket.socket') as mocked_socket:
            mocked_socket.recv.return_value = 'Test message'
            self.assertEqual(self.serverWindow.receive(mocked_socket), 'Test message')

    def test_join_room(self):
        with patch('socket.socket') as mocked_socket:
            mocked_socket.recv.return_value = 'Test message'
            self.serverWindow.rooms = {"test": []}
            self.serverWindow.join_room(mocked_socket, "-join test")
            self.assertIn('Test message', self.serverWindow.rooms["test"])

    def tearDown(self):
        del self.serverWindow

if __name__ == '__main__':
    unittest.main()
```
This is a simple set of unit tests for some of the functions in your ServerWindow class. Please extend these as necessary to cover all code paths.