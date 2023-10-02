import pytest

from server.server import *

def test_timed():
    assert isinstance(timed(), str)

def test_formatResult():
    assert isinstance(formatResult(), str)

def test_kill_proc_tree():
    pass

def test_send():
    pass

def test_receive():
    pass

def test_UserMap():
    pass

def test_ServerWindow():
    pass

def test_get_just_name():
    pass

def test_get_address():
    pass

def test_send_encrypted():
    pass

def test_updateTableWidget():
    pass

def test_join_room():
    pass

def test_leave_room():
    pass

def test_create_room():
    pass

def test_setupServer():
    pass

def test_handle_socket():
    pass

def test_close_server():
    pass