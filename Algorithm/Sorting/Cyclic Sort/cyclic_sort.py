def cyclic_sort(arr):
    for i in range(len(arr)):
        while arr[i] != i + 1:
            arr[arr[i] - 1], arr[i] = arr[i], arr[arr[i] - 1]

arr = [1, 2, 3, 9, 8, 7, 5, 4, 6]
print("Original array:", arr)
cyclic_sort(arr)
print("Array after cyclic sort:", arr)
