#ifndef STATIC_QUEUE_SPECIFICATION
#define STATIC_QUEUE_SPECIFICATION

#include <stdlib.h>

/**
 * 
 * @brief A node structure of Tree data structure
 * 
 * @attention Use TreeNode to referes a struct treeNode
 * 
 * @param data {int} An information to store inside the tree
 * @param parent {TreeNode *} Address of parent
 * @param left {TreeNode *} Address of left TreeNode
 * @param right {TreeNode *} Address of right TreeNode
 */
typedef struct treeNode TreeNode;

/**
 * @brief Create a tree node with parent, left and right address defined to NULL
 * 
 * @param value A number to store inside the node
 * @return TreeNode* 
 */
TreeNode *create_tree_node(int value);

/**
 * @brief Get inside value of node
 * 
 * @param node Address of the node I need to get the value
 * @return int 
 */
int get_node_value(TreeNode *node);

#endif