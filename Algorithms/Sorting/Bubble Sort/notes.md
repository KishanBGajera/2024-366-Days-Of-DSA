# Bubble Sort
> This MarkDown is written as per my understanding of the algorithm.

- It is the **simplest** sorting algorithm, which swaps two adjacent elements if they are in the wrong order.
> **Not suitable** for lardge datasets/arrays.

## Algorithm
- Traverse from left to right, while comparing adjacent elements,
    - if, in two adjacent elements, left one is smaller than the right one, **swap** them.
    - otherwise, keep traversing.

$\rightarrow$ After the first pass, the largest element will be sent to the right-most part of the array, and continuing it for $n$-times ($n$ = number of elements), all the elements will be sorted.

## Complexity Analysis:
- Algorithm:
```python
def bubble_sort(arr, size):
    # let n = size
    for i in range(size): # runs for `n` times
        for j in range(i + 1, size): # runs for `n` times
            if arr[i] > arr[j]: 
                arr[i], arr[j] = arr[j], arr[i]
```

### Time Complexity
- As indicated in the algorithm above, the outer loop (which runs for $n$-times), lets inner-loop run for $n$-times in one pass.
- Hence, the total number of times the inner-most statements will run = $n * n$ or $n^2$
- So, Time Complexity, $T(n) = O(n^2)$

### Space Complexity
- Since, It is an in-place algorithm, and doesn't take up more space then already given, it works in $constant$ space.
- So, Space Complexity, $S(n) = O(1)$
> _Learn about_ [in-place algorithms](https://en.wikipedia.org/wiki/In-place_algorithm)

## Key Points
- Bubble Sort is good for small-lengthed arrays.
- $T(n) = O(n^2)$
- $S(n) = O(1)$
- Bubble Sort is a **in-place** and **stable** algorithm.

#### What is a 'stable' algorithm?
- Suppose, We have an array `[8, 3, 5, 1, 5, 1]`
- The array contains two `1`s
- If the sorting algorithm sustains the order of those two `1`s, then it is a 'stable' algorithm, otherwise it is 'unstable' algorithm.

* Stable if, 
    * before: $[8, 3, 5_a, 1_a, 5_b, 1_b]$
    * after d: $[1_a, 1_b, 3, 5_a, 5_b, 6]$