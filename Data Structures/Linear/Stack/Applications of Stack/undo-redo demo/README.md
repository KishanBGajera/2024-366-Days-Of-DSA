## Undo-Redo on a Calculator

This program is a simple calculator implemented in C, allowing basic arithmetic operations (addition, subtraction, multiplication, division) with the ability to undo and redo operations. The undo-redo functionality is implemented using stacks.

### Functionality:

- **Print Menu (`printMenu`):** This function displays the menu of available operations to the user.

- **Get User Input (`getUserInput`):** This function prompts the user to enter their choice of operation and, if applicable, an operand. It handles the input of both operators and operands.

- **Operate (`operate`):** This function performs the selected operation on the current value. It also handles the undo-redo functionality:
  - If the operator is 'u' (undo), it pops the last operation from the undo stack and applies it.
  - If the operator is 'r' (redo), it pops the last operation from the redo stack and applies it.
  - If the operator is an arithmetic operator, it performs the corresponding operation and pushes the current value onto the undo stack before the operation.

- **Main Function (`main`):** The main function initializes two stacks (undo and redo) and the current value to 0. It then enters a loop where it repeatedly displays the current value, the menu, and prompts the user for input. Based on the user's choice, it calls the operate function or exits the program if the choice is 'e' (exit).

### Undo-Redo Functionality:

The undo-redo functionality allows the user to revert or redo operations performed on the calculator. It is implemented using two stacks:
- **Undo Stack:** Stores the previous states of the calculator before each operation.
- **Redo Stack:** Stores the states that were undone, allowing the user to redo them if needed.

When an operation is performed:
- The current state is pushed onto the undo stack.
- If the user chooses to undo an operation, the most recent state is popped from the undo stack and applied. The undone state is then pushed onto the redo stack.
- If the user chooses to redo an operation, the most recent undone state is popped from the redo stack and applied. The redone state is then pushed onto the undo stack.

### How Exactly Can It Look Like In An Actual Implementation?
- In an actual implementation, or in an needed one, the stacks may have "`state`" type of elements stacked onto them, these "states" can be anything, for example, in an image editing software, "image before a paint stroke" is a `state`, and "image after a paint stroke" is another `state`, which be undo-redo-ed as per your needs, by keeping the undo-redo principals intact. 

### Applications in Computer Science Paradigms:

- **Imperative Paradigm:** In imperative programming, the undo-redo functionality can be useful in applications where users need to perform reversible actions, such as text editors, graphics editors, or even version control systems.

- **Object-Oriented Paradigm:** In object-oriented programming, this functionality can be encapsulated within objects, making it easier to manage and extend. Each operation can be represented by an object with methods for undo and redo.

- **Functional Paradigm:** In functional programming, the undo-redo functionality can be implemented using immutable data structures and recursion. Each operation creates a new state, and undo-redo operations navigate through these states using recursive functions.

- **Logic Paradigm:** In logic programming, the undo-redo functionality can be implemented using backtracking techniques. Each operation can be considered a choice point, and undo-redo operations navigate through these choices using backtracking algorithms.

Overall, the undo-redo functionality enhances the user experience by providing flexibility and control over actions performed in various computational paradigms.