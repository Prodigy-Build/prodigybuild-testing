from typing import List
import math

def polar_force(
    magnitude: float, angle: float, radian_mode: bool = False
) -> List[float]:
    if radian_mode:
        return [magnitude * math.cos(angle), magnitude * math.sin(angle)]
    return [magnitude * math.cos(math.radians(angle)), magnitude * math.sin(math.radians(angle))]

def in_static_equilibrium(
    forces: List[List[float]], location: List[List[float]], eps: float = 10**-1
) -> bool:
    moments = [location[i][0] * forces[i][1] - location[i][1] * forces[i][0] for i in range(len(forces))]
    sum_moments = sum(moments)
    return abs(sum_moments) < eps

if __name__ == "__main__":
    forces = [
        polar_force(718.4, 180 - 30),
        polar_force(879.54, 45),
        polar_force(100, -90),
    ]
    location = [[0, 0], [0, 0], [0, 0]]
    assert in_static_equilibrium(forces, location)

    forces = [
        polar_force(30 * 9.81, 15),
        polar_force(215, 180 - 45),
        polar_force(264, 90 - 30),
    ]
    location = [[0, 0], [0, 0], [0, 0]]
    assert in_static_equilibrium(forces, location)

    forces = [[0, -2000], [0, -1200], [0, 15600], [0, -12400]]
    location = [[0, 0], [6, 0], [10, 0], [12, 0]]
    assert in_static_equilibrium(forces, location)