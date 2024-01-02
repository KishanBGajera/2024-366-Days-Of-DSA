# Check README.md for explanation

from stack import Stack

class Tower:
    def __init__(self, name: chr, size: int) -> None:
        self.name = name
        self.stack = Stack(size)

    def move_to_tower(self, destination) -> None:
        disk = self.stack.pop()
        destination.stack.push(disk)
        print(f"Disk {disk} moved from Tower {self.name} to Tower {destination.name}")

def print_towers(A: Tower, B: Tower, C: Tower) -> None:
    max_top = max(A.stack.top, B.stack.top, C.stack.top)
    max_top += 1

    counter = max_top
    print("Towers:")

    for i in range(max_top, 0, -1):
        counter -= 1

        if i <= A.stack.top + 1:
            print(f"| {A.stack.data[counter]} |", end=' ')
        else:
            print("|   |", end=' ')

        if i <= B.stack.top + 1:
            print(f"| {B.stack.data[counter]} |", end=' ')
        else:
            print("|   |", end=' ')

        if i <= C.stack.top + 1:
            print(f"| {C.stack.data[counter]} |", end=' ')
        else:
            print("|   |", end=' ')
        
        print()
    
    print("_____ _____ _____")
    print(f"| {A.name} | | {B.name} | | {C.name} |")

def tower_of_hanoi(n, A, B, C):
    if n > 0:
        tower_of_hanoi(n - 1, A, C, B)
        A.move_to_tower(C)
        print_towers(A, B, C)
        tower_of_hanoi(n - 1, B, A, C)

if __name__ == "__main__":
    n = int(input("Enter number of Disks: "))

    A = Tower('A', n)
    B = Tower('B', n)
    C = Tower('C', n)

    for i in range(n, 0, -1):
        A.stack.push(i)

    tower_of_hanoi(n, A, B, C)
