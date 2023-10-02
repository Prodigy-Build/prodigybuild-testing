import unittest
from unittest import mock

class TestServer(unittest.TestCase):
    def test_timed(self):
        result = timed()
        expected = "<expected value>"
        self.assertEqual(result, expected)

    def test_formatResult(self):
        result = formatResult(color="<color>", text="<text>")
        expected = "<expected value>"
        self.assertEqual(result, expected)

    def test_send_encrypted(self):
        with mock.patch("<module>.send") as mock_send:
            send_encrypted("<to_who>", "<message>", "<name>")
        mock_send.assert_called_once_with("<to_who>", "<encrypted_message>")

    def test_updateTableWidget(self):
        result = updateTableWidget(True, "<args>")
        expected = "<expected value>"
        self.assertEqual(result, expected)

    def test_join_room(self):
        with mock.patch("<module>.send") as mock_send:
            join_room("<sock>", "<data>")
        mock_send.assert_called_once_with("<user>", "<message>")

    def test_leave_room(self):
        with mock.patch("<module>.send") as mock_send:
            leave_room("<sock>", "<user_name>", "<room>")
        mock_send.assert_called_once_with("<sock>", "<message>")

    def test_create_room(self):
        with mock.patch("<module>.send") as mock_send:
            create_room("<sock>", "<data>")
        mock_send.assert_called_once_with("<sock>", "<message>")

    def test_setupServer(self):
        with mock.patch("<module>.socket.socket") as mock_socket:
            setupServer()
        mock_socket.assert_called_once_with(socket.AF_INET, socket.SOCK_STREAM)

    def test_handle_socket(self):
        with mock.patch("<module>.socket.socket") as mock_socket:
            handle_socket("<thread_event>")
        mock_socket.assert_called_once_with(socket.AF_INET, socket.SOCK_STREAM)

    def test_close_server(self):
        with mock.patch("<module>.thread_event.set") as mock_set:
            with mock.patch("<module>.socket.socket") as mock_socket:
                close_server()
        mock_set.assert_called_once()
        mock_socket.shutdown.assert_called_once_with(SHUT_RDWR)
        mock_socket.close.assert_called_once()

if __name__ == "__main__":
    unittest.main()