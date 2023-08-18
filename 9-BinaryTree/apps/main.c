
#include <stdio.h>

#include <BinaryTree.h>


int main() {
    TreeNode *node = (TreeNode *) create_tree_node(1);

    printf("node value is: %d\n", get_node_value(node));

    return 0;
}