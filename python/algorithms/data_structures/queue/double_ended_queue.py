```python
from algorithms.data_structures.queue.double_ended_queue import Deque

def test_Deque():
    # Test append
    our_deque_1 = Deque([1, 2, 3])
    our_deque_1.append(4)
    assert list(our_deque_1) == [1, 2, 3, 4]

    our_deque_2 = Deque('ab')
    our_deque_2.append('c')
    assert list(our_deque_2) == ['a', 'b', 'c']

    # Test appendleft
    our_deque_3 = Deque([2, 3])
    our_deque_3.appendleft(1)
    assert list(our_deque_3) == [1, 2, 3]

    our_deque_4 = Deque('bc')
    our_deque_4.appendleft('a')
    assert list(our_deque_4) == ['a', 'b', 'c']

    # Test extend
    our_deque_5 = Deque([1, 2, 3])
    our_deque_5.extend([4, 5])
    assert list(our_deque_5) == [1, 2, 3, 4, 5]

    our_deque_6 = Deque('ab')
    our_deque_6.extend('cd')
    assert list(our_deque_6) == ['a', 'b', 'c', 'd']

    # Test extendleft
    our_deque_7 = Deque([1, 2, 3])
    our_deque_7.extendleft([0, -1])
    assert list(our_deque_7) == [-1, 0, 1, 2, 3]

    our_deque_8 = Deque('cd')
    our_deque_8.extendleft('ba')
    assert list(our_deque_8) == ['a', 'b', 'c', 'd']

    # Test pop
    our_deque_9 = Deque([1, 2, 3, 15182])
    our_popped = our_deque_9.pop()
    assert our_popped == 15182
    assert list(our_deque_9) == [1, 2, 3]

    # Test popleft
    our_deque_10 = Deque([15182, 1, 2, 3])
    our_popped = our_deque_10.popleft()
    assert our_popped == 15182
    assert list(our_deque_10) == [1, 2, 3]

    # Test is_empty
    our_deque_11 = Deque([1, 2, 3])
    assert not our_deque_11.is_empty()

    our_empty_deque = Deque()
    assert our_empty_deque.is_empty()

    # Test __len__
    our_deque_12 = Deque([1, 2, 3])
    assert len(our_deque_12) == 3

    our_empty_deque_2 = Deque()
    assert len(our_empty_deque_2) == 0

    # Test __eq__
    our_deque_13 = Deque([1, 2, 3])
    our_deque_14 = Deque([1, 2, 3])
    assert our_deque_13 == our_deque_14

    our_deque_15 = Deque([1, 2])
    assert not our_deque_13 == our_deque_15

    # Test __iter__
    our_deque_16 = Deque([1, 2, 3])
    iterator = iter(our_deque_16)
    assert next(iterator) == 1
    assert next(iterator) == 2
    assert next(iterator) == 3

    # Test __repr__
    our_deque_17 = Deque([1, 2, 3])
    assert repr(our_deque_17) == '[1, 2, 3]'

test_Deque()
```