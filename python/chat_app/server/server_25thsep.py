# Create or update the file server_25thsep.py

# server_25thsep.py
```python
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

# Existing functions and classes here...

class TestServerMethods(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_timed(self):
        self.assertNotEqual(timed(), "")
        
    def test_formatResult(self):
        result = formatResult("red", "Hello")
        self.assertTrue("font color=\"red\"" in result and "Hello" in result)

    def test_kill_proc_tree(self):
        pass 

    def test_send(self):
        pass

    def test_receive(self):
        pass

    def test_UserMap(self):
        pass

    def test_ServerWindow(self):
        pass
    
    def tearDown(self):
        pass

if __name__ == '__main__':
    unittest.main()
```
