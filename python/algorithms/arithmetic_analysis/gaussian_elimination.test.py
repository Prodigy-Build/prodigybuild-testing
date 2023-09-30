```python
    def test_retroactive_resolution():
        assert (retroactive_resolution(np.array([[2, 2, -1], [0, -2, -1], [0, 0, 5]]), np.array([[5], [-7], [15]]))) == np.array([[2.], [2.], [3.]]))
        assert (retroactive_resolution(np.array([[2, 2], [0, -2]]), np.array([[-1], [-1]]))) == np.array([[-1.], [ 0.5]]))

    def test_gaussian_elimination():
        assert (gaussian_elimination(np.array([[1, -4, -2], [5, 2, -2], [1, -1, 0]]), np.array([[-2], [-3], [4]]))) == np.array([[ 2.3 ], [-1.7 ], [ 5.55]]))
        assert (gaussian_elimination(np.array([[1, 2], [5, 2]]), np.array([[5], [5]]))) == np.array([[0.], [2.5]]))

    test_retroactive_resolution()
    test_gaussian_elimination()
```