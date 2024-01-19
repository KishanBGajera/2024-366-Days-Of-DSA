# Heap Data Structure
> _source(s): GeeksForGeeks, Wikipedia_

- A Heap is a tree-based data structure that satisfies the **heap property**:
    - In a _max heap_, for any given node $C$ _(child)_, if $P$ is a parent node of $C$, then the key of $P$ is greater than or equal to the key of $C$.
    - In a _min heap_, the key of $P$ is less than or equal to the key of $C$.
- The node at the "`top`" of the heap (with no parents) is called the _root_ node.

## Operations of Heap Data Structure
- **Heapify**
    - The process in which the array or the binary tree is reshaped into a Heap data structure.
- **Insertion**
    - The process of inserting an element in existing heap.
    - time complexity: $O(log(n))$
- **Deletion**
    - The process of deleting the "top" element of the heap and returning the element
    - time complexity: $O(log(n))$
- **Peek**
    - to check or find the first (or the "`top`") element of the heap.
    - time complexity: $O(1)$

## Why use Heap Data Structure?
- A heap is a useful data strucure when it is necessary to repeatedly remove the object with the highest (or lowest) priority, or when insertions need to be interspersed with removals of the root node.

- Additionally, Heaps are used in many famous algorithms such as Dijkstra's algorithm for finding the shortest path, the heap sort sorting algorithm, implementing priority queues, and more. Essentially, heaps are the data structure you want to use when you want to be able to access the maximum or minimum element very quickly.

### Power of Heap
- While working with an unsorted array (say, `[2, 4, 1, 6, 9, <empty>]`)
    - `insert(10)`
        - $T(n) = O(1)$
        - Array allows random access, We just need to know the last empty index.
    - `search(6)`
        - $T(n) = O(n)$
        - Have to traverse through the array of length `n`.
    - `findMin()`
        - $T(n) = O(n)$
        - Have to traverse through the array of length `n`.
    - `deleteMin()`
        - $T(n) = O(n)$
        - Find min ($O(n)$), then delete it.
- with sorted array (say, `[1, 2, 4, 6, 9, <empty>]`)
    - `insert(7)`
        - $T(n) = O(n)$
        - Insertion algorithm, move elements.
    
    - `search(6)`
        - $T(n) = O(nlog(n))$
        - Binary Search

    - `findMin()`
        - $T(n) = O(1)$
        - First (or last) element would be minimum.

    - `deleteMin()`
        - $T(n) = $O(n)$ if array is sorted ASC else $O(1)$
        - Can't leave void at the start point.
- with LinkedList (say, `2 -> 4 -> 1 -> 6 -> 9 -> None`)
    - `insert`
        - `insert_at_beginning(<value>)`:
            - $T(n) = O(1)$
            - Links updation at the beginning.
        - `insert_at_end(<value>)`:
            - without tail:
                - $T(n) = O(n)$
                - have to traverse through the whole linked list the find the end
            - with tail:
                - $T(n) = O(1)$
                - links updatation at the end.
        - `insert_after(<reference>, <value>)`
            - $T(n) = O(n)$
            - have to traverse through whole linked list
    - `delete`
        - same complexities as insertion for respective places.
    - `find_min()`
        - $T(n) = O(n)$
        - have to travere through whole linked list

- Working with Heaps:
    - `insert(<value>)`
        - $T(n) = O(log(n))$
        - Heapify (To satisfy heap properties)
    - `find_min()`: (for a min heap)
        - $T(n) = O(1)$
        - in a **Min Heap**, the minimum element sits on the very first index, always.
    - `find_max()`: (for a max heap)
        - $T(n) = O(1)$
        - in a **Max Heap**, the maximum element sits on the very first index, always.
    - `heapify()`:
        - $T(n) = O(log(n))$

### The applications
1. Priority Queues
    - Scheduling Tasks
    - Handling Interruptions
    - Processing Events
2. Sorting Algorithms
    - [Heapsort](<../../../Algorithms/Sorting/Heap Sort>), $T(n) = O(nlog(n))$
3. Graph Algorithms
    - Dijkstra's Shortest Path Algorithm
    - Prim's Minimum Spanning Tree Algorithm
    - A* Search Algorithm
4. File Compression
    - Huffman Coding (Min Heap)
5. Dynamic Programming
    - Greedy Algorithms

