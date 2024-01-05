# Selection Sort
> This MarkDown is written as per my understanding of the algorithm.

- Selection Sort is a sorting algorithm which "selects" the minimum (or maximum, as per requirement) element's index and swaps it with the left-most not-yet-sorted element's index.
> **Not suitable** for lardge datasets/arrays.

## Algorithm
- Traverse from left to right, find the index of smallest (or largest) element of the array, and swap it with the current indexed element.
- repeat this for $n$-times.

$\rightarrow$ After the first pass, the smallest element will be sent to left-most part of the array, and continuing it for $n$-times ($n$ = number of elements), all the elements will be sorted.

## Complexity Analysis:
- Algorithm:
```python
def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i 
        for j in range(i + 1, len(arr)): 
            if arr[min_idx] > arr[j]: 
                min_idx = j 
                        
        arr[i], arr[min_idx] = arr[min_idx], arr[i]        
```

### Time Complexity
- As shown in the algorithm above, it has to iterate through the array atleast once **+** find minimum from the rest of the array, and so, the Time Complexity, $T(n) = O(n^2)$

### Space Complexity
- It doesn't take up more space than already given (in-place algorithm) and so, it works in $constant$ space.
- So, the Space Complexity, $S(n) = O(1)$

## Key Points
- Selection Sort is good for small-lengthed arrays.
- $T(n) = O(n^2)$
- $S(n) = O(1)$
- Selection Sort is a **in-place** and **stable** algorithm.