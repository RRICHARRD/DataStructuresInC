//#include <BinaryTree.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    char letter;
    struct treeNode *left;
    struct treeNode *right;
} TreeNode;

typedef struct tree {
    TreeNode *root;
} Tree;

TreeNode *create_new_node(char letter) {
    TreeNode *new_tree_node = (TreeNode *) calloc(1, sizeof(TreeNode));
    new_tree_node->letter = letter;
    return new_tree_node;
}

void show_node_value(TreeNode *tn) {
    printf("%c\n", tn->letter);
}

void insert(TreeNode *td, char *position, char letter) {
    if (position != "left" && position != "right") {
        printf("EXCEPTION: Strange insert positon | use 'right' or 'left'");
        exit(EXIT_FAILURE);
    }
    
    TreeNode *new_node = (TreeNode *) calloc(1, sizeof(TreeNode));
    new_node->letter = letter;

    TreeNode **node_position = (position == "left") ? &td->left : &td->right;
    *node_position = new_node;
}

int main() {
    Tree *tree = (Tree *) calloc(1, sizeof(Tree));
    printf("root: %p\n", tree->root);
    
    tree->root = create_new_node('r');
    printf("root: %p\n", tree->root);
    
    show_node_value(tree->root);
    
    insert(tree->root, "left", 'i');

    printf("root->left: %c\n", tree->root->left->letter);
    insert(tree->root->left, "right", 'c');

    printf("root->left: %c\n", tree->root->left->right->letter);

    return EXIT_SUCCESS;
}
