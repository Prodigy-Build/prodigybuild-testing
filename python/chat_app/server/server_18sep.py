#!/usr/bin/env python
# -*- coding:utf-8 -*- 

import os
import sys
import unittest
import socket
import threading

from python.chat_app.server.server import ServerWindow

class TestServer(unittest.TestCase):

    def setUp(self):
        self.ServerWindow = ServerWindow()

    def testInitialValues(self):
        self.assertEqual(self.ServerWindow.host, "127.0.0.1")
        self.assertEqual(self.ServerWindow.port, 1100)
        self.assertEqual(self.ServerWindow.clients, 0)
        self.assertTrue(self.ServerWindow.STATE)
        self.assertEqual(self.ServerWindow.outputs, [])
        self.assertEqual(self.ServerWindow.rooms, {})
        self.assertEqual(self.ServerWindow.room_map, {})
        self.assertEqual(self.ServerWindow.client_map, {})
        self.assertEqual(self.ServerWindow.socket_list, [])
        self.assertEqual(self.ServerWindow.commands, ["-create","-join","-leave"])
        self.assertEqual(self.ServerWindow.RECV_BUFFER, 4096)

    def testSetupServer(self):
        # because setupServer method has the infinite loop, we use threading for testing
        self.ServerWindow.thread_event = threading.Event()
        threading.Thread(target=self.ServerWindow.setupServer, args=()).start()
        self.assertIsInstance(self.ServerWindow.server, socket.socket)
        self.assertIn(self.ServerWindow.server, self.ServerWindow.socket_list)

    def testCloseServer(self):
        # Close the server and test whether it's been removed from the list
        self.ServerWindow.close_server()
        self.assertNotIn(self.ServerWindow.server, self.ServerWindow.socket_list)
        
    def tearDown(self):
        del self.ServerWindow

if __name__ == '__main__':
    unittest.main()