import unittest

class TestServerMethods(unittest.TestCase):

    def setUp(self):
        self.server = ServerWindow()

    def test_timed(self):
        self.assertIsInstance(timed(), str)

    def test_formatResult(self):
        result = formatResult("#000000", "Test")
        self.assertTrue(result.startswith("<font"))

    def test_send(self):
        self.assertRaises(TypeError, lambda: send(None, "Test"))

    def test_receive(self):
        self.assertRaises(TypeError, lambda: receive(None))

    def test_join_room(self):
        socket = None
        data = "Test"
        self.assertEqual(self.server.join_room(socket, data), None)

    def test_leave_room(self):
        socket = None
        username = "Test"
        room = "Test"
        self.assertEqual(self.server.leave_room(socket, username, room), None)

    def test_create_room(self):
        socket = None
        data = "Test"
        self.assertEqual(self.server.create_room(socket, data), None)

if __name__ == '__main__':
    unittest.main()