#ifndef DYNAMIC_STACK_SPECIFICATION
#define DYNAMIC_STACK_SPECIFICATION

/**
 * @brief Structure of node with two pointer variables to use in dynamic stack 
 * 
 * @attention Use DoublyNode or Node to refers to a type of struct doublyNode
 * 
 * @param value {int} A number to store inside the node 
 * @param upper_next_node {DoublyNode *} Upper node address
 * @param bottom_preview_node {DoublyNode *} Preview node address
 */
typedef struct doublyNode DoublyNode, Node;

/**
 * @brief Dynamic stack structure
 * 
 * @param first_node {DoublyNode *} Address of first inserted in the dynamic stack
 * @param top_node {DoublyNode *} Address of last node inserted in the dynamic stack, the top node
 */
typedef struct dynamicStack DynamicStack;

/**
 * @brief Create a dynamic stack
 * 
 * @return DynamicStack* 
 */
DynamicStack *create_dynamic_stack();

/**
 * @brief Create a doubly node
 * 
 * @param number A value to store inside the node
 */
DoublyNode *create_doubly_node(int number);

/**
 * @brief Insert a new node in the stack
 * 
 * @param dt Dynamic Stack 
 * @param number A number to store inside the new node
 */
void push(DynamicStack *dt, int number);

#endif