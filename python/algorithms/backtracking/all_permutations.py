from typing import List


def generate_all_permutations(sequence: List[int | str]) -> List[List[int | str]]:
    permutations = []
    create_state_space_tree(sequence, [], 0, [0 for i in range(len(sequence))], permutations)
    return permutations


def create_state_space_tree(
    sequence: List[int | str],
    current_sequence: List[int | str],
    index: int,
    index_used: List[int],
    permutations: List[List[int | str]],
) -> None:
    if index == len(sequence):
        permutations.append(current_sequence.copy())
        return

    for i in range(len(sequence)):
        if not index_used[i]:
            current_sequence.append(sequence[i])
            index_used[i] = True
            create_state_space_tree(sequence, current_sequence, index + 1, index_used, permutations)
            current_sequence.pop()
            index_used[i] = False


sequence_1: List[int | str] = [3, 1, 2, "A"]
print(generate_all_permutations(sequence_1))

sequence_2: List[int | str] = ["A", "B"]
print(generate_all_permutations(sequence_2))