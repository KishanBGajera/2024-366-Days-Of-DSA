from AVLTree import AVLTree


avl_tree = AVLTree()
keys = [10, 20, 30, 40, 50, 25, 55]

for key in keys:
    avl_tree.insert(key)

print("AVL Tree:")
avl_tree.print_tree()
