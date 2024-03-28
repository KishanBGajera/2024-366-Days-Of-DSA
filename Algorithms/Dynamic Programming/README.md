# Dynamic Programming

## Prefix Sum
```py
def sum_till_n(n: int) -> int:
    sums = [i for i in range(n)]

    for i in range(1, n):
        sums[i] += sums[i-1]

    return sums
    
print(sum_till_n(11))
```

## DP
### Where to apply DP?
1. **Optimal Substructure**
    - breaking it down:
        - **Optimal** : the best, most favorable
        - **Substructure** : a subproblem of a main problem.
    - A problem has Optimal Substructure property when its Optimal Solution can be constructed from that of its subproblems.

2. **Overlapping Subproblems**
    - "While solving a complex problem, it may occur that a part of what it takes to solve it, has already been calculated - performed in the process of solving that same problem" - It is called Overlapping Subproblems.
    - Now, it depends on us to reduce or discard the process of solving the (sub) problems which have already been solved.
    - for example, recursion tree of fibonacci function:
        - program:
        ```python
        def fibonacci(n: int) -> int:
            if n == 0 or n == 1:
                return n # or `1` (as per you logic)
            else:
                return fibonacci(n - 1) + fibonacci(n - 2)

        fibonacci(4)
        ```
        
        - recursion tree:
        ```mermaid
        graph TD;
        A[fibonacci 4]
        B[fibonacci 3]
        C[fibonacci 2]
        D[fibonacci 1]
        E[fibonacci 0]
        F[fibonacci 1]
        G[fibonacci 2]
        H[fibonacci 0]
        I[fibonacci 1]
        A --> B
        A --> C
        B --> D
        B --> G
        C --> E
        C --> F
        G --> H
        G --> I
        ```

        ```python
        def fibonacci_with_DP(n: int) -> int:
            if n <= 0:
                return
            if n == 1:
                return 0

            fib = [0] * (n)
            fib[1] = 1

            for i in range(2, n):
                fib[i] = fib[i - 1] + fib[i - 2]

            return fib[-1]
        ```

### DP Problem Solving
1. Define Objective Function
2. Identify Base Case
3. Recurrence Relation
4. Order of Computation
5. Location of the Answer

### Approach DP by steps below:
1. Visualize Example
2. Find an appropriate subproblem
3. Find relationships among subproblems
4. Generalize the relationship
5. Implement by solving subproblems in order

### Maze Problem

```py
def grid_paths(n, m):
    dp = [[0]*m for _ in range(n)]

    for i in range(1, n + 1):
        dp[i][1] = 1
    for j in range(1, m + 1):
        dp[1][j] = 1

    for i in range(2, n + 1):
        for j in range(2, m + 1):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]

    return dp[n][m]
```
