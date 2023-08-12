#ifndef DYNAMIC_STACK_IMPLEMENTATION
#define DYNAMIC_STACK_IMPLEMENTATION

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


#endif