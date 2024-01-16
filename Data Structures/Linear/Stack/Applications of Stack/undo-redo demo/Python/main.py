from stack import Stack

def print_menu():
    print(">>> Choose an operator:")
    print("...\t\t +: addition")
    print("...\t\t -: subtraction")
    print("...\t\t *: multiplication")
    print("...\t\t /: division")
    print("...\t\t u: undo")
    print("...\t\t r: redo")
    print("...\t\t e: EXIT")

def get_user_input():
    choice = input(">>> Enter choice: ")
    operand = 0

    if choice not in ['u', 'r', 'e']:
        operand = int(input(">>> Enter another operand: "))

    return choice, operand


def operate(main_operand, another_operand, operator, undo, redo):
    if operator == 'r':
        undo.push(main_operand)
        main_operand = redo.pop()
        return main_operand

    if operator == 'u':
        redo.push(main_operand)
        main_operand = undo.pop()
        return main_operand

    else:
        undo.push(main_operand)

        if operator == '+':
            main_operand += another_operand
        elif operator == '-':
            main_operand -= another_operand
        elif operator == '*':
            main_operand *= another_operand
        elif operator == '/':
            main_operand /= another_operand
        else:
            print("Invalid Operator")
            undo.pop()

        return main_operand


def main():
    undo = Stack(10)
    redo = Stack(10)

    current_value = 0

    while True:
        print(">>> Current Value:", current_value)
        print_menu()

        choice, another_operand = get_user_input()

        if choice != 'e':
            current_value = operate(current_value, another_operand, choice, undo, redo)
        else:
            break


if __name__ == "__main__":
    main()
