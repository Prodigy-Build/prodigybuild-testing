```python
# python/algorithms/data_structures/trie/trie.py

import unittest

class TrieNode:
    def __init__(self) -> None:
        self.nodes: dict[str, TrieNode] = {}  # Mapping from char to TrieNode
        self.is_leaf = False

    def insert_many(self, words: list[str]) -> None:
        """
        Inserts a list of words into the Trie
        :param words: list of string words
        :return: None
        """
        for word in words:
            self.insert(word)

    def insert(self, word: str) -> None:
        """
        Inserts a word into the Trie
        :param word: word to be inserted
        :return: None
        """
        curr = self
        for char in word:
            if char not in curr.nodes:
                curr.nodes[char] = TrieNode()
            curr = curr.nodes[char]
        curr.is_leaf = True

    def find(self, word: str) -> bool:
        """
        Tries to find word in a Trie
        :param word: word to look for
        :return: Returns True if word is found, False otherwise
        """
        curr = self
        for char in word:
            if char not in curr.nodes:
                return False
            curr = curr.nodes[char]
        return curr.is_leaf

    def delete(self, word: str) -> None:
        """
        Deletes a word in a Trie
        :param word: word to delete
        :return: None
        """

        def _delete(curr: TrieNode, word: str, index: int) -> bool:
            if index == len(word):
                # If word does not exist
                if not curr.is_leaf:
                    return False
                curr.is_leaf = False
                return len(curr.nodes) == 0
            char = word[index]
            char_node = curr.nodes.get(char)
            # If char not in current trie node
            if not char_node:
                return False
            # Flag to check if node can be deleted
            delete_curr = _delete(char_node, word, index + 1)
            if delete_curr:
                del curr.nodes[char]
                return len(curr.nodes) == 0
            return delete_curr


def print_words(node: TrieNode, word: str) -> None:
    """
    Prints all the words in a Trie
    :param node: root node of Trie
    :param word: Word variable should be empty at start
    :return: None
    """
    if node.is_leaf:
        print(word, end=" ")

    for key, value in node.nodes.items():
        print_words(value, word + key)


class TestTrie(unittest.TestCase):
    def setUp(self):
        self.words = "banana bananas bandana band apple all beast".split()
        self.root = TrieNode()
        self.root.insert_many(self.words)

    def test_find(self):
        self.assertTrue(all(self.root.find(word) for word in self.words))
        self.assertTrue(self.root.find("banana"))
        self.assertFalse(self.root.find("bandanas"))
        self.assertFalse(self.root.find("apps"))
        self.assertTrue(self.root.find("apple"))
        self.assertTrue(self.root.find("all"))

    def test_delete(self):
        self.root.delete("all")
        self.assertFalse(self.root.find("all"))
        self.root.delete("banana")
        self.assertFalse(self.root.find("banana"))
        self.assertTrue(self.root.find("bananas"))

    def test_print_words(self):
        # Redirect stdout to a StringIO object to capture the output
        import sys
        from io import StringIO
        captured_output = StringIO()
        sys.stdout = captured_output

        print_words(self.root, "")

        # Reset stdout
        sys.stdout = sys.__stdout__

        # Check the captured output
        expected_output = "banana bananas bandana band apple all beast "
        self.assertEqual(captured_output.getvalue(), expected_output)


if __name__ == "__main__":
    unittest.main()
```