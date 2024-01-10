import unittest
from unittest.mock import patch, Mock
import server

class TestServer(unittest.TestCase):
    def test_formatResult(self):
        self.assertEqual(server.formatResult("black", "testing formatResult"), '<font color="black">[{}] * testing formatResult</font>'.format(server.timed()))

    def test_timed(self):
        pattern = r"\d{2}:\d{2}:\d{2}"
        self.assertRegex(server.timed(), pattern)

    def test_get_just_name(self):
        server_obj = setupServerMock()
        mock_client = Mock()
        server_obj.client_map = {mock_client: ["address", "client_name", "pubkey"]}
        self.assertEqual(server_obj.get_just_name(mock_client), "client_name")

    def test_get_address(self):
        server_obj = setupServerMock()
        mock_client = Mock()
        server_obj.client_map = {mock_client: ["address", "client_name", "pubkey"]}
        self.assertEqual(server_obj.get_address(mock_client), "address")

    def setupServerMock():
        host = "127.0.0.1"
        port = 11000
        server_obj = server.ServerWindow(host, port)
        return server_obj

if __name__ == '__main__':
    unittest.main()