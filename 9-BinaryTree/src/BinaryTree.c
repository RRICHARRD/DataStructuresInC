#ifndef BINARYTREE_IMPLEMENTATION
#define BINARYTREE_IMPLEMENTATION

#include <string.h> // strcmp -> 0 indicate lexicographic equivalence

#include <BinaryTree.h>

/**
 * @brief Node strutucture to use in the Tree
 * 
 * @attention Utilize TreeNode to referst to struct treeNode
 * 
 * @param letter {char} A letter to store inside the node
 * @param left {TreeNode *} Address of left node in the tree
 * @param right {TreeNode *} Address of right node int the tree
 */
typedef struct treeNode {
    char letter;
    struct treeNode *left;
    struct treeNode *right;
} TreeNode;

/**
 * @brief Tree structure, define only the root of tree
 * 
 * @attention Utilize Tree to refers to struct tree
 * 
 * @param root {TreeNode *} Root node of the tree
 */
typedef struct tree {
    TreeNode *root;
} Tree;

/**
 * @brief Create a new node
 * 
 * @param letter A letter to store inside the node
 * @return TreeNode*
 */
TreeNode *create_new_node(char letter) {
    TreeNode *new_tree_node = (TreeNode *) calloc(1, sizeof(TreeNode));
    new_tree_node->letter = letter;
    return new_tree_node;
}

/**
 * @brief Create a new tree
 * 
 * @return Tree* 
 */
Tree *create_new_tree() {
    return (Tree *) calloc(1, sizeof(Tree));
}

/**
 * @brief Show char inside the node
 * 
 * @param tn Node address where exists the letter to be viewed
 */
void show_node_value(TreeNode *tn, char *position) {
    if (strcmp(position, "left") != 0 && strcmp(position, "right") != 0 && strcmp(position, "current") != 0) {
        printf("EXCEPTION: POSITION ERROR | The node only have left, right and current posibilities to see the values");
        exit(EXIT_FAILURE);
    }

    TreeNode **node_position = (strcmp(position, "left") == 0) ? &tn->left : (strcmp(position, "right") == 0) ? &tn->right : &tn;
    printf("%c\n", (*node_position)->letter);
}

/**
 * @brief Insert new node in specified position
 * 
 * @param td Parent node of the new node connection
 * @param position Position of connection, need to be 'left' or 'right' 
 * @param letter A letter to store inside the new node
 */
void insert(TreeNode *tn, char *position, char letter) {
    if (strcmp(position, "left") != 0 && strcmp(position, "right") != 0) { // == validate memory address, reason to use strcmp =)
        printf("EXCEPTION: Strange insert positon | use 'right' or 'left'\n");
        exit(EXIT_FAILURE);
    }

    TreeNode *new_node = (TreeNode *) calloc(1, sizeof(TreeNode));
    new_node->letter = letter;

    TreeNode **node_position = (strcmp(position, "left") == 0) ? &tn->left : &tn->right;
    *node_position = new_node;
}

/**
 * @brief Insert a node in root
 * 
 * @param t Tree structure reference
 * @param letter Letter to store inside the new node
 */
void define_root(Tree *t, char letter) {
    TreeNode *new_node = (TreeNode *) calloc(1, sizeof(TreeNode));
    new_node->letter = letter;

    t->root = new_node; 
}

/**
 * @brief Get the root of Tree
 * 
 * @param t Tree structure
 */
TreeNode *get_root_node(Tree *t) {
    if (t->root == NULL) {
        printf("EXCEPTION: NULL ROOT | insert new node in the root of the tree before get it\n");
        exit(EXIT_FAILURE);
    }

    return t->root;
}

#endif