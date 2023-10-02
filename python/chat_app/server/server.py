import unittest
import sys
import os

import server

class ServerTestCase(unittest.TestCase):
    
    def setUp(self):
        self.server_window = server.ServerWindow()
    
    def tearDown(self):
        self.server_window = None
    
    def test_get_just_name(self):
        client = 1
        self.assertEqual(self.server_window.get_just_name(client), self.server_window.client_map[client][1])
    
    def test_get_address(self):
        client = 1
        self.assertEqual(self.server_window.get_address(client), self.server_window.client_map[client][0])
    
    def test_updateTableWidget(self):
        update = True
        args = ("name", "address", "port")
        self.server_window.updateTableWidget(update, *args)
        self.assertEqual(self.server_window.tableWidget.rowCount(), 1)
        
        update = False
        args = ("name", "address", "port")
        self.server_window.updateTableWidget(update, *args)
        self.assertEqual(self.server_window.tableWidget.rowCount(), 0)
    
    def test_join_room(self):
        sock = 1
        data = "-join python"
        self.server_window.join_room(sock, data)
        self.assertTrue("python" in self.server_window.rooms.keys())
    
    def test_leave_room(self):
        sock = 1
        user_name = "user1"
        room = "python"
        self.server_window.leave_room(sock, user_name, room)
        self.assertFalse(user_name in self.server_window.rooms[room])
    
    def test_create_room(self):
        sock = 1
        data = "-create python"
        self.server_window.create_room(sock, data)
        self.assertTrue("python" in self.server_window.rooms.keys())
    
    def test_send_encrypted(self):
        to_who = 1
        message = "Hello"
        name = "user1"
        self.server_window.send_encrypted(to_who, message, name)
        # check if message is sent successfully
    
    def test_setupServer(self):
        self.server_window.setupServer()
        self.assertEqual(self.server_window.pushButton.isEnabled(), False)
        # check further if setup is done successfully
    
    def test_handle_socket(self):
        self.server_window.setupServer()
        self.server_window.shutdown_server()
        # check if the handle socket is correctly implemented
    
    def test_close_server(self):
        self.server_window.setupServer()
        self.server_window.close_server()
        # check further if server is closed successfully
    
if __name__ == '__main__':
    unittest.main()