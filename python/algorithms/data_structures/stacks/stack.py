from __future__ import annotations

from typing import Generic, TypeVar

T = TypeVar("T")


class StackOverflowError(BaseException):
    pass


class StackUnderflowError(BaseException):
    pass


class Stack(Generic[T]):
    """A stack is an abstract data type that serves as a collection of
    elements with two principal operations: push() and pop(). push() adds an
    element to the top of the stack, and pop() removes an element from the top
    of a stack. The order in which elements come off of a stack are
    Last In, First Out (LIFO).
    https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
    """

    def __init__(self, limit: int = 10):
        self.stack: list[T] = []
        self.limit = limit

    def __bool__(self) -> bool:
        return bool(self.stack)

    def __str__(self) -> str:
        return str(self.stack)

    def push(self, data: T) -> None:
        """Push an element to the top of the stack."""
        if len(self.stack) >= self.limit:
            raise StackOverflowError
        self.stack.append(data)

    def pop(self) -> T:
        """
        Pop an element off of the top of the stack.

        >>> Stack().pop()
        Traceback (most recent call last):
            ...
        data_structures.stacks.stack.StackUnderflowError
        """
        if not self.stack:
            raise StackUnderflowError
        return self.stack.pop()

    def peek(self) -> T:
        """
        Peek at the top-most element of the stack.

        >>> Stack().pop()
        Traceback (most recent call last):
            ...
        data_structures.stacks.stack.StackUnderflowError
        """
        if not self.stack:
            raise StackUnderflowError
        return self.stack[-1]

    def is_empty(self) -> bool:
        """Check if a stack is empty."""
        return not bool(self.stack)

    def is_full(self) -> bool:
        return self.size() == self.limit

    def size(self) -> int:
        """Return the size of the stack."""
        return len(self.stack)

    def __contains__(self, item: T) -> bool:
        """Check if item is in stack"""
        return item in self.stack


def test_stack() -> None:
    """
    >>> test_stack()
    """
    stack: Stack[int] = Stack(10)
    assert bool(stack) is False
    assert stack.is_empty() is True
    assert stack.is_full() is False
    assert str(stack) == "[]"

    try:
        _ = stack.pop()
        raise AssertionError  # This should not happen
    except StackUnderflowError:
        assert True  # This should happen

    try:
        _ = stack.peek()
        raise AssertionError  # This should not happen
    except StackUnderflowError:
        assert True  # This should happen

    for i in range(10):
        assert stack.size() == i
        stack.push(i)

    assert bool(stack)
    assert not stack.is_empty()
    assert stack.is_full()
    assert str(stack) == str(list(range(10)))
    assert stack.pop() == 9
    assert stack.peek() == 8

    stack.push(100)
    assert str(stack) == str([0, 1, 2, 3, 4, 5, 6, 7, 8, 100])

    try:
        stack.push(200)
        raise AssertionError  # This should not happen
    except StackOverflowError:
        assert True  # This should happen

    assert not stack.is_empty()
    assert stack.size() == 10

    assert 5 in stack
    assert 55 not in stack


def test_stack_overflow() -> None:
    """
    >>> test_stack_overflow()
    """
    stack: Stack[int] = Stack(5)
    for i in range(5):
        stack.push(i)
    try:
        stack.push(5)
        raise AssertionError  # This should not happen
    except StackOverflowError:
        assert True  # This should happen


def test_stack_underflow() -> None:
    """
    >>> test_stack_underflow()
    """
    stack: Stack[int] = Stack(5)
    try:
        _ = stack.pop()
        raise AssertionError  # This should not happen
    except StackUnderflowError:
        assert True  # This should happen


def test_stack_peek() -> None:
    """
    >>> test_stack_peek()
    """
    stack: Stack[int] = Stack(5)
    stack.push(1)
    assert stack.peek() == 1
    stack.push(2)
    assert stack.peek() == 2
    stack.pop()
    assert stack.peek() == 1


def test_stack_is_empty() -> None:
    """
    >>> test_stack_is_empty()
    """
    stack: Stack[int] = Stack(5)
    assert stack.is_empty() is True
    stack.push(1)
    assert stack.is_empty() is False
    stack.pop()
    assert stack.is_empty() is True


def test_stack_is_full() -> None:
    """
    >>> test_stack_is_full()
    """
    stack: Stack[int] = Stack(5)
    assert stack.is_full() is False
    for i in range(5):
        stack.push(i)
    assert stack.is_full() is True


def test_stack_size() -> None:
    """
    >>> test_stack_size()
    """
    stack: Stack[int] = Stack(5)
    assert stack.size() == 0
    stack.push(1)
    assert stack.size() == 1
    stack.push(2)
    assert stack.size() == 2
    stack.pop()
    assert stack.size() == 1


def test_stack_contains() -> None:
    """
    >>> test_stack_contains()
    """
    stack: Stack[int] = Stack(5)
    stack.push(1)
    stack.push(2)
    assert 1 in stack
    assert 2 in stack
    assert 3 not in stack


if __name__ == "__main__":
    test_stack()
    test_stack_overflow()
    test_stack_underflow()
    test_stack_peek()
    test_stack_is_empty()
    test_stack_is_full()
    test_stack_size()
    test_stack_contains()