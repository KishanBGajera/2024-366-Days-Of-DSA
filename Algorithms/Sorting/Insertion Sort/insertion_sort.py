def insertion_sort(arr):
    size = len(arr)
    for i in range(1, size):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

arr = [4, 2, 5, 1, 7, 8]
insertion_sort(arr)
print(arr)
