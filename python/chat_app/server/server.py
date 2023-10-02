import unittest

class TestServer(unittest.TestCase):
	def test_timed(self):
		expected = "15:30:45"
		result = timed()
		self.assertEqual(expected, result)

	def test_formatResult(self):
		expected = '<font color="black">[15:30:45] * Hello</font>'
		result = formatResult("black", "Hello")
		self.assertEqual(expected, result)

	def test_kill_proc_tree(self):
		kill_proc_tree(12345)

	def test_send(self):
		pass

	def test_receive(self):
		pass

	def test_UserMap(self):
		sock = socket.socket()
		name = "John"
		user_map = UserMap(sock, name)
		self.assertEqual(sock, user_map.sock)
		self.assertEqual(name, user_map.name)

	def test_ServerWindow(self):
		host = "127.0.0.1"
		port = 1100
		server_window = ServerWindow(host, port)
		self.assertEqual(host, server_window.host)
		self.assertEqual(port, server_window.port)

	def test_get_just_name(self):
		client = socket.socket()
		expected = "John"
		client_map = {client: ("127.0.0.1", "John", RSA.importKey(os.urandom(16)))}
		server_window = ServerWindow()
		server_window.client_map = client_map
		result = server_window.get_just_name(client)
		self.assertEqual(expected, result)

	def test_get_address(self):
		client = socket.socket()
		expected = "127.0.0.1"
		client_map = {client: ("127.0.0.1", "John", RSA.importKey(os.urandom(16)))}
		server_window = ServerWindow()
		server_window.client_map = client_map
		result = server_window.get_address(client)
		self.assertEqual(expected, result)

	def test_send_encrypted(self):
		pass

	def test_updateTableWidget(self):
		pass

	def test_join_room(self):
		pass

	def test_leave_room(self):
		pass

	def test_create_room(self):
		pass

	def test_setupServer(self):
		pass

	def test_handle_socket(self):
		pass

	def test_close_server(self):
		pass

if __name__ == '__main__':
	unittest.main()