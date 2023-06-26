

Test.py

import unittest
from server_newfile import send_message

class TestSendMessage(unittest.TestCase):
    def test_send_message(self):
        message = "Hello World!"
        self.assertEqual(send_message(message), message)

if __name__ == '__main__':
    unittest.main()

