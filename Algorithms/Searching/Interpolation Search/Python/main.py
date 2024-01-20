def interpolation_search(arr, target, low, high):
    if low < high and arr[low] <= target <= high:
        position = low + ((high - low)//(arr[high] - arr[low])) * (target - arr[low])

        if arr[position] == target:
            return position
        elif arr[position] < target:
            return interpolation_search(arr, target, position + 1, high)
        else:
            return interpolation_search(arr, target, low, position - 1)
    return -1

arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
n = len(arr)

pos = interpolation_search(arr, 8, 0, n - 1)
print(pos)