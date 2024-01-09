import unittest
from unittest.mock import patch, MagicMock
from PyQt5.QtTest import QTest
from PyQt5.QtCore import Qt

class TestServerWindow(unittest.TestCase):
    def setUp(self):
        self.patcher1 = patch('__main__.app', create=True)
        self.patcher2 = patch('__main__.ServerWindow.setupServer')
        self.patcher3 = patch('__main__.ServerWindow.close_server')
        self.MockApp = self.patcher1.start()
        self.MockSetupServer = self.patcher2.start()
        self.MockCloseServer = self.patcher3.start()
        self.test_app = self.MockApp()
        self.main_window = ServerWindow()         
        self.main_window.show()

    def tearDown(self):
        self.patcher1.stop()
        self.patcher2.stop()
        self.patcher3.stop()
        self.main_window.close_server() 

    def test_setupServer_is_triggered_when_button_is_clicked(self):
        QTest.mouseClick(self.main_window.pushButton, Qt.LeftButton)
        self.MockSetupServer.assert_called_once()

    def test_close_server_is_triggered_when_button_is_clicked(self):
        QTest.mouseClick(self.main_window.pushButton_2, Qt.LeftButton)
        self.MockCloseServer.assert_called_once()

if __name__ == "__main__":
    unittest.main()