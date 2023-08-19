
#include <stdio.h>

#include <BinaryTree.h>

/*
    A binary tree is a tree in which every node has at most two children. Can ONE but not more then TWO

    types of binary`s trees

        Full Binary Tree → A binary tree in which every node has 2 children except the leaves is known as a full binary tree.
*/

int main() {
    TreeNode *node = (TreeNode *) create_tree_node(1);

    printf("node value is: %d\n", get_node_value(node));

    return 0;
}