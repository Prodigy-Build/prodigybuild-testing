import unittest

class TestServerWindow(unittest.TestCase):
    def test_get_just_name(self):
        # Test case for the get_just_name method
        server = ServerWindow()
        server.client_map = {client1: ("127.0.0.1", "user1", pubkey1), client2: ("127.0.0.1", "user2", pubkey2)}
        self.assertEqual(server.get_just_name(client1), "user1")
        self.assertEqual(server.get_just_name(client2), "user2")

    def test_get_address(self):
        # Test case for the get_address method
        server = ServerWindow()
        server.client_map = {client1: ("127.0.0.1", "user1", pubkey1), client2: ("127.0.0.1", "user2", pubkey2)}
        self.assertEqual(server.get_address(client1), ("127.0.0.1", "user1"))
        self.assertEqual(server.get_address(client2), ("127.0.0.1", "user2"))

    def test_send_encrypted(self):
        # Test case for the send_encrypted method
        server = ServerWindow()
        server.client_map = {client1: ("127.0.0.1", "user1", pubkey1), client2: ("127.0.0.1", "user2", pubkey2)}
        server.send_encrypted(client1, "message", "user2")
        # Assert that the encrypted message is sent to the correct client in the client_map

    def test_updateTableWidget(self):
        # Test case for the updateTableWidget method
        server = ServerWindow()
        server.tableWidget = QTableWidget()
        server.updateTableWidget(True, "user1", "127.0.0.1", 1100)
        # Assert that a new row is inserted into the tableWidget with the provided values
        server.updateTableWidget(False, "user1", "127.0.0.1", 1100)
        # Assert that the row with the provided values is removed from the tableWidget

    def test_join_room(self):
        # Test case for the join_room method
        server = ServerWindow()
        server.rooms = {"room1": ["user1"], "room2": ["user2"]}
        server.room_map = {"room1": [(client1, "user1")], "room2": [(client2, "user2")]}
        server.textEdit = QTextEdit()
        server.join_room(client1, "-join room3")
        # Assert that "No such that room !!!" is sent to client1
        server.join_room(client1, "-join room1")
        # Assert that user1 is added to the room1 list in rooms and room_map
        # Assert that the appropriate messages are sent to the clients in room1

    def test_leave_room(self):
        # Test case for the leave_room method
        server = ServerWindow()
        server.rooms = {"room1": ["user1", "user2"], "room2": ["user3"]}
        server.room_map = {"room1": [(client1, "user1"), (client2, "user2")], "room2": [(client3, "user3")]}
        server.textEdit = QTextEdit()
        server.leave_room(client1, "user1", "room1")
        # Assert that user1 is removed from the room1 list in rooms and room_map
        # Assert that the appropriate messages are sent to the clients in room1

    def test_create_room(self):
        # Test case for the create_room method
        server = ServerWindow()
        server.rooms = {"room1": ["user1"], "room2": ["user2"]}
        server.room_map = {"room1": [(client1, "user1")], "room2": [(client2, "user2")]}
        server.client_map = {client1: ("127.0.0.1", "user1", pubkey1), client2: ("127.0.0.1", "user2", pubkey2)}
        server.textEdit = QTextEdit()
        server.create_room(client1, "-create room3")
        # Assert that "New room #room3 is avaiable now." is sent to client2
        # Assert that room3 is added to the rooms dict and the room_map dict
        server.create_room(client1, "-create room2")
        # Assert that "That room is avaiable,you can join in." is sent to client1

    def test_handle_socket(self):
        # Test case for the handle_socket method
        pass

    def test_close_server(self):
        # Test case for the close_server method
        pass

if __name__ == '__main__':
    unittest.main()