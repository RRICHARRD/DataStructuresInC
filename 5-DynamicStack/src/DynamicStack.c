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
        dt->top_node = dt->first_node = (DoublyNode *) create_doubly_node(number);
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
    return dt->top_node->value;
}

/**
 * @brief Get the first value of dynamic stack
 * 
 * @param dt Dynamic stack
 * @return int 
 */
int first(DynamicStack *dt){
    return dt->first_node->value;
}

/**
 * @brief Show all values and address of dynamics stack
 * 
 * @param dt A Dynamic Stack
 * @param inverted A boolean to show normal from top to first (false) or from first to top (true)
 */
void show(DynamicStack *dt, bool inverted){
    DoublyNode *node_reader = inverted ? dt->first_node : dt->top_node;
    
    while ((inverted ? node_reader->upper_next_node : node_reader->bottom_preview_node) != NULL){ //
        printf("address: %p value: %d\n", node_reader, node_reader->value);
        node_reader = inverted ? node_reader->upper_next_node : node_reader->bottom_preview_node;
    }
    printf("address: %p value: %d\n", node_reader, node_reader->value);
}

#endif