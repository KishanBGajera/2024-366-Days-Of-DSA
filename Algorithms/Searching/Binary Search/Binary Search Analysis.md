# Binary Search
> This MarkDown is written as per my understanding of the algorithm.

- Binary Search is a very efficient and widely used searching algorithm.
- It uses [**divide and conquer**](https://www.geeksforgeeks.org/introduction-to-divide-and-conquer-algorithm-data-structure-and-algorithm-tutorials/) approach for solving the problem (searching).
- In order to apply Binary Sort on any dataset/array, it has to be sorted (ascending or descending).

## Algorithm

```c
int BinarySearch(int *arr, int target, int l, int h){
    if(l <= h){
        int m = (l + h)/2;
        if(arr[m] == target){
            return m; // target index
        }
        else if(target < arr[m]){
            l = m + 1;
            return BinarySearch(arr, target, l, h);
        }
        else{
            h = m - 1;
            return BinarySearch(arr, target, l, h);
        }
    }
    else{
        return -1; // if not found
    }
}
```

### Explanation
- As stated already, Binary Search is a **Divide and Conquer** Algorithm.
- When the low index (smallest index, `l`) is _less than or equal to_ high index (highest index, `h`) of the array (or, part of it),
    - it finds the middle index (`m`) and check,
    - if $m$-th indexed element (`arr[m]`) _is equal to_ the target value (`target`):
        - it returns $m$ (the target index).
    - else if the target value (`target`)  _is greater than_ $m$-th indexed element (`arr[m]`):
        - it sets low index (`l`) as mid index + 1 (`m+1`), and discards the other half of the array from the algorithm.
        - and recurses and check for the element in the other half of the array.
    - else
        - since, the target wasn't found in the middle and in the right-half of the array, if it is present in the array, it must in the left-half.
        - So, the high (`h`) is set to mid index - 1 (`mid-1`), and discards the other half of the array from the algorithm.
        - and recurses and check for the element in the other half of the array.
- If `l <= h` is `false`, then Binary Search has worked exhaustively and still hasn't found the element, that means, that the element is not present in the array.
    - then, it returns `-1` as a sentinel value of "Element Not Found" indicator.
> _learn about_ [sentinel values](https://en.wikipedia.org/wiki/Sentinel_value)

## Complexity Analysis
### Time Complexity
-  It recursively eliminates half of the array elements until the `target` is found.
- so, the number of times the functions has to recurse (or the loop has to iterate, in iterative implementation) is determined by $log(n)$,
    - eg., `arr` = [1, 2, 3, 4, 5, 6, 7, 8], `target` = 7.
    
    - `l` = 0, `h` = 7 $\rightarrow$ `l <= h` -$true$-> `m = (l + h)/2` $\rightarrow$ `m` = (0+7)/2 $\rightarrow$ `m` = 3.
    
    - `arr[m]` = `arr[3]` = 4 != 7 > 4.
    
    - `l` = m + 1 = 5, `h` = 7 $\rightarrow$ `l <= h` -$true$-> `m=(l + h)/2` $\rightarrow$ `m` = (5 + 7)/2 $\rightarrow$ `m` = 6

    - `arr[m]` = `arr[6]` = 7 == 7 (_returns `6`_)

- as shown in the example above, it took `2` function calls (or loop iterations), to find the target element.
- the way, if we wanted to find `8`, it would have taken us `3` function calls.

- $log_2{(n)} = log_2{(8)} = 3$
- So, it would never take more than `3` function calls to find ANY element from the list, and so, Time Complexity, $T(n) = O(log_2(n))$

### Space Complexity
- Since, it doesn't take any more space than already given, it uses $constant$ space, and so, Space Complexity $S(n) = O(1)$

## Remarks
- It is a highly practical way of searching through a sorted array/dataset.
> _check out:_ [Binary Search vs. Linear Search Analysis](<../Binary Search vs. Linear Search Analysis/README.md>)