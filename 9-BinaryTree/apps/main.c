
#include <stdio.h>
#include <stdlib.h>

#include <BinaryTree.h>


int main() {
    Tree *tree = create_new_tree();
    //printf("root: %p\n", tree->root);
    
    define_root(tree, 'r');
    //tree->root = create_new_node('r');
    
    printf("root: %p\n", get_root_node(tree));
    
    show_node_value(get_root_node(tree));
    
    insert(get_root_node(tree), "left", 'i');

    //printf("root->left: %c\n", tree->root->left->letter);
    //insert(tree->root->left, "right", 'c');

    //printf("root->left: %c\n", tree->root->left->right->letter);

    return EXIT_SUCCESS;
}
