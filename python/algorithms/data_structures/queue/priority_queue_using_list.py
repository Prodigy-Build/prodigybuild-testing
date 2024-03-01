The updated code for the file "python/algorithms/data_structures/queue/priority_queue_using_list.py" is as follows:

```python
class OverFlowError(Exception):
    pass


class UnderFlowError(Exception):
    pass


class FixedPriorityQueue:
    def __init__(self):
        self.queues = [
            [],
            [],
            [],
        ]

    def enqueue(self, priority: int, data: int) -> None:
        try:
            if len(self.queues[priority]) >= 100:
                raise OverFlowError("Maximum queue size is 100")
            self.queues[priority].append(data)
        except IndexError:
            raise ValueError("Valid priorities are 0, 1, and 2")

    def dequeue(self) -> int:
        for queue in self.queues:
            if queue:
                return queue.pop(0)
        raise UnderFlowError("All queues are empty")

    def __str__(self) -> str:
        return "\n".join(f"Priority {i}: {q}" for i, q in enumerate(self.queues))


class ElementPriorityQueue:
    def __init__(self):
        self.queue = []

    def enqueue(self, data: int) -> None:
        if len(self.queue) == 100:
            raise OverFlowError("Maximum queue size is 100")
        self.queue.append(data)

    def dequeue(self) -> int:
        if not self.queue:
            raise UnderFlowError("The queue is empty")
        else:
            data = min(self.queue)
            self.queue.remove(data)
            return data

    def __str__(self) -> str:
        return str(self.queue)
```

Please note that the code provided in the original file is not testable as it only contains class definitions and function calls.