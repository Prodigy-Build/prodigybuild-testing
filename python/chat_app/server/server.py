def test_UserMap():
    sock = socket.socket()
    user_map = UserMap(sock, "user1")
    assert user_map.sock == sock
    assert user_map.name == "user1"


def test_formatResult():
    result = formatResult(color="black", text="test message")
    expected_result = '<font color="black">[{0}] * {1}</font>'.format(timed(), "test message")
    assert result == expected_result


def test_send_encrypted():
    def send(channel, *msg):
        return True

    to_who = socket.socket()
    message = "test message"
    name = "user1"
    send_encrypted(to_who, message, name)
    assert send(to_who, "test message")


def test_join_room():
    sock = socket.socket()
    data = "-join hacking"
    join_room(sock, data)
    assert room_map["hacking"] == [UserMap(sock, "user1")]
    assert rooms["hacking"] == ["user1"]


def test_leave_room():
    sock = socket.socket()
    user_name = "user1"
    room = "hacking"
    leave_room(sock, user_name, room)
    assert rooms[room] == []
    assert room_map[room] == []


def test_create_room():
    sock = socket.socket()
    data = "-create hacking"
    create_room(sock, data)
    assert room_map["hacking"] == [UserMap(sock, "user1")]
    assert rooms["hacking"] == ["user1"]