#ifndef DYNAMIC_STACK_SPECIFICATION
#define DYNAMIC_STACK_SPECIFICATION

#include <stdbool.h>

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

/**
 * @brief Get the top value of dynamic stack
 * 
 * @param dt Dynamic stack
 * @return int 
 */
int top(DynamicStack *dt);

/**
 * @brief Get the first value of dynamic stack
 * 
 * @param dt Dynamic stack
 * @return int 
 */
int first(DynamicStack *dt);

/**
 * @brief Show all values and address of dynamics stack
 * 
 * @param dt A Dynamic Stack
 * @param inverted A boolean to show normal from top to first (false) or from first to top (true)
 */
void show(DynamicStack *dt, bool inverted);

/**
 * @brief Remove to top element of dynamic stack
 * 
 * @param dt A dynamic stack
 * @return int
 */
int pop(DynamicStack *dt);

/**
 * @brief Destroy allocated memory of nodes
 * 
 * @param dt Dynamic stack
 * @param intirely Validation to destroy intirely dynamic list
 */
void destroy(DynamicStack **dt, bool intirely);

/**
 * @brief Get quantity of nodes inside Dynamic stack
 * 
 * @param st Dynamic stack
 * @return int
 */
unsigned long quantity(DynamicStack *dt);

#endif