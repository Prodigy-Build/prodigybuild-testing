import unittest
import os
import sys

class TestServer(unittest.TestCase):

    def setUp(self):
        self.serverWindow = ServerWindow()
        self.serverWindow.setupServer()

    def tearDown(self):
        self.serverWindow.close_server()

    def test_join_room(self):
        self.serverWindow.join_room(sock, data)
        room_name = data.split()[1]
        self.assertIn(room_name, self.serverWindow.rooms)
        self.assertIn(user_name, self.serverWindow.rooms[room_name])

    def test_leave_room(self):
        self.serverWindow.leave_room(sock, user_name, room_name)
        self.assertNotIn(user_name, self.serverWindow.rooms[room_name])
        self.assertEqual(len(self.serverWindow.room_map[room_name]), 0)

    def test_create_room(self):
        self.serverWindow.create_room(sock, data)
        room_name = data.split()[1]
        self.assertIn(room_name, self.serverWindow.rooms)

if __name__ == '__main__':
    unittest.main()