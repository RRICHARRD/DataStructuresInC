#ifndef BINARYTREE_SPECIFICATION
#define BINARYTREE_SPECIFICATION

#include <stdlib.h>

/**
 * 
 * @brief A node structure of Tree data structure
 * 
 * @attention Use TreeNode to referes a struct treeNode
 * 
 * @param leter {char} A letter to store inside the node
 * @param parent {TreeNode *} Address of parent
 * @param left {TreeNode *} Address of left TreeNode
 * @param right {TreeNode *} Address of right TreeNode
 */
typedef struct treeNode {
    char *letter;
    struct treeNode *parent;
    struct treeNode *left;
    struct treeNode *right;
} TreeNode;

/**
 * @brief Create a tree node with parent, left and right address defined to NULL
 * 
 * @param letter A letter to store inside the node
 * @return TreeNode* 
 */
TreeNode *create_tree_node(char *letter);

/**
 * @brief Get inside value of node
 * 
 * @param node Address of the node I need to get the value
 * @return int 
 */
char *get_node_value(TreeNode *node);

#endif