python
def find_all_subsequences(sequence):
    return [[sequence[j] for j in range(len(sequence)) if (i & 1 << j)] for i in range(1 << len(sequence))]

def print_subsequences(sequences):
    for sequence in sequences:
        print(sequence)

if __name__ == "__main__":
    seq1 = [3, 1, 2, 4]
    subsequences1 = find_all_subsequences(seq1)
    print_subsequences(subsequences1)

    seq2 = ["A", "B", "C"]
    subsequences2 = find_all_subsequences(seq2)
    print_subsequences(subsequences2)
