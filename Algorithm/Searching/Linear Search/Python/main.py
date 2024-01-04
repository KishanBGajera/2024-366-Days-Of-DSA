from random import randint, choice # 'cause I am lazy

def linear_search(arr: list, target: int) -> int:
    for idx, elem in enumerate(arr):
        if elem == target:
            return idx

# loop for multiple random tests
for _ in range(10):
    arr = [randint(0, 50) for __ in range(20)] # 20 random numbers
    target = choice(arr) # because we wouldn't know any number from the list (since, it was generated 'randomly')

    print(f"arr: {arr}")
    print(f"target: {target}")
    print(f"idx: {linear_search(arr, target)}")

    print()