import matplotlib.pyplot as plt
from random import randint, choice

def linear_search(arr: list, target: int) -> int:
    count = 0
    for idx, elem in enumerate(arr):
        count += 1
        if elem == target:
            return count

global_count = 0  # Use a different global variable name
def binary_search(arr: list, target: int, l: int, h: int) -> int:
    global global_count  # Declare count as a global variable
    global_count += 1
    if l <= h:
        m = (l + h) // 2
        if arr[m] == target:
            return global_count
        elif arr[m] < target:
            l = m + 1
            return binary_search(arr, target, l, h)
        else:
            h = m - 1
            return binary_search(arr, target, l, h)
    else:
        return -1

# ns = [5, 10, 20, 50, 100, 500, 1000,]
n = 5

arr = [randint(0, n * 2) for _ in range(n)]
arr.sort()  # Sorted array for searching

lis = []
bis = []


for i in arr:
    idx1 = linear_search(arr, i)
    lis.append(idx1)

    global_count = 0  # Reset global_count for each binary search
    idx2 = binary_search(arr, i, 0, len(arr))
    bis.append(idx2)

number_of_operations = [i for i in range(1, n + 1)]

plt.scatter(number_of_operations, lis, label='Linear Search')
plt.scatter(number_of_operations, bis, label='Binary Search')
plt.xlabel('Index')
plt.ylabel('Number of Operations')
plt.legend()
plt.show()
