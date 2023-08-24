#ifndef BINARYTREE_IMPLEMENTATION
#define BINARYTREE_IMPLEMENTATION

#include <Tree.h>

/**
 * @brief A node structure of Tree data structure
 * 
 * @attention Use TreeNode to referes a struct treeNode
 * 
 * @param letter {char} A leeter to store inside the node
 * @param parent {TreeNode *} Address of parent
 * @param left {TreeNode *} Address of left TreeNode
 * @param right {TreeNode *} Address of right TreeNode
 */
typedef struct treeNode TreeNode;

/**
 * @brief Create a tree node with parent, left and right address defined to NULL
 * 
 * @param letter A letter to store inside the node
 * @return TreeNode* 
 */
TreeNode *create_tree_node(char *letter) {
    TreeNode *new_tree_node = (TreeNode *) calloc(1, sizeof(TreeNode)); 
    new_tree_node->letter = letter;
    
    return new_tree_node;
}

/**
 * @brief Get inside value of node
 * 
 * @param node Address of the node I need to get the value
 * @return int 
 */
char *get_node_value(TreeNode *node) {
    return node->letter;
}

#endif