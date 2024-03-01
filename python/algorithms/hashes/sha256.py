import hashlib
import unittest

class SHA256HashTest(unittest.TestCase):
    """
    Test class for the SHA256 class. Inherits the TestCase class from unittest
    """

    def test_match_hashes(self) -> None:
        msg = bytes("Test String", "utf-8")
        self.assertEqual(SHA256(msg).hash, hashlib.sha256(msg).hexdigest())