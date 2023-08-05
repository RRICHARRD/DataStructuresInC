 //! Segmentation fault error -> Tentative to access memory location that they are not allowed to acces
//! maybe tring to access data of NULL reference

//In some cases I use struct linked list only to remember me that is possible

#ifndef LINKED_LIST_IMPLEMENTATION
#define LINKED_LIST_IMPLEMENTATION

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <LinkedList.h>

/**
 * @brief Basic structure to use insie linked list
 * 
 * @param value {int} Value to store in the node
 * @param next_node_address {struct node* | typedef Node*} Address of next node to connect
 */
typedef struct node {
    int value;
    struct node *next_node_address;
} Node;


/**
 * @brief Linked list struture
 * 
 * @param head {Node *} The first node of this linked list
 */
typedef struct linked_list {
    Node *head;
} Linked_List;

/**
 * @brief Create a linked list object
 * 
 * @details Used `struct linked_list` only to know that is possible
 * 
 * @return struct linked_list* 
 */
struct linked_list * create_linked_list(){
    return (struct linked_list *) calloc(1, sizeof(struct linked_list));
}

/**
 * @brief Create a new Node with next_node_address property set to NULL
 * 
 * @param value A number to store inside the node
 * @return Node *
 */
Node *create_new_node(int value) {
    Node *new_node = (Node *) calloc(1, sizeof(Node));
    new_node->next_node_address = NULL;
    new_node->value = value;

    return new_node;
}

/**
 * @brief Insert new node in the head of linked list
 * 
 * @param l A linked list address
 * @param value Info to store inside the new node
 */
void insert_first(Linked_List *l, int value){
    Node *new_node = (Node *) calloc(1, sizeof(Node));
    new_node->value = value;

    new_node->next_node_address = l->head;
    l->head = new_node;
}

/**
 * @brief Insert new node at last position of linked list
 * 
 * @param l The linked list
 * @param value A value to insert inside the new node in the final of liked list
 */
void insert_last(const Linked_List *l, int value){
    Node *node_reader = (Node *) l->head;

    while (node_reader->next_node_address != NULL)
        node_reader = node_reader->next_node_address;

    node_reader->next_node_address = (Node *) create_new_node(value);
}


/**
 * @brief Show all values inside a linked list if exists
 * 
 * @param l A linked list
 */
void show(const Linked_List *l){
    if(l->head == NULL) return;

    Node *nodes_reader = (Node *) l->head;

    while(nodes_reader->next_node_address != NULL){
        printf("node value: %d\n", nodes_reader->value);
        nodes_reader = nodes_reader->next_node_address;
    }
    printf("node value: %d\n", nodes_reader->value); //for first and last Node with NULL next_node_address
}

/**
 * @brief Insert a new node af an existing node value
 * 
 * @param l A linked list structure
 * @param node_value A value of possible existing node
 * @param new_node_value A value to create store in the new node
 */
void insert_new_node_after_node(const Linked_List *l, int node_value, int new_node_value){
    Node *node_reader = l->head;

    while (node_reader->next_node_address != NULL){
        if(node_reader->value == node_value){
            Node *new_node = create_new_node(new_node_value);
            new_node->next_node_address = node_reader->next_node_address;
            node_reader->next_node_address = new_node;
            return;
        }
        node_reader = node_reader->next_node_address;
    }

    //Last position validation, not try if value has been found above
    if(node_reader->value == node_value){
            Node *new_node = create_new_node(new_node_value);
            new_node->next_node_address = node_reader->next_node_address;
            node_reader->next_node_address = new_node;
    }
    
}

/**
 * @brief Remove a node from linked list
 * 
 * @param l The linked list
 * @param node_value An existing node value, make no changes if does not exists
 */
void delete_node(Linked_List *l, int node_value){
    Node *node_reader = l->head;

    if(l->head->value == node_value){
        Node *next_head_node = l->head->next_node_address;
        free(l->head); //free at address block of node * calloc alocation, not address of &head variable
        l->head = next_head_node;
        return;
    }

    while (node_reader->next_node_address != NULL){
        if(node_reader->next_node_address->value == node_value){
            Node *node_to_delete = node_reader->next_node_address;
            node_reader->next_node_address = node_reader->next_node_address->next_node_address;
            free(node_to_delete);
            return;
        }
        node_reader = node_reader->next_node_address;
    }
    
}

/**
 * @brief Get total of Nodes in the sctructure
 * 
 * @param l A linked list
 * @return int Number to identify total of Nodes inside linked list
 */
int get_total_nodes(const struct linked_list * l){
    if(l->head == NULL) return 0;

    Node *node_reader = l->head;
    
    int quantity = 0;
    while (node_reader->next_node_address != NULL){
        quantity++;
        node_reader = node_reader->next_node_address;
    }

    return ++quantity; //plus one for the last node that -> to null
}

/**
 * @brief Desaloc all Nodes and of the linked list
 * 
 * @param l The address of linked list
 * @param desaloc_list Identification to validade if is necessary to free intire linked list address 
 */
void destroy(Linked_List **l, bool desaloc_list) {
     //**l is the same address of (*l)->head
    //(**l).head != NULL works too O_o

    //free always the first Node of linked list in sequence =)
    while((*l)->head != NULL){
        Node *current_head_node = (*l)->head;
        (*l)->head = (*l)->head->next_node_address;
        free(current_head_node);
    }

    if(desaloc_list == true) {
        free(*l);
        *l = NULL;
    }
}

#endif