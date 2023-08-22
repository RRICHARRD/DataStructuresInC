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
    TreeNode *new_node = (TreeNode *) calloc(1, sizeof(TreeNode));
    new_node->letter = letter;
    
    if (position == "left") {
        td->left = new_node;
    } else if(position == "right") {
        td->right = new_node;
    } else {
        printf("EXCEPTION: Strange insert positon | use 'right' or 'left'");
        exit("EXIT_FAILURE");
    }
}

int main() {
    Tree *tree = (Tree *) calloc(1, sizeof(Tree));
    printf("root: %p\n", tree->root);
    
    tree->root = create_new_node('r');
    printf("root: %p\n", tree->root);
    
    show_node_value(tree->root);
    
    insert(tree->root, "left", 'i');

    printf("root->left: %c\n", tree->root->left->letter);

    return 'EXIT_SUCCESS';
}
