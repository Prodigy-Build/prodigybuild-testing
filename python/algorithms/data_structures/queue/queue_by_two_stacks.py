class TestQueueByTwoStacks:
    def test_init_empty(self):
        queue = QueueByTwoStacks()
        assert len(queue) == 0
        assert str(queue) == "Queue(())"

    def test_init_with_iterable(self):
        queue = QueueByTwoStacks([10, 20, 30])
        assert len(queue) == 3
        assert str(queue) == "Queue((10, 20, 30))"

    def test_init_with_generator(self):
        queue = QueueByTwoStacks((i**2 for i in range(1, 4)))
        assert len(queue) == 3
        assert str(queue) == "Queue((1, 4, 9))"

    def test_len_empty(self):
        queue = QueueByTwoStacks()
        assert len(queue) == 0

    def test_len_non_empty(self):
        queue = QueueByTwoStacks([10, 20, 30])
        assert len(queue) == 3

    def test_len_after_put(self):
        queue = QueueByTwoStacks()
        for i in range(1, 11):
            queue.put(i)
        assert len(queue) == 10

    def test_get(self):
        queue = QueueByTwoStacks((10, 20, 30))
        assert queue.get() == 10

    def test_get_after_put(self):
        queue = QueueByTwoStacks((10, 20, 30))
        queue.put(40)
        assert queue.get() == 20
        assert queue.get() == 30
        assert len(queue) == 1
        assert queue.get() == 40

    def test_get_empty(self):
        queue = QueueByTwoStacks()
        try:
            queue.get()
        except IndexError:
            assert True
        else:
            assert False

    def test_repr_empty(self):
        queue = QueueByTwoStacks()
        assert repr(queue) == "Queue(())"

    def test_repr_non_empty(self):
        queue = QueueByTwoStacks()
        queue.put(10)
        queue.put(20)
        queue.put(30)
        assert repr(queue) == "Queue((10, 20, 30))"