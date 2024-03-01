import operator as op


def solve(post_fix):
    stack = []
    div = lambda x, y: int(x / y)  # noqa: E731 integer division operation
    opr = {
        "^": op.pow,
        "*": op.mul,
        "/": div,
        "+": op.add,
        "-": op.sub,
    }  # operators & their respective operation

    # print table header
    print("Symbol".center(8), "Action".center(12), "Stack", sep=" | ")
    print("-" * (30 + len(post_fix)))

    for x in post_fix:
        if x.isdigit():  # if x in digit
            stack.append(x)  # append x to stack
            # output in tabular format
            print(x.rjust(8), ("push(" + x + ")").ljust(12), ",".join(stack), sep=" | ")
        else:
            b = stack.pop()  # pop stack
            # output in tabular format
            print("".rjust(8), ("pop(" + b + ")").ljust(12), ",".join(stack), sep=" | ")

            a = stack.pop()  # pop stack
            # output in tabular format
            print("".rjust(8), ("pop(" + a + ")").ljust(12), ",".join(stack), sep=" | ")

            stack.append(
                str(opr[x](int(a), int(b)))
            )  # evaluate the 2 values popped from stack & push result to stack
            # output in tabular format
            print(
                x.rjust(8),
                ("push(" + a + x + b + ")").ljust(12),
                ",".join(stack),
                sep=" | ",
            )

    return int(stack[0])


if __name__ == "__main__":
    Postfix = input("\n\nEnter a Postfix Equation (space separated) = ").split(" ")
    print("\n\tResult = ", solve(Postfix))

# Unit Test 1: post_fix = ['5', '6', '9', '*', '+']
# Expected Output: 59
assert solve(['5', '6', '9', '*', '+']) == 59

# Unit Test 2: post_fix = ['2', '3', '4', '*', '+']
# Expected Output: 14
assert solve(['2', '3', '4', '*', '+']) == 14

# Unit Test 3: post_fix = ['1', '2', '3', '*', '+']
# Expected Output: 7
assert solve(['1', '2', '3', '*', '+']) == 7

# Unit Test 4: post_fix = ['9', '8', '7', '*', '+']
# Expected Output: 79
assert solve(['9', '8', '7', '*', '+']) == 79

# Unit Test 5: post_fix = ['4', '5', '6', '*', '+']
# Expected Output: 34
assert solve(['4', '5', '6', '*', '+']) == 34

print("All unit tests pass")