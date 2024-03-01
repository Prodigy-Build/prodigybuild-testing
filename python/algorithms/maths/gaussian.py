def test_gaussian():
    assert gaussian(1) == 0.24197072451914337
    assert gaussian(24) == 3.342714441794458e-126
    assert gaussian(1, 4, 2) == 0.06475879783294587
    assert gaussian(1, 5, 3) == 0.05467002489199788
    assert np.allclose(gaussian(np.arange(15)), np.array([3.98942280e-01, 2.41970725e-01, 5.39909665e-02, 4.43184841e-03,
           1.33830226e-04, 1.48671951e-06, 6.07588285e-09, 9.13472041e-12,
           5.05227108e-15, 1.02797736e-18, 7.69459863e-23, 2.11881925e-27,
           2.14638374e-32, 7.99882776e-38, 1.09660656e-43]))
    assert gaussian(15) == 5.530709549844416e-50
    with pytest.raises(TypeError):
        gaussian([1,2, 'string'])
    with pytest.raises(TypeError):
        gaussian('hello world')
    with pytest.raises(OverflowError):
        gaussian(10**234)
    assert gaussian(10**-326) == 0.3989422804014327
    assert gaussian(2523, mu=234234, sigma=3425) == 0.0