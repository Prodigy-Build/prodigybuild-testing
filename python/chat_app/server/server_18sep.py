#!/usr/bin/env python
# -*- coding:utf-8 -*- 

import os
import sys
import time
import json
import signal
import socket
import psutil
import select
import pickle
import struct
import unittest

from threading import *
from PyQt5 import uic
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from time import strftime,localtime

from Crypto.Hash import SHA
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_PSS

from server import ServerWindow

class TestServer(unittest.TestCase):

    def setUp(self):
        self.server = ServerWindow()

    def test_get_just_name(self):
        socket = 1
        self.server.client_map[socket] = [1, "test name", 1]
        self.assertEqual(self.server.get_just_name(socket), "test name")

    def test_updateTableWidget(self):
        self.server.updateTableWidget(True, "test name", "test address", 1100)
        self.assertEqual(self.server.tableWidget.item(0, 0).text(), "test name")
        self.assertEqual(self.server.tableWidget.item(0, 1).text(), "test address")
        self.assertEqual(self.server.tableWidget.item(0, 2).text(), "1100")

if __name__ == '__main__':
    unittest.main()