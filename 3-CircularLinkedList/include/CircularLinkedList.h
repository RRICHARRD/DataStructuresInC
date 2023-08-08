#ifndef CIRCULAR_LINKEDLIST_ESPECIFICATION
#define CIRCULAR_LINKEDLIST_ESPECIFICATION

/**
 * @brief Circular node structure
 * 
 * @attention Use Circular Node to refers to struct circularNode
 * 
 * @param value {int} A value to store inside the node
 * @param circularNode {struct circularNode *} Node in the last position
 */
typedef struct circularNode CircularNode;

/**
 * @brief Circular linked list strutucte
 * 
 * @attention User CircularLinkedList to referes to struct circularLinkedList
 */
typedef struct circularLinkedList CircularLinkedList;

/**
 * @brief Create a circuluar linked list
 * 
 * @return CircularLinkedList * 
 */
CircularLinkedList * create_circuluar_linked_list();

/**
 * @brief Insert new node in the circular linked list
 * 
 * @param cl A circular linked list
 * @param value A value to store inside the new node
 */
void insert_new_node(CircularLinkedList *cl, int value);

#endif