def test_is_prime():
    assert is_prime(2) == True
    assert is_prime(3) == True
    assert is_prime(4) == False
    assert is_prime(5) == True
    assert is_prime(6) == False

def test_sieve_er():
    assert sieve_er(10) == [2, 3, 5, 7]
    assert sieve_er(20) == [2, 3, 5, 7, 11, 13, 17, 19]
    assert sieve_er(30) == [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

def test_get_prime_numbers():
    assert get_prime_numbers(10) == [2, 3, 5, 7]
    assert get_prime_numbers(20) == [2, 3, 5, 7, 11, 13, 17, 19]
    assert get_prime_numbers(30) == [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

def test_prime_factorization():
    assert prime_factorization(2) == [2]
    assert prime_factorization(3) == [3]
    assert prime_factorization(4) == [2, 2]
    assert prime_factorization(5) == [5]
    assert prime_factorization(6) == [2, 3]

def test_greatest_prime_factor():
    assert greatest_prime_factor(2) == 2
    assert greatest_prime_factor(3) == 3
    assert greatest_prime_factor(4) == 2
    assert greatest_prime_factor(5) == 5
    assert greatest_prime_factor(6) == 3

def test_smallest_prime_factor():
    assert smallest_prime_factor(2) == 2
    assert smallest_prime_factor(3) == 3
    assert smallest_prime_factor(4) == 2
    assert smallest_prime_factor(5) == 5
    assert smallest_prime_factor(6) == 2

def test_is_even():
    assert is_even(2) == True
    assert is_even(3) == False
    assert is_even(4) == True
    assert is_even(5) == False
    assert is_even(6) == True

def test_is_odd():
    assert is_odd(2) == False
    assert is_odd(3) == True
    assert is_odd(4) == False
    assert is_odd(5) == True
    assert is_odd(6) == False

def test_goldbach():
    assert goldbach(4) == [2, 2]
    assert goldbach(6) == [3, 3]
    assert goldbach(8) == [3, 5]
    assert goldbach(10) == [3, 7]
    assert goldbach(12) == [5, 7]

def test_gcd():
    assert gcd(2, 3) == 1
    assert gcd(4, 6) == 2
    assert gcd(8, 12) == 4
    assert gcd(10, 15) == 5
    assert gcd(12, 18) == 6

def test_kg_v():
    assert kg_v(2, 3) == 6
    assert kg_v(4, 6) == 12
    assert kg_v(8, 12) == 24
    assert kg_v(10, 15) == 30
    assert kg_v(12, 18) == 36

def test_get_prime():
    assert get_prime(0) == 2
    assert get_prime(1) == 3
    assert get_prime(2) == 5
    assert get_prime(3) == 7
    assert get_prime(4) == 11

def test_get_primes_between():
    assert get_primes_between(2, 10) == [3, 5, 7]
    assert get_primes_between(5, 20) == [7, 11, 13, 17, 19]
    assert get_primes_between(10, 30) == [11, 13, 17, 19, 23, 29]

def test_get_divisors():
    assert get_divisors(2) == [1, 2]
    assert get_divisors(3) == [1, 3]
    assert get_divisors(4) == [1, 2, 4]
    assert get_divisors(5) == [1, 5]
    assert get_divisors(6) == [1, 2, 3, 6]

def test_is_perfect_number():
    assert is_perfect_number(2) == False
    assert is_perfect_number(3) == False
    assert is_perfect_number(4) == False
    assert is_perfect_number(5) == False
    assert is_perfect_number(6) == True

def test_simplify_fraction():
    assert simplify_fraction(2, 4) == (1, 2)
    assert simplify_fraction(3, 9) == (1, 3)
    assert simplify_fraction(4, 8) == (1, 2)
    assert simplify_fraction(5, 10) == (1, 2)
    assert simplify_fraction(6, 12) == (1, 2)

def test_factorial():
    assert factorial(0) == 1
    assert factorial(1) == 1
    assert factorial(2) == 2
    assert factorial(3) == 6
    assert factorial(4) == 24

def test_fib():
    assert fib(0) == 1
    assert fib(1) == 1
    assert fib(2) == 2
    assert fib(3) == 3
    assert fib(4) == 5