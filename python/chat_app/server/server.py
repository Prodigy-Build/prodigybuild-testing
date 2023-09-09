# server.py

# Code does not change here.

…

# test_server.py

import unittest
import mock
from server import ServerWindow, UserMap

class TestUserMap(unittest.TestCase):
    
    @mock.patch('socket.socket')
    def test_init(self, mock_socket):
        sock = mock_socket
        name = "test_user"
        usermap = UserMap(sock, name)
        self.assertEqual(usermap.sock, sock)
        self.assertEqual(usermap.name, name)


class TestServerWindow(unittest.TestCase):
    
    @mock.patch('socket.socket')
    def setUp(self, mock_socket):
        self.app = QCoreApplication([])
        self.window = ServerWindow(host="127.0.0.1", port=3000)
    
    def test_constructor(self):
        self.assertEqual(self.window.host, "127.0.0.1")
        self.assertEqual(self.window.port, 3000)
        
    def test_setup_server(self):
        with mock.patch.object(self.window, 'setupServer') as mock_setup:
            self.window.setupServer()
            mock_setup.assert_called()
            
    def test_get_just_name(self):
        # Add a mock client to client_map
        mock_client = mock.Mock()
        self.window.client_map[mock_client] = ("address", "clientname", "publickey")
        self.assertEqual(self.window.get_just_name(mock_client), "clientname")
        
    def test_get_address(self):
        # Add a mock client to client_map
        mock_client = mock.Mock()
        self.window.client_map[mock_client] = ("address", "clientname", "publickey")
        self.assertEqual(self.window.get_address(mock_client), "address")

    def tearDown(self):
        self.app.quit()

if __name__ == '__main__':
    unittest.main()

…
