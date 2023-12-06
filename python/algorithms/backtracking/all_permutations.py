from typing import List, Union

def generate_all_permutations(sequence: List[Union[int, str]]) -> None:
    create_state_space_tree(sequence, [], 0, [0 for i in range(len(sequence))])

def create_state_space_tree(
    sequence: List[Union[int, str]],
    current_sequence: List[Union[int, str]],
    index: int,
    index_used: List[int]
) -> None:

    if index == len(sequence):
        print(current_sequence)
        return

    for i in range(len(sequence)):
        if not index_used[i]:
            current_sequence.append(sequence[i])
            index_used[i] = True
            create_state_space_tree(sequence, current_sequence, index + 1, index_used)
            current_sequence.pop()
            index_used[i] = False

sequence: List[Union[int, str]] = [3, 1, 2, 4]
generate_all_permutations(sequence)

sequence_2: List[Union[int, str]] = ["A", "B", "C"]
generate_all_permutations(sequence_2)