import unittest

from algorithms.hashes.enigma_machine import engine, rotator


class EnigmaMachineTestCase(unittest.TestCase):
    def test_engine(self):
        alphabets = [chr(i) for i in range(32, 126)]
        gear_one = list(range(len(alphabets)))
        gear_two = list(range(len(alphabets)))
        gear_three = list(range(len(alphabets)))
        reflector = list(reversed(range(len(alphabets))))
        code = []
        gear_one_pos = gear_two_pos = gear_three_pos = 0

        def rotator():
            nonlocal gear_one_pos, gear_two_pos, gear_three_pos
            i = gear_one[0]
            gear_one.append(i)
            del gear_one[0]
            gear_one_pos += 1
            if gear_one_pos % int(len(alphabets)) == 0:
                i = gear_two[0]
                gear_two.append(i)
                del gear_two[0]
                gear_two_pos += 1
                if gear_two_pos % int(len(alphabets)) == 0:
                    i = gear_three[0]
                    gear_three.append(i)
                    del gear_three[0]
                    gear_three_pos += 1

        def engine(input_character):
            nonlocal code
            target = alphabets.index(input_character)
            target = gear_one[target]
            target = gear_two[target]
            target = gear_three[target]
            target = reflector[target]
            target = gear_three.index(target)
            target = gear_two.index(target)
            target = gear_one.index(target)
            code.append(alphabets[target])
            rotator()

        decode = list("Hello World")
        token = 5
        for _ in range(token):
            rotator()
        for j in decode:
            engine(j)
        self.assertEqual("".join(code), "Uryyb Jbeyq")


if __name__ == "__main__":
    unittest.main()