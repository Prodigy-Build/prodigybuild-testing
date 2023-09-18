#!/usr/bin/env python
# -*- coding:utf-8 -*- 

import os
import sys
import time
import json
import signal
import socket
import unittest
import psutil
import select
import pickle
import struct

from threading import *
from PyQt5 import uic
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtTest import QTest
from PyQt5.QtWidgets import *
from time import strftime,localtime

from Crypto.Hash import SHA
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_PSS

from server import ServerWindow

class TestServer(unittest.TestCase):
    def setUp(self):
        self.app = QApplication(sys.argv)
        self.server = ServerWindow()

    def test_defaults(self):
        self.assertEqual(self.server.host, "127.0.0.1")
        self.assertEqual(self.server.port, 1100)

    def test_setUpServer(self):
        with self.assertRaises(Exception):
            self.server.setupServer()
        self.assertEqual(self.server.STATE, True)

    def test_close_server(self):
        self.server.STATE = False
        self.assertEqual(self.server.STATE, False)


if __name__ == "__main__":
    unittest.main()
