import pytest
from pathlib import Path
import sys

def test_server_exists():
    assert Path("python/chat_app/server/server.py").is_file()

def test_server_run():
    pytest.skip("Running the server is not currently supported")