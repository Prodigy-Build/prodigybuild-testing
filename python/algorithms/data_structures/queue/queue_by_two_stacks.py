import unittest
from typing import Any, List
from queue_by_two_stacks import QueueByTwoStacks


class TestQueueByTwoStacks(unittest.TestCase):
    def setUp(self) -> None:
        self.queue: QueueByTwoStacks[Any] = QueueByTwoStacks()

    def test_put(self) -> None:
        self.queue.put(1)
        self.assertEqual(len(self.queue), 1)

    def test_get(self) -> None:
        self.queue.put(1)
        self.queue.put(2)
        self.assertEqual(self.queue.get(), 1)
        self.assertEqual(self.queue.get(), 2)

    def test_queue(self) -> None:
        items: List[int] = list(range(10))
        for item in items:
            self.queue.put(item)
        self.assertEqual(len(self.queue), len(items))
        for item in items:
            self.assertEqual(self.queue.get(), item)

    def test_empty_queue_raises_error(self) -> None:
        with self.assertRaises(IndexError):
            self.queue.get()


if __name__ == "__main__":
    unittest.main()