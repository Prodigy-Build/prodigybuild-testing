"""
Checks if a system of forces is in static equilibrium.
Updated to Python 3.9
"""
from typing import List
import numpy as np

def polar_force(
    magnitude: float, angle: float, radian_mode: bool = False
) -> List[float]:
    """
    Resolves force along rectangular components.
    (force, angle) => (force_x, force_y)
    """
    if radian_mode:
        return [magnitude * np.cos(angle), magnitude * np.sin(angle)]
    return [magnitude * np.cos(np.radians(angle)), magnitude * np.sin(np.radians(angle))]


def in_static_equilibrium(
    forces: np.ndarray, location: np.ndarray, eps: float = 10**-1
) -> bool:
    """
    Check if a system is in equilibrium.
    It takes two numpy.array objects.
    forces ==>  [
                        [force1_x, force1_y],
                        [force2_x, force2_y],
                        ....]
    location ==>  [
                        [x1, y1],
                        [x2, y2],
                        ....]
    """
    # summation of moments is zero
    moments: np.ndarray = np.cross(location, forces)
    sum_moments: float = np.sum(moments)
    return abs(sum_moments) < eps


if __name__ == "__main__":
    # Test to check if it works
    forces = np.array(
        [
            polar_force(718.4, 180 - 30),
            polar_force(879.54, 45),
            polar_force(100, -90),
        ]
    )

    location: np.ndarray = np.array([[0, 0], [0, 0], [0, 0]])

    assert in_static_equilibrium(forces, location)

    # Problem 1 in image_data/2D_problems.jpg
    forces = np.array(
        [
            polar_force(30 * 9.81, 15),
            polar_force(215, 180 - 45),
            polar_force(264, 90 - 30),
        ]
    )

    location = np.array([[0, 0], [0, 0], [0, 0]])

    assert in_static_equilibrium(forces, location)

    # Problem in image_data/2D_problems_1.jpg
    forces = np.array([[0, -2000], [0, -1200], [0, 15600], [0, -12400]])

    location = np.array([[0, 0], [6, 0], [10, 0], [12, 0]])

    assert in_static_equilibrium(forces, location)

    import doctest

    doctest.testmod()