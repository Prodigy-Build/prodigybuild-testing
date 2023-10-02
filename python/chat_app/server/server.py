def test_user_map():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    name = "User1"
    user_map = UserMap(sock, name)
    assert user_map.sock == sock
    assert user_map.name == name

def test_server_window():
    app = QApplication(sys.argv)
    window = ServerWindow()
    
    assert window.host == "127.0.0.1"
    assert window.port == 1100
    assert window.clients == 0
    assert window.STATE is True
    assert window.outputs == []
    assert window.rooms == {}
    assert window.room_map == {}
    assert window.client_map == {}
    assert window.socket_list == []
    assert window.commands == ["-create", "-join", "-leave"]
    assert window.RECV_BUFFER == 4096

def test_timed():
    # Assuming server starts at 12:00:00
    assert timed() == "12:00:00"

def test_formatResult():
    color = "blue"
    text = "Setting up server !"
    assert formatResult(color, text) == '<font color="blue">[12:00:00] * Setting up server !</font>'

def test_kill_proc_tree():
    pid = os.getpid()
    assert kill_proc_tree(pid) is None

def test_send():
    channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    msg = "Hello, world!"
    send(channel, msg)

def test_receive():
    channel = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    data = receive(channel)
    assert data == "Hello, world!"

def test_join_room():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    data = "-join room1"
    join_room(sock, data)

def test_leave_room():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    user_name = "User1"
    room = "room1"
    leave_room(sock, user_name, room)

def test_create_room():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    data = "-create room1"
    create_room(sock, data)

def test_setupServer():
    window = ServerWindow()
    window.setupServer()
    assert window.pushButton.isEnabled() is False

def test_handle_socket():
    thread_event = Event()
    handle_socket(thread_event)

def test_close_server():
    close_server()

if __name__ == '__main__':
    test_user_map()
    test_server_window()
    test_timed()
    test_formatResult()
    test_kill_proc_tree()
    test_send()
    test_receive()
    test_join_room()
    test_leave_room()
    test_create_room()
    test_setupServer()
    test_handle_socket()
    test_close_server()