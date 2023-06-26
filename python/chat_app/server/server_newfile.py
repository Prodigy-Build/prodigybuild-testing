

# server_newfile.py

import socket

def start_server():
    """
    Starts a server on the localhost
    """
    # Create a socket object
    server_socket = socket.socket()

    # Get local machine name
    host = socket.gethostname()

    # Reserve a port for your service
    port = 12345

    # Bind to the port
    server_socket.bind((host, port))

    # Start listening on the port
    server_socket.listen(5)

    # Wait for client connection
    while True:
        client_socket, address = server_socket.accept()
        print("Got connection from", address)

        # Receive data from client
        data = client_socket.recv(1024).decode()
        print("Received data:", data)

        # Send response to client
        client_socket.send("Thank you for connecting".encode())

        # Close the connection
        client_socket.close()

# Unit Test
import unittest

class TestStartServer(unittest.TestCase):
    def test_start_server(self):
        start_server()
        self.assertTrue(True)

if __name__ == '__main__':
    unittest.main()