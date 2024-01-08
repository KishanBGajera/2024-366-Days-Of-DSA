def merge(arr, l, h, m):
    n1 = m - l + 1
    n2 = h - m

    L = [arr[l + i] for i in range(n1)]
    R = [arr[m + 1 + j] for j in range(n2)]

    i = j = 0
    k = l

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort(arr, l, h):
    if l < h:
        m = (l + h) // 2

        merge_sort(arr, l, m)
        merge_sort(arr, m + 1, h)

        merge(arr, l, h, m)

arr = [9, 7, 3, 6, 1, 7, 8, 2, 3]
n = len(arr)

print("Original array:", arr)
merge_sort(arr, 0, n - 1)
print("Sorted array:", arr)
