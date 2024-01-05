from random import randint

def bubble_sort(arr):
    size = len(arr)
    for i in range(size):
        for j in range(i + 1, size):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]

arr = []

for _ in range(20):
    arr.append(randint(0, 100)) # array[20] with random elements from [0, 100]

print("Before: ", arr)
bubble_sort(arr)
print("After : ", arr)
