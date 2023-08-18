#ifndef BINARYTREE_IMPLEMENTATION
#define BINARYTREE_IMPLEMENTATION

#include <BinaryTree.h>

/**
 * @brief A node structure of Tree data structure
 * 
 * @attention Use TreeNode to referes a struct treeNode
 * 
 * @param data {int} An information to store inside the tree
 * @param parent {TreeNode *} Address of parent
 * @param left {TreeNode *} Address of left TreeNode
 * @param right {TreeNode *} Address of right TreeNode
 */
typedef struct treeNode {
    int data;
    struct treeNode *parent;
    struct treeNode *left;
    struct treeNode *right;
} TreeNode;

/**
 * @brief Create a tree node with parent, left and right address defined to NULL
 * 
 * @param value A number to store inside the node
 * @return TreeNode* 
 */
TreeNode *create_tree_node(int value) {
    TreeNode *new_tree_node = (TreeNode *) calloc(1, sizeof(TreeNode)); 
    new_tree_node->data = value;
    
    return new_tree_node;
}

/**
 * @brief Get inside value of node
 * 
 * @param node Address of the node I need to get the value
 * @return int 
 */
int get_node_value(TreeNode *node) {
    return node->data;
}

#endif