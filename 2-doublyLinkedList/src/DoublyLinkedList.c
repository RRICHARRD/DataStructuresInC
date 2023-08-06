#ifndef DOUBLY_LINKEDLIST_IMPLEMENTATION
#define DOUBLY_LINKEDLIST_IMPLEMENTATION

#include <stdlib.h>
#include <stdio.h>

#include <DoublyLinkedList.h>

/**
 * @brief Node structure to use inside DoubleLinkedList
 * 
 * @attention Use DoublyNode or Node to define type of struct doubly_node in source code
 * 
 * @param node_value {int} A value to store inside a Node
 * @param next_doubly_node_address {doubly_node *} Next node address int the chain
 * @param preview_doubly_node_address {doubly_node *} Preview doubly node address in the chain
 */
typedef struct doubly_node {
    int node_value;
    struct doubly_node *next_doubly_node_address;
    struct doubly_node *preview_doubly_node_address;
} DoublyNode, Node;

/**
 * @brief Create a doubly node structure with NULL values to address
 * 
 * @param number Value to store inside the Doubly node
 * @return Doubly_node* 
 */
DoublyNode *create_doubly_node(int number) {
    DoublyNode *new_doubly_node = (DoublyNode *) calloc(1, sizeof(DoublyNode)); //next and preview address is NULL
    new_doubly_node->node_value = number;
    return new_doubly_node;
}

/**
 * @brief Doubly linked list structure
 * 
 * @attention Use DoublyLinkedList or LinkedList to define type of struct doubly_linked_list in source code
 * 
 * @param head {DoublyNode *} First Doubly node of the chain
 */
typedef struct doubly_linked_list {
    DoublyNode *head;
} DoublyLinkedList, LinkedList;

/**
 * @brief Create a linked list object
 * 
 * @return DoublyLinkedList* 
 */
DoublyLinkedList *create_doubly_linked_list(){
    return (DoublyLinkedList *) calloc(1, sizeof(DoublyLinkedList));
}

/**
 * @brief Insert a Doubly Node in the last position of the doubly linked list
 * 
 * @param l Doubly linked list
 * @param number Value to store inside the new node
 */
void insert_last(DoublyLinkedList *l, int number){
    if (l->head == NULL){
        l->head = (DoublyNode *) create_doubly_node(number);
        return;
    }

    DoublyNode *node_reader = l->head;
    while (node_reader->next_doubly_node_address != NULL)
        node_reader = node_reader->next_doubly_node_address;
    
    DoublyNode *new_doubly_node = (DoublyNode *) create_doubly_node(number);
    node_reader->next_doubly_node_address = new_doubly_node;
    new_doubly_node->preview_doubly_node_address = node_reader;
}

/**
 * @brief Insert another node in the head
 * 
 * @param l Doubly linked list
 * @param number A value to store inside the new Doubly node of the structure
 */
void insert_head(DoublyLinkedList *l, int number){
    DoublyNode *new_doubly_node = (DoublyNode *) create_doubly_node(number);
    
    new_doubly_node->next_doubly_node_address = l->head;
    l->head->preview_doubly_node_address = new_doubly_node;

    l->head = new_doubly_node;
}

/**
 * @brief Show nodes from the head to tail if exists
 * 
 * @param l Doubly linked list with values
 */
void show_from_head(DoublyLinkedList *l){
    if (l->head == NULL) return;

    DoublyNode *node_reader = l->head;
    while (node_reader->next_doubly_node_address != NULL){
        printf("value: %d address %p\n", node_reader->node_value, node_reader);
        node_reader = node_reader->next_doubly_node_address;
    }
    printf("value: %d address %p\n", node_reader->node_value, node_reader);
}

/**
 * @brief Show nodes of doubly linked list from tail to head if exists
 * 
 * @param l Doubly linked list structure
 */
void show_from_tail(DoublyLinkedList *l){
    if(l->head == NULL) return;

    DoublyNode *node_reader = l->head;

    while (node_reader->next_doubly_node_address != NULL)
        node_reader = node_reader->next_doubly_node_address;

    while (node_reader->preview_doubly_node_address != NULL){
        printf("value: %d address %p\n", node_reader->node_value, node_reader);
        node_reader = node_reader->preview_doubly_node_address;
    }
    printf("value: %d address %p\n", node_reader->node_value, node_reader);

}

#endif