```python
import unittest
from unittest.mock import patch, MagicMock

from server import ServerWindow, UserMap, send, receive, formatResult, kill_proc_tree

class TestServer(unittest.TestCase):
    def setUp(self):
        self.server = ServerWindow()

    def test_send(self):
        test_channel = MagicMock()
        test_channel.send.side_effect = [None, None]
        send(test_channel, "test_message")
        test_channel.send.assert_any_call(struct.pack("L", socket.htonl(len(pickle.dumps(("test_message",))))))
        test_channel.send.assert_any_call(pickle.dumps(("test_message",)))

    def test_receive(self):
        test_channel = MagicMock()
        test_channel.recv.side_effect = [struct.pack("L", socket.htonl(len(pickle.dumps(("test_message",))))),
                                         pickle.dumps(("test_message",))]
        self.assertEqual(receive(test_channel), "test_message")

    def test_formatResult(self):
        self.assertEqual(formatResult("red", "Test"), '<font color="red">[{}] * Test</font>'.format(timed()))

    def test_kill_proc_tree(self):
        with patch('os.getpid', return_value=123), \
             patch('psutil.Process', return_value=MagicMock()), \
             patch.object(psutil.Process, "kill"):
            kill_proc_tree(123, True)

    def test_create_room(self):
        self.server.create_room(self.server, "-create test_room")
        self.assertTrue("test_room" in self.server.rooms.keys())

    def test_join_room(self):
        self.server.create_room(self.server, "-create test_room")
        self.server.join_room(self.server, "-join test_room")
        self.assertIn(self.server.get_just_name(self.server), self.server.rooms["test_room"])

    def test_leave_room(self):
        self.server.create_room(self.server, "-create test_room")
        self.server.join_room(self.server, "-join test_room")
        self.server.leave_room(self.server, self.server.get_just_name(self.server), "test_room")
        self.assertNotIn(self.server.get_just_name(self.server), self.server.rooms["test_room"])

if __name__ == '__main__':
    unittest.main()
```