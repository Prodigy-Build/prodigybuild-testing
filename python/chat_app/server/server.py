import unittest

class TestServer(unittest.TestCase):
    def test_timed(self):
        self.assertEqual(timed(), strftime("%H:%M:%S",localtime()))
    
    def test_formatResult(self):
        self.assertEqual(formatResult(color="black",text=""), '<font color="black">[{0}] * {1}</font>'.format(timed(),""))
    
    def test_send(self):
        # Assume channel is a socket object
        send(channel, "message")

    def test_receive(self):
        # Assume channel is a socket object
        receive(channel)

if __name__ == '__main__':
    unittest.main()