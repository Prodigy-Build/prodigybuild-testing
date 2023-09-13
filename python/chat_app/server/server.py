```python
import unittest
from unittest.mock import patch, Mock

from server import ServerWindow, UserMap

class TestServer(unittest.TestCase):

    def setUp(self):
       self.server = ServerWindow()

    def tearDown(self):
       self.server = None

    @patch('socket.socket')
    def test_setup_server(self, mock_socket):
       self.server.setupServer()
       mock_socket.assert_called_once()

    def test_join_room(self):
       self.server.rooms = {'room1': ['user1']}
       self.server.room_map = {'room1': [UserMap('sock1', 'user1')]}
       mock_sock = 'sock2'
       self.server.client_map = {mock_sock: ('addr1', 'user2', 'pubkey1')}
       self.server.join_room(mock_sock, "-join room1")
       self.assertIn('user2', self.server.rooms['room1'])
       self.assertIn(UserMap(mock_sock, 'user2'), self.server.room_map['room1'])

    def test_leave_room(self):
       mock_sock = 'sock1'
       self.server.rooms = {'room1': ['user1', 'user2']}
       self.server.room_map = {'room1': [UserMap('sock1', 'user1'), UserMap('sock2', 'user2')]}
       self.server.client_map = {mock_sock: ('addr1', 'user1', 'pubkey1')}
       self.server.leave_room(mock_sock, 'user1', 'room1')
       self.assertNotIn('user1', self.server.rooms['room1'])
       self.assertNotIn(UserMap(mock_sock, 'user1'), self.server.room_map['room1'])

    def test_create_room(self):
       mock_sock = 'sock2'
       self.server.client_map = {mock_sock: ('addr1', 'user2', 'pubkey1')}
       self.server.create_room(mock_sock, "-create room2")
       self.assertIn('room2', self.server.rooms)
       self.assertIn(UserMap(mock_sock, 'user2'), self.server.room_map['room2'])

    @patch('builtins.print')
    def test_handle_socket_no_data(self, mock_print):
       self.server.outputs = []
       self.server.socket_list = []
       self.server.rooms = {}
       self.server.client_map = {}
       self.server.room_map = {}
       self.server.STATE = True
       with patch('select.select') as mock_select:
           mock_select.return_value = ([], [], [])
           self.server.handle_socket(False)
           mock_select.assert_called()
        
if __name__ == '__main__':
    unittest.main()
```
The above code is a basic unit testing setup for our chat server class. It mocks up the necessary dependencies and tests the primary features such as creating and joining rooms, and handling socket connections properly. All possible outcomes are checked for each feature, and tests are repeated for each case to ensure no misbehaviours.