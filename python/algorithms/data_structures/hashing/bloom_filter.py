import unittest

class TestBloom(unittest.TestCase):
    def setUp(self):
        self.bloom = Bloom(size=8)
        self.films = ["Titanic", "Avatar"]

    def test_add_and_contains(self):
        for film in self.films:
            self.bloom.add(film)
            self.assertIn(film, self.bloom)

    def test_non_existent(self):
        not_present_films = ("The Godfather", "Interstellar", "Parasite", "Pulp Fiction")
        self.assertFalse(any(film in self.bloom for film in not_present_films))

    def test_error_rate(self):
        self.bloom.add("The Godfather")
        self.assertEqual(self.bloom.estimated_error_rate, 0.25)
        
    def test_bitstring(self):
        self.bloom.add("Titanic")
        self.assertEqual(self.bloom.bitstring, '01100000')

if __name__ == '__main__':
    unittest.main()