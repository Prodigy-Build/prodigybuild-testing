import unittest
from unittest.mock import patch
from PyQt5.QtWidgets import QApplication
import sys

from server_9sep import ServerWindow, UserMap

class TestUserMap(unittest.TestCase):
    def setUp(self):
        self.sock = 'mock_socket'
        self.name = 'test_user'
        self.u_map = UserMap(self.sock, self.name)

    def test_init(self):
        self.assertEqual(self.u_map.sock, self.sock)
        self.assertEqual(self.u_map.name, self.name)

class TestServerWindow(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        # Need to create an instance of QApplication before creating a QMainWindow
        cls.app = QApplication(sys.argv)

    def setUp(self):
        self.window = ServerWindow()

    @patch('socket.socket')
    def test_setupServer(self, mock_socket):
        # Check if the server's setup function runs without error
        self.window.setupServer()
        self.assertTrue(mock_socket.called)

    def test_join_room(self):
        # Test case where user joins an already existing room
        self.window.rooms = {'room1': ['user1']}
        self.window.room_map = {'room1': [UserMap('sock1', 'user1')]}
        self.window.client_map = {'sock2': ('addr2', 'user2', 'pubkey2')}
        # User2 tries to join room1
        self.window.join_room('sock2', '-join room1')
        self.assertIn('user2', self.window.rooms['room1'])
        self.assertIn('user2', [user.name for user in self.window.room_map['room1']])

    def test_create_room(self):
        # Test case where user creates a new room
        self.window.rooms = {}
        self.window.room_map = {}
        self.window.client_map = {'sock1': ('addr1', 'user1', 'pubkey1')}
        # User1 creates a new room 'room1'
        self.window.create_room('sock1', '-create room1')
        self.assertIn('room1', self.window.rooms)
        self.assertIn('room1', self.window.room_map)
        self.assertIn('user1', self.window.rooms['room1'])
        self.assertIn('user1', [user.name for user in self.window.room_map['room1']])


if __name__ == "__main__":
    unittest.main()
