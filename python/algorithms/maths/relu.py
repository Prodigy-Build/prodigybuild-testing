def test_relu():
    vec = np.array([-1, 0, 5])
    assert np.array_equal(relu(vec), np.array([0, 0, 5]))

test_relu()