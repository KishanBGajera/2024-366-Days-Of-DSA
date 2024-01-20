# Interpolation Search

- Interpolation search is an algorithm for searching for a specific key value in a sorted array.
- It is an improvement over binary search, especially when the elements in the array are uniformly distributed.
- The basic idea behind interpolation search is to use the distribution of values to estimate the likely position of the target key.
- At every iteration/recursion it finds the position to search using,
$$ \text{position} = \text{low} + \left( \frac{\text{high} - \text{low}}{\text{array[high]} - \text{array[low]}} \right) \times (\text{target} - \text{array[low]}) $$
- The formula considers the proportional relationship between the difference in values at the current search boundaries (`array[high] - array[low]`) and the difference between the target value and the lower boundary. It scales this proportion to estimate the likely position of the target within the array.

## Algorithm
```python
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
```

## Time Complexity:
- Best case: when elements are uniformly distributed, the interpolation formula converges quickly, resulting in $T(n) = O(1)$.
- Average and Worst case: under the assumption of a uniform distribution of keys, the interpolation search has a time complexity of $T(n) = O(\log \log n)$. However, in the presence of unevenly distributed keys, the performance may degrade to O(n).

