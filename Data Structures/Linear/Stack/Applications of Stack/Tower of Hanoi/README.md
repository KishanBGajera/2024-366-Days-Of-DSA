# Tower of Hanoi

- The **Tower of Hanoi** (also called **The problem of Benares Temple** or **Tower of Brahma** or **Lucas' Tower** and sometimes pluralized as **Towers**, or simply **pyramid puzzle**) is a mathematical game or puzzle consisting of three rods and a number of disks of various diameters, which can slide onto any rod. The puzzle begins with the disks stacked on one rod in order of decreasing size, the smallest at the top, thus approximating a conical shape. The objective of the puzzle is to move the entire stack to one of the other rods, obeying the following rules:

    1. Only one disk may be moved at a time.
    2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
    3. No disk may be placed on top of a disk that is smaller than it.

- With three disks, the puzzle can be solved in seven moves. The minimal number of moves required to solve a Tower of Hanoi puzzle is $2^n - 1$, where $n$ is the number of disks.
> _source:_ [Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi)

## Solution for n Disk
1. Move $n - 1$ Disks from $A$ to $B$ using $C$
2. Move a Disk from $A$ to $C$
3. Move $n - 1$ Disks from $B$ to $C$ using $A$
 
> _learnt from (the GOAT's):_ [YouTube/Abdul Bari/Algorithms](https://www.youtube.com/watch?v=q6RicK1FCUs) _and_ [YouTube/Reducible](https://www.youtube.com/watch?v=rf6uf3jNjbo)

## Solution Explanation
> _(following_ `main.c` _located in_ `./C/`_)_

- "stack.h" is explained in `../README.md`
- `Tower` struct which includes a `Stack` pointer, and `name` (`Tower`'s name, in one character, i.e., A, B, or C)
- `void printTowers(Tower* A, Tower* B, Tower* C)` prints Towers in Stack format the way they would actually have looked like, _if they were tangible or simulated._
> note: This function isn't consistently printing Towers `A`, `B`, and `C`, they are getting interchanged, _as per the program logic._
- `void moveToTower(Tower* source, Tower* destination)`, as the name suggests, moves a disk from `source` Tower to `destination` Tower.

- ### Tower of Hanoi
    - `void towerOfHanoi(int n, Tower* A, Tower* B, Tower* C)`
    - **Parameters**
        - `n`: The number of disks to be moved.
        - `A`, `B`, `C`: Pointers to Tower structures representing the source, auxiliary, and target towers, respectively.

    - **Algorithm**
        - The function recursively moves n disks from the source tower (A) to the target tower (C) using the auxiliary tower (B) as an intermediate step. The process follows the Tower of Hanoi rules:

            1. Move the top n-1 disks from the source tower (A) to the auxiliary tower (B).
            2. Move the bottom disk from the source tower (A) to the target tower (C).
            3. Print the current state of the towers after each move.
            4. Move the n-1 disks from the auxiliary tower (B) to the target tower (C).
> _Visual representation to be added here_

## Recursive Problem Solving
- Let $f(n)$ be a recursive function
    1. Show $f(1)$ works _(base case)_
    2. Assume $f(n - 1)$ works
    3. Show $f(n)$ works using $f(n - 1)$
> _Tips from_ [YouTube/Reducible](https://www.youtube.com/watch?v=rf6uf3jNjbo)
