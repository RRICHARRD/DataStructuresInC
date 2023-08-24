#ifndef BINARYTREE_SPECIFICATION
#define BINARYTREE_SPECIFICATION

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Node strutucture to use in the Tree
 * 
 * @attention Utilize TreeNode to referst to struct treeNode
 * 
 * @param letter {char} A letter to store inside the node
 * @param left {TreeNode *} Address of left node in the tree
 * @param right {TreeNode *} Address of right node int the tree
 */
typedef struct treeNode TreeNode;

/**
 * @brief Tree structure, define only the root of tree
 * 
 * @attention Utilize Tree to refers to struct tree
 * 
 * @param root {TreeNode *} Root node of the tree
 * 
 */
typedef struct tree Tree;

/**
 * @brief Create a new node
 * 
 * @param letter A letter to store inside the node
 * @return TreeNode*
 */
TreeNode *create_new_node(char letter);

/**
 * @brief Create a new tree
 * 
 * @return Tree* 
 */
Tree *create_new_tree();

/**
 * @brief Show char inside the node
 * 
 * @param tn Node address where exists the letter to be viewed
 */
void show_node_value(TreeNode *tn, char *position);

/**
 * @brief Insert new node in specified position
 * 
 * @param td Parent node of the new node connection
 * @param position Position of connection, need to be 'left' or 'right' 
 * @param letter A letter to store inside the new node
 */
void insert(TreeNode *td, char *position, char letter);

/**
 * @brief Insert a node in root
 * 
 * @param t Tree structure reference
 * @param letter Letter to store inside the new node
 */
void define_root(Tree *t, char letter);

/**
 * @brief Get the root of Tree
 * 
 * @param t Tree structure
 */
TreeNode *get_root_node(Tree *t);

#endif