#ifndef DYNAMIC_STACK_IMPLEMENTATION
#define DYNAMIC_STACK_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#include <DynamicStack.h>

/**
 * @brief Structure of node with two pointer variables to use in dynamic stack 
 * 
 * @attention Use DoublyNode or Node to refers to a type of struct doublyNode
 * 
 * @param value {int} A number to store inside the node 
 * @param upper_next_node {DoublyNode *} Upper node address
 * @param bottom_preview_node {DoublyNode *} Preview node address
 */
typedef struct doublyNode{
    int value;
    struct doublyNode *upper_next_node;
    struct doublyNode *bottom_preview_node;
} DoublyNode, Node;

/**
 * @brief Dynamic stack structure
 * 
 * @param first_node {DoublyNode *} Address of first inserted in the dynamic stack
 * @param top_node {DoublyNode *} Address of last node inserted in the dynamic stack, the top node
 */
typedef struct dynamicStack{
    DoublyNode *first_node;
    DoublyNode *top_node;
} DynamicStack;

/**
 * @brief Create a dynamic stack
 * 
 * @return DynamicStack* 
 */
DynamicStack *create_dynamic_stack(){
    return (DynamicStack *) calloc(1, sizeof(DynamicStack)); //first and top nodes is NULL
}

/**
 * @brief Create a doubly node
 * 
 * @param number A value to store inside the node
 */
DoublyNode *create_doubly_node(int number){
    return (DoublyNode *) calloc(1, sizeof(DoublyNode));
}

/**
 * @brief Insert a new node in the stack
 * 
 * @param dt Dynamic Stack 
 * @param number A number to store inside the new node
 */
void push(DynamicStack *dt, int number){
    if (dt->top_node == NULL && dt->first_node == NULL) {
        DoublyNode *new_doubly_Node = (DoublyNode *) create_doubly_node(number);
        new_doubly_Node->value = number;
        dt->top_node = new_doubly_Node;
        dt->first_node = new_doubly_Node;
        return;
    }

    DoublyNode *new_doubly_node = (DoublyNode *) create_doubly_node(number);
    new_doubly_node->value = number;

    dt->top_node->upper_next_node = new_doubly_node;
    new_doubly_node->bottom_preview_node = dt->top_node;
    dt->top_node = new_doubly_node;
}

/**
 * @brief Get the top value of dynamic stack
 * 
 * @param dt Dynamic stack
 * @return int 
 */
int top(DynamicStack *dt){
    return dt->top_node != NULL ? dt->top_node->value : -321;
}

/**
 * @brief Get the first value of dynamic stack
 * 
 * @param dt Dynamic stack
 * @return int 
 */
int first(DynamicStack *dt){
    return dt->first_node != NULL ? dt->first_node->value : -321;
}

/**
 * @brief Show all values and address of dynamics stack
 * 
 * @param dt A Dynamic Stack
 * @param inverted A boolean to show normal from top to first (false) or from first to top (true)
 */
void show(DynamicStack *dt, bool inverted){
    if(dt->first_node == NULL && dt->top_node == NULL) return;

    DoublyNode *node_reader = inverted ? dt->first_node : dt->top_node;
    
    while ((inverted ? node_reader->upper_next_node : node_reader->bottom_preview_node) != NULL){ //
        printf("address: %p value: %d\n", node_reader, node_reader->value);
        node_reader = inverted ? node_reader->upper_next_node : node_reader->bottom_preview_node;
    }
    printf("address: %p value: %d\n", node_reader, node_reader->value);
}

/**
 * @brief Remove to top element of dynamic stack
 * 
 * @param dt A dynamic stack
 * @return int
 */
int pop(DynamicStack *dt){
    if (dt->top_node == NULL) return -321;

    if (dt->top_node == dt->first_node) {
        DoublyNode *current_top_node_address = dt->top_node;

        dt->first_node = dt->top_node = NULL; 
        int current_top_node_value = current_top_node_address->value;

        free(current_top_node_address);
        return current_top_node_value;
    }

    DoublyNode *current_top_node_address = dt->top_node;
    int current_top_node_value = dt->top_node->value;
    
    dt->top_node = dt->top_node->bottom_preview_node;
    dt->top_node->upper_next_node = NULL;

    free(current_top_node_address);
    return current_top_node_value;
}

/**
 * @brief Destroy allocated memory of nodes
 * 
 * @param dt Dynamic stack
 * @param intirely Validation to destroy intirely dynamic list
 */
void destroy(DynamicStack **dt, bool intirely){
    if ((*dt)->top_node == NULL && intirely != true) return;

    if ((*dt)->top_node == NULL && intirely == true){
        free(*dt);
        dt = NULL;
        return;
    } 

    DoublyNode *node_reader = (*dt)->top_node;

    while (node_reader->bottom_preview_node != NULL) {
        DoublyNode *current_doubly_node = node_reader;
        (*dt)->top_node = node_reader = node_reader->bottom_preview_node;

        current_doubly_node->upper_next_node = NULL;
        current_doubly_node->bottom_preview_node = NULL;
        free(current_doubly_node);
    }
    
    node_reader->upper_next_node = NULL;
    node_reader->bottom_preview_node = NULL;
    free(node_reader);

    (*dt)->top_node = (*dt)->first_node = NULL;

    if (intirely){
        free(*dt);
        dt = NULL;
    }
}

/**
 * @brief Get quantity of nodes inside Dynamic stack
 * 
 * @param st Dynamic stack
 * @return int
 */
unsigned long quantity(DynamicStack *dt){
    if (dt->top_node == NULL) return 0;

    unsigned long quantity = 0;
    DoublyNode *node_reader = dt->top_node;
    while (node_reader->bottom_preview_node != NULL){
        quantity++;
        node_reader = node_reader->bottom_preview_node;
    }

    return ++quantity; //for the last node
}

#endif