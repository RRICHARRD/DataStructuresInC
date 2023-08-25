

#include <stdio.h>

#include <Tree.h>

/*
    Reading theory to understand better

    non-linear data structure, before all was linear
    store data in a hierarchical order
    each node of a tree has children and parent, the concentual is the same of real trees

    Trees has details, I will learn them in the future to be more productive
*/


/*
    Buid that tree below and tranversal after:

                    D
                  /  \
                 C    R
                / \    \
               R  I     A
                       /
                      H
*/ 

void traversal(TreeNode *root) {
    printf("%s", root->letter);
    
    if (root->left != NULL) {
        return traversal(root->left);
    } else if (root->right != NULL) {
        return traversal(root->right);
    } else if (root->right == NULL) {
        return traversal(root->parent->parent->right);
    }

}

int main() {

    TreeNode *R = (TreeNode *) create_tree_node("R");
    TreeNode *I = (TreeNode *) create_tree_node("I");
    TreeNode *C = (TreeNode *) create_tree_node("C");
    TreeNode *H = (TreeNode *) create_tree_node("H");
    TreeNode *A = (TreeNode *) create_tree_node("A");
    TreeNode *R2 = (TreeNode *) create_tree_node("R");
    TreeNode *D = (TreeNode *) create_tree_node("D");

    D->left = C;
    C->parent = D;
    
    C->left = R;
    R->parent = C;
    C->right = I;
    I->parent = C;

    D->right = R2;
    R2->parent = D;

    R2->right = A;
    A->parent = R2;

    A->left = H;
    H->parent = A;


    traversal(D);

    return 0;
}