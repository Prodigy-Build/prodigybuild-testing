from math import pi


def arc_length(angle: int, radius: int) -> float:
    """
    Calculates the length of an arc given the angle and radius.
    
    Args:
        angle (int): The angle of the arc in degrees.
        radius (int): The radius of the circle.
    
    Returns:
        float: The length of the arc.
    """
    return 2 * pi * radius * (angle / 360)


if __name__ == "__main__":
    print(arc_length(90, 10))