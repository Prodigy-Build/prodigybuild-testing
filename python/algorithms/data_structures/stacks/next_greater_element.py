from typing import List

def next_greatest_element_slow(arr: List[float]) -> List[float]:
    result = []
    arr_size = len(arr)

    for i in range(arr_size):
        next_element: float = -1
        for j in range(i + 1, arr_size):
            if arr[i] < arr[j]:
                next_element = arr[j]
                break
        result.append(next_element)
    return result


def next_greatest_element_fast(arr: List[float]) -> List[float]:
    result = []
    for i, outer in enumerate(arr):
        next_item: float = -1
        for inner in arr[i + 1 :]:
            if outer < inner:
                next_item = inner
                break
        result.append(next_item)
    return result


def next_greatest_element(arr: List[float]) -> List[float]:
    arr_size = len(arr)
    stack: List[float] = []
    result: List[float] = [-1] * arr_size

    for index in reversed(range(arr_size)):
        if stack:
            while stack[-1] <= arr[index]:
                stack.pop()
                if not stack:
                    break
        if stack:
            result[index] = stack[-1]
        stack.append(arr[index])
    return result