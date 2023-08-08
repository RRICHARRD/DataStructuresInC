#ifndef CIRCULAR_LINKEDLIST_IMPLEMENTATION
#define CIRCULAR_LINKEDLIST_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#include <CircularLinkedList.h>

/**
 * @brief A simple node, using circular node only for convention
 * 
 * @attention Use Circular Node to refers to struct circularNode
 * 
 * @param value {int} A value to store inside the node
 * @param next_circular_node {struct circularNode *} Node in the last position
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
    CircularNode *new_circular_node = (CircularNode *) calloc(1, sizeof(CircularNode)); //next_circular_node is NULL
    new_circular_node->value = number;
    return new_circular_node;
}

/**
 * @brief Insert new node in the circular linked list
 * 
 * @attention Only the first inserted node is static, the others insertions begin descending
 * 
 * @param cl A circular linked list
 * @param value A value to store inside the new node
 */
void insert_new_node(CircularLinkedList *cl, int value){
    if (cl->last_node == NULL){
        CircularNode *new_circular_node = create_new_circular_node(value);
        new_circular_node->next_circular_node = new_circular_node; //the first node -> first node ✓
        cl->last_node = new_circular_node;
        return;
    }

    CircularNode *new_circular_node = create_new_circular_node(value);
    new_circular_node->next_circular_node = cl->last_node->next_circular_node;
    cl->last_node->next_circular_node = new_circular_node;
}

/**
 * @brief Show all nodes inside circular linked list
 * 
 * @param cl Circular linked list
 * @param repeat_infinitely A boolean to activate infinite Circular linked list transversal
 */
void show(CircularLinkedList *cl, bool repeat_infinitely){
    if (cl->last_node == NULL) return;

    void *repeat = (repeat_infinitely == true) ? NULL : cl->last_node; //only need or a NULL or an address, reason I use void *, I dont need members

    CircularNode *node_reader = cl->last_node;
    while (node_reader->next_circular_node != repeat){
        printf("address: %p value: %d\n", node_reader, node_reader->value);
        node_reader = node_reader->next_circular_node;
    }
    printf("address: %p value: %d\n", node_reader, node_reader->value);
}

/**
 * @brief Delete a node from Circular Linked List
 * 
 * @param cl A circular linked list
 * @param number A value inside a node to be deleted
 */
void delete_node(CircularLinkedList *cl, int number){
    if (cl->last_node == NULL) return;

    if(cl->last_node->value == number){ //test when i have only one node in last position
        CircularNode *current_last_node = cl->last_node;
        cl->last_node = cl->last_node->next_circular_node;

        CircularNode *node_reader = cl->last_node;
        while (node_reader->next_circular_node != current_last_node)
            node_reader = node_reader->next_circular_node;

        node_reader->next_circular_node = cl->last_node;
        free(current_last_node);
    }
    
}

#endif