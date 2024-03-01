def test_check_polygon():
    assert check_polygon([6, 10, 5]) == True
    assert check_polygon([3, 7, 13, 2]) == False
    assert check_polygon([1, 4.3, 5.2, 12.2]) == False
    nums = [3, 7, 13, 2]
    _ = check_polygon(nums)
    assert nums == [3, 7, 13, 2]
    try:
        check_polygon([])
        assert False, "Expected ValueError"
    except ValueError:
        pass
    try:
        check_polygon([-2, 5, 6])
        assert False, "Expected ValueError"
    except ValueError:
        pass