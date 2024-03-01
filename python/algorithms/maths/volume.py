def test_vol_cube():
    assert vol_cube(1) == 1.0
    assert vol_cube(3) == 27.0
    assert vol_cube(0) == 0.0
    assert vol_cube(1.6) == 4.096000000000001
    try:
        vol_cube(-1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_cube() only accepts non-negative values"

def test_vol_spherical_cap():
    assert vol_spherical_cap(1, 2) == 5.235987755982988
    assert vol_spherical_cap(1.6, 2.6) == 16.621119532592402
    assert vol_spherical_cap(0, 0) == 0.0
    try:
        vol_spherical_cap(-1, 2)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_spherical_cap() only accepts non-negative values"
    try:
        vol_spherical_cap(1, -2)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_spherical_cap() only accepts non-negative values"

def test_vol_spheres_intersect():
    assert vol_spheres_intersect(2, 2, 1) == 21.205750411731103
    assert vol_spheres_intersect(2.6, 2.6, 1.6) == 40.71504079052372
    assert vol_spheres_intersect(0, 0, 0) == 0.0
    try:
        vol_spheres_intersect(-2, 2, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_spheres_intersect() only accepts non-negative values"
    try:
        vol_spheres_intersect(2, -2, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_spheres_intersect() only accepts non-negative values"
    try:
        vol_spheres_intersect(2, 2, -1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_spheres_intersect() only accepts non-negative values"

def test_vol_spheres_union():
    assert vol_spheres_union(2, 2, 1) == 45.814892864851146
    assert vol_spheres_union(1.56, 2.2, 1.4) == 48.77802773671288
    try:
        vol_spheres_union(0, 2, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_spheres_union() only accepts non-negative values, non-zero radius"
    try:
        vol_spheres_union('1.56', '2.2', '1.4')
        assert False, "Expected TypeError"
    except TypeError as e:
        assert str(e) == "'<=' not supported between instances of 'str' and 'int'"
    try:
        vol_spheres_union(1, None, 1)
        assert False, "Expected TypeError"
    except TypeError as e:
        assert str(e) == "'<=' not supported between instances of 'NoneType' and 'int'"

def test_vol_cuboid():
    assert vol_cuboid(1, 1, 1) == 1.0
    assert vol_cuboid(1, 2, 3) == 6.0
    assert vol_cuboid(1.6, 2.6, 3.6) == 14.976
    assert vol_cuboid(0, 0, 0) == 0.0
    try:
        vol_cuboid(-1, 2, 3)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_cuboid() only accepts non-negative values"
    try:
        vol_cuboid(1, -2, 3)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_cuboid() only accepts non-negative values"
    try:
        vol_cuboid(1, 2, -3)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_cuboid() only accepts non-negative values"

def test_vol_cone():
    assert vol_cone(10, 3) == 10.0
    assert vol_cone(1, 1) == 0.3333333333333333
    assert vol_cone(1.6, 1.6) == 0.8533333333333335
    assert vol_cone(0, 0) == 0.0
    try:
        vol_cone(-1, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_cone() only accepts non-negative values"
    try:
        vol_cone(1, -1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_cone() only accepts non-negative values"

def test_vol_right_circ_cone():
    assert vol_right_circ_cone(2, 3) == 12.566370614359172
    assert vol_right_circ_cone(0, 0) == 0.0
    assert vol_right_circ_cone(1.6, 1.6) == 4.289321169701265
    try:
        vol_right_circ_cone(-1, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_right_circ_cone() only accepts non-negative values"
    try:
        vol_right_circ_cone(1, -1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_right_circ_cone() only accepts non-negative values"

def test_vol_prism():
    assert vol_prism(10, 2) == 20.0
    assert vol_prism(11, 1) == 11.0
    assert vol_prism(1.6, 1.6) == 2.5600000000000005
    assert vol_prism(0, 0) == 0.0
    try:
        vol_prism(-1, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_prism() only accepts non-negative values"
    try:
        vol_prism(1, -1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_prism() only accepts non-negative values"

def test_vol_pyramid():
    assert vol_pyramid(10, 3) == 10.0
    assert vol_pyramid(1.5, 3) == 1.5
    assert vol_pyramid(1.6, 1.6) == 0.8533333333333335
    assert vol_pyramid(0, 0) == 0.0
    try:
        vol_pyramid(-1, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_pyramid() only accepts non-negative values"
    try:
        vol_pyramid(1, -1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_pyramid() only accepts non-negative values"

def test_vol_sphere():
    assert vol_sphere(5) == 523.5987755982989
    assert vol_sphere(1) == 4.1887902047863905
    assert vol_sphere(1.6) == 17.15728467880506
    assert vol_sphere(0) == 0.0
    try:
        vol_sphere(-1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_sphere() only accepts non-negative values"

def test_vol_hemisphere():
    assert vol_hemisphere(1) == 2.0943951023931953
    assert vol_hemisphere(7) == 718.377520120866
    assert vol_hemisphere(1.6) == 8.57864233940253
    assert vol_hemisphere(0) == 0.0
    try:
        vol_hemisphere(-1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_hemisphere() only accepts non-negative values"

def test_vol_circular_cylinder():
    assert vol_circular_cylinder(1, 1) == 3.141592653589793
    assert vol_circular_cylinder(4, 3) == 150.79644737231007
    assert vol_circular_cylinder(1.6, 1.6) == 12.867963509103795
    assert vol_circular_cylinder(0, 0) == 0.0
    try:
        vol_circular_cylinder(-1, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_circular_cylinder() only accepts non-negative values"
    try:
        vol_circular_cylinder(1, -1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_circular_cylinder() only accepts non-negative values"

def test_vol_hollow_circular_cylinder():
    assert vol_hollow_circular_cylinder(1, 2, 3) == 28.274333882308138
    try:
        vol_hollow_circular_cylinder(-1, 2, 3)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_hollow_circular_cylinder() only accepts non-negative values"
    try:
        vol_hollow_circular_cylinder(1, -2, 3)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_hollow_circular_cylinder() only accepts non-negative values"
    try:
        vol_hollow_circular_cylinder(1, 2, -3)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_hollow_circular_cylinder() only accepts non-negative values"
    try:
        vol_hollow_circular_cylinder(2, 1, 3)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "outer_radius must be greater than inner_radius"
    try:
        vol_hollow_circular_cylinder(0, 0, 0)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "outer_radius must be greater than inner_radius"

def test_vol_conical_frustum():
    assert vol_conical_frustum(45, 7, 28) == 48490.482608158454
    assert vol_conical_frustum(1, 1, 2) == 7.330382858376184
    assert vol_conical_frustum(1.6, 2.6, 3.6) == 48.7240076620753
    assert vol_conical_frustum(0, 0, 0) == 0.0
    try:
        vol_conical_frustum(-2, 2, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_conical_frustum() only accepts non-negative values"
    try:
        vol_conical_frustum(2, -2, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_conical_frustum() only accepts non-negative values"
    try:
        vol_conical_frustum(2, 2, -1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_conical_frustum() only accepts non-negative values"

def test_vol_torus():
    assert vol_torus(1, 1) == 19.739208802178716
    assert vol_torus(4, 3) == 710.6115168784338
    assert vol_torus(3, 4) == 947.4820225045784
    assert vol_torus(1.6, 1.6) == 80.85179925372404
    assert vol_torus(0, 0) == 0.0
    try:
        vol_torus(-1, 1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_torus() only accepts non-negative values"
    try:
        vol_torus(1, -1)
        assert False, "Expected ValueError"
    except ValueError as e:
        assert str(e) == "vol_torus() only accepts non-negative values"

test_vol_cube()
test_vol_spherical_cap()
test_vol_spheres_intersect()
test_vol_spheres_union()
test_vol_cuboid()
test_vol_cone()
test_vol_right_circ_cone()
test_vol_prism()
test_vol_pyramid()
test_vol_sphere()
test_vol_hemisphere()
test_vol_circular_cylinder()
test_vol_hollow_circular_cylinder()
test_vol_conical_frustum()
test_vol_torus()