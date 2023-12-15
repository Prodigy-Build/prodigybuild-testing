```
import unittest

class TestServerWindow(unittest.TestCase):

    def test_get_just_name(self):
        # Test case 1
        client = "client1"
        expected_output = "client1"
        self.assertEqual(window.get_just_name(client), expected_output)

        # Test case 2
        client = "client2"
        expected_output = "client2"
        self.assertEqual(window.get_just_name(client), expected_output)

    def test_get_address(self):
        # Test case 1
        client = "client1"
        expected_output = "address1"
        self.assertEqual(window.get_address(client), expected_output)

        # Test case 2
        client = "client2"
        expected_output = "address2"
        self.assertEqual(window.get_address(client), expected_output)

    def test_send_encrypted(self):
        # Test case 1
        to_who = "client1"
        message = "Hello"
        name = "client2"
        expected_output = "Encrypted message sent"
        self.assertEqual(window.send_encrypted(to_who, message, name), expected_output)

        # Test case 2
        to_who = "client2"
        message = "Hi"
        name = "client1"
        expected_output = "Encrypted message sent"
        self.assertEqual(window.send_encrypted(to_who, message, name), expected_output)

    def test_updateTableWidget(self):
        # Test case 1
        update = True
        args = ("client1", "address1", 1100)
        expected_output = "Table widget updated"
        self.assertEqual(window.updateTableWidget(update, *args), expected_output)

        # Test case 2
        update = False
        args = ("client2", "address2", 1200)
        expected_output = "Table widget updated"
        self.assertEqual(window.updateTableWidget(update, *args), expected_output)

if __name__ == "__main__":
    unittest.main()
```
