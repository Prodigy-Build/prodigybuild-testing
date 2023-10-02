def update_server_py_file(file_path):
    with open(file_path, 'r') as file:
        file_contents = file.read()

        file_contents = file_contents.replace('#!/usr/bin/env python\n# -*- coding:utf-8 -*-',
                                              '#!/usr/bin/env python\n# -*- coding:utf-8 -*-\n\n'
                                              'import unittest\n')
        file_contents += '\n\nclass TestServer(unittest.TestCase):\n'
        file_contents += '\n    def setUp(self):\n        pass\n'
        file_contents += '\n    def tearDown(self):\n        pass\n\n'

        file_contents += '\nif __name__ == "__main__":\n    unittest.main()'

    with open(file_path, 'w') as file:
        file.write(file_contents)

update_server_py_file("python/chat_app/server/server.py")