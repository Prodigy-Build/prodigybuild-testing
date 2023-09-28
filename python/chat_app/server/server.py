def test_user_map_creation():
   sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   name = "test_user"
   user_map = UserMap(sock, name)
   assert user_map.sock == sock
   assert user_map.name == name

def test_user_map_creation_invalid_socket():
   sock = "invalid_socket"
   name = "test_user"
   user_map = UserMap(sock, name)
   assert user_map.sock == None
   assert user_map.name == name

def test_server_window_creation():
   host = "127.0.0.1"
   port = 1100
   server_window = ServerWindow(host, port)
   assert server_window.host == host
   assert server_window.port == port
   assert server_window.clients == 0
   assert server_window.STATE == True
   assert server_window.outputs == []
   assert server_window.rooms == {}
   assert server_window.room_map == {}
   assert server_window.client_map == {}
   assert server_window.socket_list == []
   assert server_window.commands == ["-create","-join","-leave"]
   assert server_window.RECV_BUFFER == 4096

def test_get_just_name():
   sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   name = "test_user"
   server_window = ServerWindow()
   server_window.client_map = {sock: ('127.0.0.1', name, None)}
   assert server_window.get_just_name(sock) == name

def test_get_just_name_invalid_socket():
   sock = "invalid_socket"
   server_window = ServerWindow()
   server_window.client_map = {sock: ('127.0.0.1', 'test_user', None)}
   assert server_window.get_just_name(sock) == None

def test_get_address():
   sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   address = ('127.0.0.1', 1100)
   server_window = ServerWindow()
   server_window.client_map = {sock: (address, 'test_user', None)}
   assert server_window.get_address(sock) == address

def test_get_address_invalid_socket():
   sock = "invalid_socket"
   server_window = ServerWindow()
   server_window.client_map = {sock: (('127.0.0.1', 1100), 'test_user', None)}
   assert server_window.get_address(sock) == None

def test_send_encrypted():
   sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   message = "Test message"
   name = "test_user"
   server_window = ServerWindow()
   server_window.client_map = {sock: ('127.0.0.1', name, RSA.generate(2048))}
   server_window.send_encrypted(sock, message, name)

def test_update_table_widget():
   server_window = ServerWindow()
   server_window.updateTableWidget(True, "name", "127.0.0.1", 1100)
   server_window.updateTableWidget(False, "name", "127.0.0.1", 1100)

def test_join_room():
   sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   data = "-join room_name"
   server_window = ServerWindow()
   server_window.rooms = {"room_name": []}
   server_window.room_map = {"room_name": []}
   server_window.join_room(sock, data)

def test_leave_room():
   sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   user_name = "test_user"
   room = "room_name"
   server_window = ServerWindow()
   server_window.rooms = {room: [user_name]}
   server_window.room_map = {room: [UserMap(sock, user_name)]}
   server_window.leave_room(sock, user_name, room)
   assert user_name not in server_window.rooms[room]
   assert len(server_window.room_map[room]) == 0

def test_create_room():
   sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   data = "-create room_name"
   server_window = ServerWindow()
   server_window.create_room(sock, data)
   assert server_window.rooms["room_name"] == ["test_user"]
   assert server_window.room_map["room_name"][0].sock == sock
   assert server_window.room_map["room_name"][0].name == "test_user"

def test_setup_server():
   server_window = ServerWindow()
   server_window.setupServer()

def test_handle_socket():
   thread_event = Event()
   server_window = ServerWindow()
   server_window.handle_socket(thread_event)

def test_close_server():
   server_window = ServerWindow()
   server_window.close_server()

test_user_map_creation()
test_user_map_creation_invalid_socket()
test_server_window_creation()
test_get_just_name()
test_get_just_name_invalid_socket()
test_get_address()
test_get_address_invalid_socket()
test_send_encrypted()
test_update_table_widget()
test_join_room()
test_leave_room()
test_create_room()
test_setup_server()
test_handle_socket()
test_close_server()