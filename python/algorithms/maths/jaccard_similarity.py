The updated code for the file "python/algorithms/maths/jaccard_similarity.py" with added unit test cases is as follows:

```python
import unittest

def jaccard_similarity(set_a, set_b, alternative_union=False):
    if isinstance(set_a, set) and isinstance(set_b, set):
        intersection = len(set_a.intersection(set_b))

        if alternative_union:
            union = len(set_a) + len(set_b)
        else:
            union = len(set_a.union(set_b))

        return intersection / union

    if isinstance(set_a, (list, tuple)) and isinstance(set_b, (list, tuple)):
        intersection = [element for element in set_a if element in set_b]

        if alternative_union:
            union = len(set_a) + len(set_b)
            return len(intersection) / union
        else:
            union = set_a + [element for element in set_b if element not in set_a]
            return len(intersection) / len(union)

    return None


class JaccardSimilarityTestCase(unittest.TestCase):
    def test_set_similarity(self):
        set_a = {'a', 'b', 'c', 'd', 'e'}
        set_b = {'c', 'd', 'e', 'f', 'h', 'i'}
        self.assertAlmostEqual(jaccard_similarity(set_a, set_b), 0.375)

    def test_set_self_similarity(self):
        set_a = {'a', 'b', 'c', 'd', 'e'}
        self.assertAlmostEqual(jaccard_similarity(set_a, set_a), 1.0)

    def test_set_self_similarity_alternative_union(self):
        set_a = {'a', 'b', 'c', 'd', 'e'}
        self.assertAlmostEqual(jaccard_similarity(set_a, set_a, True), 0.5)

    def test_list_tuple_similarity(self):
        set_a = ['a', 'b', 'c', 'd', 'e']
        set_b = ('c', 'd', 'e', 'f', 'h', 'i')
        self.assertAlmostEqual(jaccard_similarity(set_a, set_b), 0.375)


if __name__ == "__main__":
    unittest.main()
```
