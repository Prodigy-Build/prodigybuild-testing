def twin_prime(number: int) -> int:
    """
    This functions takes an integer number as input.
    returns n+2 if n and n+2 are prime numbers and -1 otherwise.
    """
    if not isinstance(number, int):
        msg = f"Input value of [number={number}] must be an integer"
        raise TypeError(msg)
    if is_prime(number) and is_prime(number + 2):
        return number + 2
    else:
        return -1