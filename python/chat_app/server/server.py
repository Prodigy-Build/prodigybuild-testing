import unittest

class TestServer(unittest.TestCase):
    
    def setUp(self):
        self.server = ServerWindow()
    
    def tearDown(self):
        self.server = None
    
    def test_get_just_name(self):
        client = 1
        expected_name = "Test"
        self.server.client_map[client] = (None, expected_name, None)
        result = self.server.get_just_name(client)
        self.assertEqual(result, expected_name)

    def test_get_address(self):
        client = 1
        expected_address = ("127.0.0.1", 1100)
        self.server.client_map[client] = (expected_address, None, None)
        result = self.server.get_address(client)
        self.assertEqual(result, expected_address)
    
    def test_updateTableWidget_insert(self):
        update = True
        args = ["Test", "127.0.0.1", 1100]
        expected_row_count = self.server.tableWidget.rowCount() + 1
        self.server.updateTableWidget(update, *args)
        result_row_count = self.server.tableWidget.rowCount()
        self.assertEqual(result_row_count, expected_row_count)
    
    def test_updateTableWidget_remove(self):
        update = False
        args = ["Test", "127.0.0.1", 1100]
        self.server.tableWidget.insertRow(0)
        for i in range(3):
            self.server.tableWidget.setItem(0, i, QTableWidgetItem(str(args[i])))
        expected_row_count = self.server.tableWidget.rowCount() - 1
        self.server.updateTableWidget(update, *args)
        result_row_count = self.server.tableWidget.rowCount()
        self.assertEqual(result_row_count, expected_row_count)
    
    def test_join_room_existing_room(self):
        sock = 1
        room_name = "TestRoom"
        user_name = "TestUser"
        self.server.rooms[room_name] = []
        self.server.room_map[room_name] = []
        self.server.room_map[room_name].append(UserMap(sock, user_name))
        expected_rooms = {room_name: [user_name]}
        self.server.join_room(sock, f"-join {room_name}")
        result_rooms = self.server.rooms
        self.assertEqual(result_rooms, expected_rooms)
    
    def test_join_room_non_existing_room(self):
        sock = 1
        room_name = "TestRoom"
        user_name = "TestUser"
        expected_rooms = {}
        self.server.join_room(sock, f"-join {room_name}")
        result_rooms = self.server.rooms
        self.assertEqual(result_rooms, expected_rooms)
    
    def test_leave_room(self):
        sock = 1
        user_name = "TestUser"
        room_name = "TestRoom"
        host = ("127.0.0.1", 1100)
        self.server.rooms[room_name] = [user_name]
        self.server.room_map[room_name] = [UserMap(sock, user_name)]
        expected_rooms = {}
        expected_output = [
            formatResult(color="#f99a34",text=f"User {user_name}@{host[0]}:{host[1]} left #{room_name} room")
        ]
        self.server.leave_room(sock, user_name, room_name)
        result_rooms = self.server.rooms
        result_output = self.server.textEdit.toPlainText().split("\n")
        self.assertEqual(result_rooms, expected_rooms)
        self.assertEqual(result_output, expected_output)
    
    def test_create_room_existing_room(self):
        sock = 1
        room_name = "TestRoom"
        expected_rooms = {}
        self.server.rooms[room_name] = []
        self.server.room_map[room_name] = []
        self.server.create_room(sock, f"-create {room_name}")
        result_rooms = self.server.rooms
        self.assertEqual(result_rooms, expected_rooms)
    
    def test_create_room_non_existing_room(self):
        sock = 1
        room_name = "TestRoom"
        user = "TestUser"
        host = ("127.0.0.1", 1100)
        expected_rooms = {room_name: [user]}
        expected_output = [
            formatResult(color="#f99a34",text=f"User {user}@{host[0]}:{host[1]} created #{room_name} room")
        ]
        self.server.create_room(sock, f"-create {room_name}")
        result_rooms = self.server.rooms
        result_output = self.server.textEdit.toPlainText().split("\n")
        self.assertEqual(result_rooms, expected_rooms)
        self.assertEqual(result_output, expected_output)

if __name__ == '__main__':
    unittest.main()