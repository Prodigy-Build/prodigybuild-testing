import unittest
from math import pi, sqrt, tan


class TestArea(unittest.TestCase):
    def test_surface_area_cube(self):
        self.assertEqual(surface_area_cube(1), 6)
        self.assertEqual(surface_area_cube(1.6), 15.360000000000003)
        self.assertEqual(surface_area_cube(0), 0)
        with self.assertRaises(ValueError):
            surface_area_cube(-1)

    def test_surface_area_cuboid(self):
        self.assertEqual(surface_area_cuboid(1, 2, 3), 22)
        self.assertEqual(surface_area_cuboid(0, 0, 0), 0)
        self.assertEqual(surface_area_cuboid(1.6, 2.6, 3.6), 38.56)
        with self.assertRaises(ValueError):
            surface_area_cuboid(-1, 2, 3)
        with self.assertRaises(ValueError):
            surface_area_cuboid(1, -2, 3)
        with self.assertRaises(ValueError):
            surface_area_cuboid(1, 2, -3)

    def test_surface_area_sphere(self):
        self.assertEqual(surface_area_sphere(5), 314.1592653589793)
        self.assertEqual(surface_area_sphere(1), 12.566370614359172)
        self.assertEqual(surface_area_sphere(1.6), 32.169908772759484)
        self.assertEqual(surface_area_sphere(0), 0.0)
        with self.assertRaises(ValueError):
            surface_area_sphere(-1)

    def test_surface_area_hemisphere(self):
        self.assertEqual(surface_area_hemisphere(5), 235.61944901923448)
        self.assertEqual(surface_area_hemisphere(1), 9.42477796076938)
        self.assertEqual(surface_area_hemisphere(0), 0.0)
        self.assertEqual(surface_area_hemisphere(1.1), 11.40398133253095)
        with self.assertRaises(ValueError):
            surface_area_hemisphere(-1)

    def test_surface_area_cone(self):
        self.assertEqual(surface_area_cone(10, 24), 1130.9733552923256)
        self.assertEqual(surface_area_cone(6, 8), 301.59289474462014)
        self.assertEqual(surface_area_cone(1.6, 2.6), 23.387862992395807)
        self.assertEqual(surface_area_cone(0, 0), 0.0)
        with self.assertRaises(ValueError):
            surface_area_cone(-1, -2)
        with self.assertRaises(ValueError):
            surface_area_cone(1, -2)
        with self.assertRaises(ValueError):
            surface_area_cone(-1, 2)

    def test_surface_area_conical_frustum(self):
        self.assertEqual(surface_area_conical_frustum(1, 2, 3), 45.511728065337266)
        self.assertEqual(surface_area_conical_frustum(4, 5, 6), 300.7913575056268)
        self.assertEqual(surface_area_conical_frustum(0, 0, 0), 0.0)
        self.assertEqual(surface_area_conical_frustum(1.6, 2.6, 3.6), 78.57907060751548)
        with self.assertRaises(ValueError):
            surface_area_conical_frustum(-1, 2, 3)
        with self.assertRaises(ValueError):
            surface_area_conical_frustum(1, -2, 3)
        with self.assertRaises(ValueError):
            surface_area_conical_frustum(1, 2, -3)

    def test_surface_area_cylinder(self):
        self.assertEqual(surface_area_cylinder(7, 10), 747.6990515543707)
        self.assertEqual(surface_area_cylinder(1.6, 2.6), 42.22300526424682)
        self.assertEqual(surface_area_cylinder(0, 0), 0.0)
        self.assertEqual(surface_area_cylinder(6, 8), 527.7875658030853)
        with self.assertRaises(ValueError):
            surface_area_cylinder(-1, -2)
        with self.assertRaises(ValueError):
            surface_area_cylinder(1, -2)
        with self.assertRaises(ValueError):
            surface_area_cylinder(-1, 2)

    def test_surface_area_torus(self):
        self.assertEqual(surface_area_torus(1, 1), 39.47841760435743)
        self.assertEqual(surface_area_torus(4, 3), 473.7410112522892)
        with self.assertRaises(ValueError):
            surface_area_torus(3, 4)
        self.assertEqual(surface_area_torus(1.6, 1.6), 101.06474906715503)
        self.assertEqual(surface_area_torus(0, 0), 0.0)
        with self.assertRaises(ValueError):
            surface_area_torus(-1, 1)
        with self.assertRaises(ValueError):
            surface_area_torus(1, -1)

    def test_area_rectangle(self):
        self.assertEqual(area_rectangle(10, 20), 200)
        self.assertEqual(area_rectangle(1.6, 2.6), 4.16)
        self.assertEqual(area_rectangle(0, 0), 0)
        with self.assertRaises(ValueError):
            area_rectangle(-1, -2)
        with self.assertRaises(ValueError):
            area_rectangle(1, -2)
        with self.assertRaises(ValueError):
            area_rectangle(-1, 2)

    def test_area_square(self):
        self.assertEqual(area_square(10), 100)
        self.assertEqual(area_square(0), 0)
        self.assertEqual(area_square(1.6), 2.5600000000000005)
        with self.assertRaises(ValueError):
            area_square(-1)

    def test_area_triangle(self):
        self.assertEqual(area_triangle(10, 10), 50.0)
        self.assertEqual(area_triangle(1.6, 2.6), 2.08)
        self.assertEqual(area_triangle(0, 0), 0.0)
        with self.assertRaises(ValueError):
            area_triangle(-1, -2)
        with self.assertRaises(ValueError):
            area_triangle(1, -2)
        with self.assertRaises(ValueError):
            area_triangle(-1, 2)

    def test_area_triangle_three_sides(self):
        self.assertEqual(area_triangle_three_sides(5, 12, 13), 30.0)
        self.assertEqual(area_triangle_three_sides(10, 11, 12), 51.521233486786784)
        self.assertEqual(area_triangle_three_sides(0, 0, 0), 0.0)
        self.assertEqual(area_triangle_three_sides(1.6, 2.6, 3.6), 1.8703742940919619)
        with self.assertRaises(ValueError):
            area_triangle_three_sides(-1, -2, -1)
        with self.assertRaises(ValueError):
            area_triangle_three_sides(1, -2, 1)
        with self.assertRaises(ValueError):
            area_triangle_three_sides(2, 4, 7)
        with self.assertRaises(ValueError):
            area_triangle_three_sides(2, 7, 4)
        with self.assertRaises(ValueError):
            area_triangle_three_sides(7, 2, 4)

    def test_area_parallelogram(self):
        self.assertEqual(area_parallelogram(10, 20), 200)
        self.assertEqual(area_parallelogram(1.6, 2.6), 4.16)
        self.assertEqual(area_parallelogram(0, 0), 0)
        with self.assertRaises(ValueError):
            area_parallelogram(-1, -2)
        with self.assertRaises(ValueError):
            area_parallelogram(1, -2)
        with self.assertRaises(ValueError):
            area_parallelogram(-1, 2)

    def test_area_trapezium(self):
        self.assertEqual(area_trapezium(10, 20, 30), 450.0)
        self.assertEqual(area_trapezium(1.6, 2.6, 3.6), 7.5600000000000005)
        self.assertEqual(area_trapezium(0, 0, 0), 0.0)
        with self.assertRaises(ValueError):
            area_trapezium(-1, -2, -3)
        with self.assertRaises(ValueError):
            area_trapezium(-1, 2, 3)
        with self.assertRaises(ValueError):
            area_trapezium(1, -2, 3)
        with self.assertRaises(ValueError):
            area_trapezium(1, 2, -3)
        with self.assertRaises(ValueError):
            area_trapezium(-1, -2, 3)
        with self.assertRaises(ValueError):
            area_trapezium(1, -2, -3)

    def test_area_circle(self):
        self.assertEqual(area_circle(20), 1256.6370614359173)
        self.assertEqual(area_circle(1.6), 8.042477193189871)
        self.assertEqual(area_circle(0), 0.0)
        with self.assertRaises(ValueError):
            area_circle(-1)

    def test_area_ellipse(self):
        self.assertEqual(area_ellipse(10, 10), 314.1592653589793)
        self.assertEqual(area_ellipse(10, 20), 628.3185307179587)
        self.assertEqual(area_ellipse(0, 0), 0.0)
        self.assertEqual(area_ellipse(1.6, 2.6), 13.06902543893354)
        with self.assertRaises(ValueError):
            area_ellipse(-10, 20)
        with self.assertRaises(ValueError):
            area_ellipse(10, -20)
        with self.assertRaises(ValueError):
            area_ellipse(-10, -20)

    def test_area_rhombus(self):
        self.assertEqual(area_rhombus(10, 20), 100.0)
        self.assertEqual(area_rhombus(1.6, 2.6), 2.08)
        self.assertEqual(area_rhombus(0, 0), 0.0)
        with self.assertRaises(ValueError):
            area_rhombus(-1, -2)
        with self.assertRaises(ValueError):
            area_rhombus(1, -2)
        with self.assertRaises(ValueError):
            area_rhombus(-1, 2)

    def test_area_reg_polygon(self):
        self.assertEqual(area_reg_polygon(3, 10), 43.301270189221945)
        self.assertEqual(area_reg_polygon(4, 10), 100.00000000000001)
        with self.assertRaises(ValueError):
            area_reg_polygon(0, 0)
        with self.assertRaises(ValueError):
            area_reg_polygon(-1, -2)
        with self.assertRaises(ValueError):
            area_reg_polygon(5, -2)
        with self.assertRaises(ValueError):
            area_reg_polygon(-1, 2)


if __name__ == "__main__":
    unittest.main()