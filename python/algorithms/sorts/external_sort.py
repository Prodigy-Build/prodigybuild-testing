import unittest
from unittest.mock import patch
import os
import tempfile

class TestExternalSort(unittest.TestCase):

    def setUp(self):
        self.temp_file = tempfile.NamedTemporaryFile(delete=False)

    def tearDown(self):
        os.remove(self.temp_file.name)

    def test_file_splitter(self):
        splitter = FileSplitter(self.temp_file.name)
        splitter.write_block('test', 0)
        block_filenames = splitter.get_block_filenames()
        self.assertEqual(block_filenames[0], 'block_0.dat')
        with open(block_filenames[0], 'r') as f:
            self.assertEqual(f.read(), 'test')
        splitter.cleanup()

    def test_nway_merge(self):
        merger = NWayMerge()
        min_index = merger.select(['b', 'c', 'a'])
        self.assertEqual(min_index, 2)

    def test_files_array(self):
        f = open(self.temp_file.name, 'w')
        f.write("test")
        f.close()
        files = [open(self.temp_file.name, 'r')]
        files_array = FilesArray(files)
        self.assertTrue(files_array.refresh())
        files_array.unshift(0)
        self.assertFalse(files_array.refresh())

    def test_file_merger(self):
        f = open(self.temp_file.name, 'w')
        f.write("b\na\n")
        f.close()
        files = [self.temp_file.name]
        file_merger = FileMerger(NWayMerge())
        outfile_name = tempfile.mktemp()
        file_merger.merge(files, outfile_name, 100)
        with open(outfile_name, "r") as f:
            self.assertEqual(f.read(), "a\nb\n")
        os.remove(outfile_name)

    def test_external_sort(self):
        esort = ExternalSort(10)
        num_blocks = esort.get_number_blocks(self.temp_file.name, 10)
        self.assertEqual(num_blocks, 1)

    @patch('argparse.ArgumentParser.parse_args')
    def test_main(self, mock_args):
        mock_args.return_value.mem = '100M'
        mock_args.return_value.filename = [self.temp_file.name]
        main()


if __name__ == '__main__':
    unittest.main()