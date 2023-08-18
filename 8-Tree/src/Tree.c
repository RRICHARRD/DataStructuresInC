#ifndef STATIC_QUEUE_IMPLEMENTATION
#define STATIC_QUEUE_IMPLEMENTATION

#include <Tree.h>

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

#endif