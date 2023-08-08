#ifndef CIRCULAR_LINKEDLIST_IMPLEMENTATION
#define CIRCULAR_LINKEDLIST_IMPLEMENTATION

#include <stdlib.h>

#include <CircularLinkedList.h>

/**
 * @brief A simple node, using circular node only for convention
 * 
 * @attention Use Circular Node to refers to struct circularNode
 * 
 * @param value {int} A value to store inside the node
 * @param circularNode {struct circularNode *} Node in the last position
 */
typedef struct circularNode{
    int value;
    struct circularNode *next_circular_node;
} CircularNode;

/**
 * @brief Circular linked list strutucte
 * 
 * @attention User CircularLinkedList to referes to struct circularLinkedList
 * 
 * @param last_node {CircularNode *}
 */
typedef struct circularLinkedList{
    CircularNode *last_node;
} CircularLinkedList;

/**
 * @brief Create a circuluar linked list
 * 
 * @return CircularLinkedList * 
 */
CircularLinkedList * create_circuluar_linked_list(){
    return (CircularLinkedList *) calloc(1, sizeof(CircularLinkedList));
}

/**
 * @brief Create a new circular node
 * 
 * @param number A value to store inside the new node
 * 
 * @return CircularNode* 
 */
CircularNode * create_new_circular_node(int number){
    return (CircularNode *) calloc(1, sizeof(CircularNode)); //next_circular_node is NULL
}

/**
 * @brief Insert new node in the circular linked list
 * 
 * @param cl A circular linked list
 * @param value A value to store inside the new node
 */
void insert_new_node(CircularLinkedList *cl, int value){
    if (cl->last_node == NULL){
        CircularNode *new_circular_node = create_new_circular_node(value);
        new_circular_node->next_circular_node = new_circular_node; //the first node -> first node
        cl->last_node = new_circular_node;
    }

}

#endif