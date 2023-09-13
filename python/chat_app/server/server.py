#!/usr/bin/env python
# -*- coding:utf-8 -*- 

import unittest

class TestServerWindow(unittest.TestCase):

    def setUp(self):
        self.window = ServerWindow()

    def test_get_just_name(self):
        mock_socket = MagicMock()
        self.window.client_map[mock_socket] = ("localhost:8080", "test_name")
        self.assertEqual(self.window.get_just_name(mock_socket), "test_name")

    def test_get_address(self):
        mock_socket = MagicMock()
        self.window.client_map[mock_socket] = ("localhost:8080", "test_name")
        self.assertEqual(self.window.get_address(mock_socket), "localhost:8080")

    def test_send_encrypted(self):
        mock_socket = MagicMock()
        self.window.client_map[mock_socket] = ("localhost:8080", "test_name")

        with patch('server.server.send') as mock_send:
            self.window.send_encrypted(mock_socket, "test message", "test_name")
            mock_send.assert_called_once()

    def tearDown(self):
        self.window = None

if __name__ == '__main__':
    unittest.main()