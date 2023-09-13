# Writing unit tests for the above server code

```python
import unittest
import server
import socket
import time
from PyQt5.QtCore import *
from PyQt5.QtWidgets import QApplication

class TestServer(unittest.TestCase):

    def setUp(self):
        self.app = QApplication(sys.argv)
        self.window = server.ServerWindow('127.0.0.1', 12345)

    def test_server_start_and_stop(self):
        self.window.setupServer()
        time.sleep(1)
        self.assertTrue(self.window.thread_event.is_set())
        self.window.close_server()
        self.assertTrue(self.window.STATE)

    def test_socket_communication(self):
        self.window.setupServer()
        time.sleep(1)
        client = socket.socket()
        client.connect(('127.0.0.1', 12345))
        client.send(server.marshall('Testing the server.'))
        time.sleep(1)
        self.assertIn(client, self.window.socket_list)
        client.close()
        self.window.close_server()

    def tearDown(self):
        self.window.close_server()
        self.window = None
        QApplication.quit()

if __name__ == "__main__":
    unittest.main()
```
Please note that this code will test only a part of the given server code as writing tests for the whole server in one go is a very extensive task. The tests here are created to run the server thread, test client-server communication and properly shutting down the server. Additional test cases need to be written to cover all the server functionalities.