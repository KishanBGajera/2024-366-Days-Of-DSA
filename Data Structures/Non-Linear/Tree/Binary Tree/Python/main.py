from binary_tree import *

binaryTree = BinaryTree(TreeNode(10))

binaryTree.insert_to_bin_tree(10, 5, -1)
binaryTree.insert_to_bin_tree(10, 15, 1)
binaryTree.insert_to_bin_tree(5, 0, -1)
binaryTree.insert_to_bin_tree(5, 7, 1)

binaryTree.print_tree(binaryTree.root, 0, target=0)
