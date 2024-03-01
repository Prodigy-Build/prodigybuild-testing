def test_sigmoid():
    assert np.allclose(sigmoid(np.array([-1.0, 1.0, 2.0])), np.array([0.26894142, 0.73105858, 0.88079708]))
    assert np.allclose(sigmoid(np.array([0.0])), np.array([0.5]))