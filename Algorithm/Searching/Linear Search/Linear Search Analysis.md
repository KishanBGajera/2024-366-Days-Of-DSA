# Linear Search
> This MarkDown is written as per my understanding of the algorithm.
- Linear Search is highly intuitive, naive (and impractical) approach of searching an element from an array.

## Algorithm

```python
def LinearSearch(arr, size, target):
    for idx, elem in enumerate(arr):
        if elem == target:
            return idx
    return -1 # sentinel value
```
> _learn about_ [enumerate](https://docs.python.org/3/library/functions.html#enumerate)

### Explanation
- As intuitive as it gets, it just starts from the left-most (0th) element and starts comparing all the elements with target value until it matches:
    - when `elem` _is equal to_ `target`, it returns the `elem`'s index (in our case, `idx`)
    - if, _after all the iteration or checking all the elements_, `target` doesn't match with **any** of them, it will return -1, as a sentinel value.
> _learn about_ [sentinel values](https://en.wikipedia.org/wiki/Sentinel_value)

## Complexity Analysis
### Time Comlexity
- Since, `elem`s are compared once, and you can never be sure that where you might encounter `target`, it, inevitably, has to run for $linear$ time, and so, Time Complexity, $T(n) = O(n)$.

### Space Complexity
- Since, it doesn't use more space than already given (`arr`), it uses $constant$ space, and so, Space Complexity, $S(n) = O(1)$.

## Remarks
- Not a practical way to search through large datasets.
- Only feasible for small dataset/array. (if compared with [Binary Search](<../Binary Search>), better only when `n` < 10, _which is not practical at all._)
> _check out:_ [Binary Search vs. Linear Search Analysis](<../Binary Search vs. Linear Search Analysis/README.md>)