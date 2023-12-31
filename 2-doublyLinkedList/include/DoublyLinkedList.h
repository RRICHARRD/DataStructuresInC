#ifndef DOUBLY_LINKEDLIST_SPECIFICATION
#define DOUBLY_LINKEDLIST_SPECIFICATION

#include <stdbool.h>

/**
 * @brief Node structure to use inside DoubleLinkedList
 * 
 * @attention Use Doubly_node or Node to define type of struct doubly_node in source code
 * 
 * @param node_value {int} A value to store inside a Node
 * @param next_doubly_node_address {doubly_node *} Next node address int the chain
 * @param preview_doubly_node_address {doubly_node *} Preview doubly node address in the chain
 */
typedef struct doubly_node DoublyNode, Node;

/**
 * @brief Create a doubly node structure
 * 
 * @param number Value to store inside the Doubly node
 * @return Doubly_node* 
 */
DoublyNode *create_doubly_node(int number);

/**
 * @brief Doubly linked list structure
 * 
 * @attention Use DoublyLinkedList or LinkedList to define type of struct doubly_linked_list in source code
 * 
 * @param head {DoublyNode *} First Doubly node of the chain
 */
typedef struct doubly_linked_list DoublyLinkedList, LinkedList;

/**
 * @brief Create a linked list object
 * 
 * @return DoublyLinkedList* 
 */
DoublyLinkedList *create_doubly_linked_list();

/**
 * @brief Insert a Doubly Node in the last position of the doubly linked list
 * 
 * @param l Doubly linked list
 * @param number Value to store inside the new node
 */
void insert_last(DoublyLinkedList *l, int number);

/**
 * @brief Insert another node in the head
 * 
 * @param l Doubly linked list
 * @param number A value to store inside the new Doubly node of the structure
 */
void insert_head(DoublyLinkedList *l, int number); 

/**
 * @brief Show nodes from the head to tail if exists
 * 
 * @param l Doubly linked list with values
 */
void show_from_head(DoublyLinkedList *l);

/**
 * @brief Show nodes of doubly linked list from tail to head if exists
 * 
 * @param l Doubly linked list structure
 */
void show_from_tail(DoublyLinkedList *l);

/**
 * @brief Delete node from doubly linked list if exists
 * 
 * @param l Doubly linked list address
 * @param node_value A value to delete from doubly list if exists
 */
void delete_node(DoublyLinkedList *l, int node_value);

/**
 * @brief Destroy all nodes of Doubly linked list
 * 
 * @param l Doubly linked list
 * @param intire_list Identification to destroy intire list of the memory
 */
void destroy(DoublyLinkedList **l, bool intire_list);

#endif