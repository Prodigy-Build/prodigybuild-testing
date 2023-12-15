#!/usr/bin/env python
# -*- coding:utf-8 -*-

import unittest
import server as server
from threading import Thread



def test_send():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((localhost, 1100))
    server.send(sock,"Hello World")
    data = server.receive(sock)
    assert data == 'Hello World'

def test_receive():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((localhost, 1100))
    server.send(sock,"Hello World")
    data = server.receive(sock)
    assert data == 'Hello World'

def test_create_room():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((localhost, 1100))
    server.create_room(sock,'-create chatroom')
    data = server.receive(sock)
    assert data == "New room #chatroom is avaiable now."

def test_leave_room():
    sock1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock1.connect((localhost, 1100))
    sock2.connect((localhost, 1100))
    server.create_room(sock1,'-create chatroom')
    server.join_room(sock2,'-join chatroom')
    server.leave_room(sock2,'John', 'chatroom')
    data = server.receive(sock1)
    assert data == 'User John left the room'

def test_join_room():
    sock1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock1.connect((localhost, 1100))
    sock2.connect((localhost, 1100))
    server.create_room(sock1,'-create chatroom')
    server.join_room(sock2,'-join chatroom')
    data = server.receive(sock2)
    assert data == 'User John joined to the room'

def test_get_just_name():
    test_sock= "test"
    result = server.get_just_name(test_sock)
    assert result == server.client_map[test_sock][1]

def test_get_address():
    test_sock= "test"
    result = server.get_address(test_sock)
    assert result == server.client_map[test_sock][0]



class TestCases(unittest.TestCase):

    def test_send(self):
        result = test_send()
        self.assertEqual(result, )
    
    def test_receive(self):
        result = test_receive()
        self.assertEqual(result, )
    
    def test_create_room(self):
        result = test_create_room()
        self.assertEqual(result, )
    
    def test_leave_room(self):
        result = test_leave_room()
        self.assertEqual(result, )

    def test_join_room(self):
        result = test_join_room()
        self.assertEqual(result, )
    
    def test_get_just_name(self):
        result = test_get_just_name()
        self.assertEqual(result, )
    
    def test_get_address(self):
        result = test_get_address()
        self.assertEqual(result, )
    

unittest.main()