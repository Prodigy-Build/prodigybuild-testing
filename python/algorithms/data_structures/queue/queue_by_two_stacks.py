from collections.abc import Iterable
from typing import Generic, TypeVar
import unittest

_T = TypeVar("_T")


class QueueByTwoStacks(Generic[_T]):
    def __init__(self, iterable: Iterable[_T] | None = None) -> None:
        self._stack1: list[_T] = list(iterable or [])
        self._stack2: list[_T] = []

    def __len__(self) -> int:
        return len(self._stack1) + len(self._stack2)

    def __repr__(self) -> str:
        return f"Queue({tuple(self._stack2[::-1] + self._stack1)})"

    def put(self, item: _T) -> None:
        self._stack1.append(item)

    def get(self) -> _T:
        stack1_pop = self._stack1.pop
        stack2_append = self._stack2.append

        if not self._stack2:
            while self._stack1:
                stack2_append(stack1_pop())

        if not self._stack2:
            raise IndexError("Queue is empty")
        return self._stack2.pop()


class TestQueueByTwoStacks(unittest.TestCase):
    def test_empty_queue(self):
        queue = QueueByTwoStacks()
        self.assertEqual(len(queue), 0)
        self.assertEqual(queue.__repr__(), "Queue(())")

    def test_queue_with_items(self):
        queue = QueueByTwoStacks([10, 20, 30])
        self.assertEqual(len(queue), 3)
        self.assertEqual(queue.__repr__(), "Queue((10, 20, 30))")

    def test_queue_with_generator(self):
        queue = QueueByTwoStacks((i**2 for i in range(1, 4)))
        self.assertEqual(len(queue), 3)
        self.assertEqual(queue.__repr__(), "Queue((1, 4, 9))")

    def test_put_item(self):
        queue = QueueByTwoStacks()
        queue.put(10)
        self.assertEqual(len(queue), 1)
        self.assertEqual(queue.__repr__(), "Queue((10,))")

    def test_get_item(self):
        queue = QueueByTwoStacks((10, 20, 30))
        self.assertEqual(queue.get(), 10)
        queue.put(40)
        self.assertEqual(queue.get(), 20)
        self.assertEqual(queue.get(), 30)
        self.assertEqual(len(queue), 1)
        self.assertEqual(queue.get(), 40)
        with self.assertRaises(IndexError):
            queue.get()


if __name__ == "__main__":
    unittest.main()