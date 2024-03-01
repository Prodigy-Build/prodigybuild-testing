```python
# python/algorithms/maths/integration_by_simpson_approx.py

def test_simpson_integration():
    assert simpson_integration(lambda x: x * x, 1, 2, 3) == 2.333
    assert simpson_integration(lambda x: x * x, 3.45, 3.2, 1) == -2.8

    try:
        simpson_integration(lambda x: x * x, 'wrong_input', 2, 3)
        assert False, "Expected AssertionError"
    except AssertionError as e:
        assert str(e) == "a should be float or integer your input : wrong_input"

    try:
        simpson_integration(lambda x: x * x, 1, 'wrong_input', 3)
        assert False, "Expected AssertionError"
    except AssertionError as e:
        assert str(e) == "b should be float or integer your input : wrong_input"

    try:
        simpson_integration(lambda x: x * x, 1, 2, 'wrong_input')
        assert False, "Expected AssertionError"
    except AssertionError as e:
        assert str(e) == "precision should be positive integer your input : wrong_input"

    try:
        simpson_integration('wrong_input', 2, 3, 4)
        assert False, "Expected AssertionError"
    except AssertionError as e:
        assert str(e) == "the function(object) passed should be callable your input : wrong_input"

    try:
        simpson_integration(lambda x: x * x, 3.45, 3.2, 0)
        assert False, "Expected AssertionError"
    except AssertionError as e:
        assert str(e) == "precision should be positive integer your input : 0"

    try:
        simpson_integration(lambda x: x * x, 3.45, 3.2, -1)
        assert False, "Expected AssertionError"
    except AssertionError as e:
        assert str(e) == "precision should be positive integer your input : -1"
```