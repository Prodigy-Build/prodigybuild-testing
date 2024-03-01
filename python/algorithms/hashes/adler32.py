def test_adler32():
    assert adler32('Algorithms') == 363791387
    assert adler32('go adler em all') == 708642122