#ifndef LINKED_LIST_SPECIFICATION
#define LINKED_LIST_SPECIFICATION

#include <stdbool.h>

/**
 * @brief Basic structure to use insie linked list
 * 
 * @param value {int} Value to store in the node
 * @param next_node_address {struct node* | typedef Node*} Address of next node to connect
 */
typedef struct node Node;


/**
 * @brief Linked list struture
 * 
 * @param head {Node *} The first node of this linked list
 */
typedef struct linked_list Linked_List;

/**
 * @brief Create a linked list object
 * 
 * @details Used `struct linked_list` only to know that is possible
 * 
 * @return struct linked_list* 
 */
struct linked_list * create_linked_list();

/**
 * @brief Create a new Node with next_node_address property set to NULL
 * 
 * @param value A number to store inside the node
 * @return Node *
 */
Node *create_new_node(int value);

/**
 * @brief Insert new node in the head of linked list
 * 
 * @param l A linked list address
 * @param value Info to store inside the new node
 */
void insert_first(Linked_List *l, int value);

/**
 * @brief Insert new node at last position of linked list
 * 
 * @param l The linked list
 * @param value A value to insert inside the new node in the final of liked list
 */
void insert_last(const Linked_List *l, int value);

/**
 * @brief Show all values inside a linked list if exists
 * 
 * @param l A linked list
 */
void show(const Linked_List *l);

/**
 * @brief Insert a new node af an existing node value
 * 
 * @param l A linked list structure
 * @param node_value A value of possible existing node
 * @param new_node_value A value to create store in the new node
 */
void insert_new_node_after_node(const Linked_List *l, int node_value, int new_node_value);

/**
 * @brief Remove a node from linked list
 * 
 * @param l The linked list
 * @param node_value An existing node value, make no changes if does not exists
 */
void delete_node(Linked_List *l, int node_value);

/**
 * @brief Get total of Nodes in the sctructure
 * 
 * @param l A linked list
 * @return int Number to identify total of Nodes inside linked list
 */
int get_total_nodes(const struct linked_list * l);

/**
 * @brief Desaloc all Nodes and of the linked list
 * 
 * @param l The address of linked list
 * @param desaloc_list Identification to validade if is necessary to free intire linked list address 
 */
void destroy(Linked_List **l, bool desaloc_list);

#endif