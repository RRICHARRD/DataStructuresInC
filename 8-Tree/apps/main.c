

#include <stdio.h>

#include <Tree.h>

/*
    Reading theory to understand better

    non-linear data structure, before all was linear
    store data in a hierarchical order
    each node of a tree has children and parent, the concentual is the same of real trees

    Trees has details, I will learn them in the future to be more productive
*/


int main() {

    TreeNode *node = (TreeNode *) create_tree_node(1);

    printf("node value is: %d\n", get_node_value(node));

    return 0;
}