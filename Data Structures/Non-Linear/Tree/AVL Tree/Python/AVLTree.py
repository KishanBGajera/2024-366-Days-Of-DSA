class AVLTree:
    class AVLNode:
        def __init__(self, value):
            self.value = value
            self.left = None
            self.right = None
            self.height = 1

    def __init__(self):
        self.root = None

    def height_of_node(self, node):
        if not node:
            return 0
        else:
            return 1 + max(self.height_of_node(node.left), self.height_of_node(node.right))

    def get_balance(self, node):
        if not node:
            return 0
        else:
            return self.height_of_node(node.left) - self.height_of_node(node.right)

    def right_rotate(self, root):
        left = root.left
        right_of_left = left.right

        left.right = root
        root.left = right_of_left

        root.height = 1 + max(self.height_of_node(root.left), self.height_of_node(root.right))
        left.height = 1 + max(self.height_of_node(left.left), self.height_of_node(left.right))

        return left # new root

    def left_rotate(self, root):
        right = root.right
        left_of_right = right.left

        right.left = root
        root.right = left_of_right

        root.height = 1 + max(self.height_of_node(root.left), self.height_of_node(root.right))
        right.height = 1 + max(self.height_of_node(right.left), self.height_of_node(right.right))

        return right

    def insert(self, data):
        self.root = self._insert(self.root, data)

    def _insert(self, root, data):
        if not root:
            return self.AVLNode(data)

        if data < root.value:
            root.left = self._insert(root.left, data)
        elif data > root.value:
            root.right = self._insert(root.right, data)
        else:
            return root

        root.height = 1 + max(self.height_of_node(root.left), self.height_of_node(root.right))

        balance = self.get_balance(root)

        if balance > 1 and data < root.left.value:
            return self.right_rotate(root)

        if balance < -1 and data > root.right.value:
            return self.left_rotate(root)

        if balance > 1 and data > root.left.value:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        if balance < -1 and data < root.right.value:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    def print_tree(self):
        self._print_tree(self.root)

    def _print_tree(self, root, level=0):
        if root:
            self._print_tree(root.right, level + 1)
            print("    " * level + str(root.value))
            self._print_tree(root.left, level + 1)

