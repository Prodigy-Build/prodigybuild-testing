#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import unittest
from unittest.mock import MagicMock 
from server import ServerWindow

class ServerWindowTest(unittest.TestCase):
    
    def setUp(self):
        self.server_window = ServerWindow()

    def test_send(self):
        self.server_window.send = MagicMock()
        self.server_window.join_room(self.server_window, "msg")
        self.server_window.send.assert_called_once()

    def test_create_room(self):
        self.server_window.send = MagicMock()
        self.server_window.create_room(self.server_window, "msg")
        self.server_window.send.assert_called()

    def test_join_room(self):
        self.server_window.send = MagicMock()
        self.server_window.join_room(self.server_window, "msg")
        self.server_window.send.assert_called()

    def test_leave_room(self):
        self.server_window.send = MagicMock()
        self.server_window.leave_room(self.server_window, "msg")
        self.server_window.send.assert_called()

if __name__ == '__main__':
    unittest.main()