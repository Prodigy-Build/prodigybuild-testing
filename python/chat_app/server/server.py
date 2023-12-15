#!/usr/bin/env python
# -*- coding:utf-8 -*-

import unittest
import sys


class TestServerWindow(unittest.TestCase):
    
    def test_setupServer(self):
        server = ServerWindow(host="127.0.0.1", port=1100)
        server.setupServer()
        self.assertEqual(server.port, 1100)
        self.assertEqual(server.host, "127.0.0.1")
        self.assertEqual(server.pushButton.isEnabled(), False)

    def test_leave_room(self):
        server = ServerWindow()
        sock = object()
        server.client_map[sock] = ["host", "user"]
        server.rooms["room"] = ["user"]
        server.room_map["room"] = [sock]
        server.leave_room(sock, "user", "room")
        self.assertEqual(server.rooms["room"], [])
        self.assertEqual(server.room_map["room"], [])
        
    def test_create_room(self):
        server = ServerWindow()
        sock = object()
        server.rooms["room"] = ["anotherUser"]
        server.room_map["room"] = [sock]
        server.create_room(sock, "-create newroom")
        self.assertEqual(server.rooms["room"], ["anotherUser"])
        self.assertEqual(server.room_map["room"], [sock])
        self.assertEqual(server.rooms["newroom"], ["user"])
        self.assertEqual(server.room_map["newroom"], [sock])
        
    def test_join_room(self):
        server = ServerWindow()
        sock = object()
        server.rooms["room"] = ["user"]
        server.room_map["room"] = [sock]
        server.join_room(sock, "-join room")
        self.assertEqual(server.rooms["room"], ["user"])
        self.assertEqual(server.room_map["room"], [sock])
        self.assertEqual(server.rooms["room2"], ["user"])
        self.assertEqual(server.room_map["room2"], [sock])

        
if __name__ == '__main__':
    unittest.main()