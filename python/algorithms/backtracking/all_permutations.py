from typing import List


def generate_all_permutations(sequence: List[int | str]) -> List[List[int | str]]:
    return get_permutations(sequence)


def get_permutations(sequence: List[int | str]) -> List[List[int | str]]:
    if len(sequence) <= 1:
        return [sequence]
    
    result = []
    
    for i in range(len(sequence)):
        current_element = sequence[i]
        remaining_elements = sequence[:i] + sequence[i+1:]
        permutations = get_permutations(remaining_elements)
        
        for permutation in permutations:
            result.append([current_element] + permutation)
    
    return result


sequence: List[int | str] = [3, 1, 2, 4]
print(generate_all_permutations(sequence))

sequence_2: List[int | str] = ["A", "B", "C"]
print(generate_all_permutations(sequence_2))