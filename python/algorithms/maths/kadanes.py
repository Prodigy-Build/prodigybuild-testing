test_data: tuple = ([-2, -8, -9], [2, 8, 9], [-1, 0, 1], [0, 0], [])

def negative_exist(arr: list) -> int:
    arr = arr or [0]
    max_number = arr[0]
    for i in arr:
        if i >= 0:
            return 0
        elif max_number <= i:
            max_number = i
    return max_number

def kadanes(arr: list) -> int:
    max_sum = negative_exist(arr)
    if max_sum < 0:
        return max_sum

    max_sum = 0
    max_till_element = 0

    for i in arr:
        max_till_element += i
        max_sum = max(max_sum, max_till_element)
        max_till_element = max(max_till_element, 0)
    return max_sum

if __name__ == "__main__":
    try:
        print("Enter integer values sepatated by spaces")
        arr = [int(x) for x in input().split()]
        print(f"Maximum subarray sum of {arr} is {kadanes(arr)}")
    except ValueError:
        print("Please enter integer values.")