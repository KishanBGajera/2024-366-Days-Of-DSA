from random import choice

def binary_search(arr: list, target: int, l: int, h: int) -> int:
    if l <= h:
        m = int((l + h)/2)
        if arr[m] == target:
            return m
        elif arr[m] < target:
            l = m + 1
            return binary_search(arr, target, l, h)
        else:
            h = m - 1
            return binary_search(arr, target, l, h)
    else:
        return -1

arr = [2, 3, 6, 7, 10, 12, 34, 35, 56, 67, 69, 73, 78, 81, 90, 95] # MUST BE SORTED (ASC or DESC, but according to our logic, it must be ASC)

for _ in range(5):
    target = choice(arr)
    idx = binary_search(arr, target, 0, len(arr))
    print(f"{target} at {idx}")
