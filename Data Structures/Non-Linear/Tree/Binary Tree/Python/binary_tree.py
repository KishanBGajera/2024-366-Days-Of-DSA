class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self, root: TreeNode):
        self.root = root

    def get_tree_node(self, data):
        return TreeNode(data)

    def search_node(self, root, target):
        if root:
            if root.data == target:
                return root

            left_result = self.search_node(root.left, target)
            if left_result:
                return left_result

            right_result = self.search_node(root.right, target)
            if right_result:
                return right_result
        return None

    def insert_to_bin_tree(self, parent, child, which_child):
        parent_node = self.search_node(self.root, parent)
        if not parent_node:
            print(f"NodeNotInTreeError: Node({parent}) couldn't be found in the given Tree(root: {self.root.data})")
            return

        if which_child == -1:
            parent_node.left = self.get_tree_node(child)
        elif which_child == 1:
            parent_node.right = self.get_tree_node(child)

    def print_tree(self, tree_node, level, target):
        if tree_node:
            self.print_tree(tree_node.right, level + 1, target)
            for i in range(level):
                print("    ", end="")
            
            if tree_node.data == target:
                print("*", end="")
            
            print(tree_node.data)

            self.print_tree(tree_node.left, level + 1, target)

    def free_tree_node_memory(self, tree_node):
        del tree_node
