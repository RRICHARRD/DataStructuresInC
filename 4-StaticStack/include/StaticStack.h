#ifndef STATIC_STACK_SPECIFICATION
#define STATIC_STACK_SPECIFICATION

#include <stdbool.h>

/**
 * @brief Stack structure
 * 
 * @attention Utilize StaticStack to referes to struct staticStack
 * 
 * @param size {long} The size of the stack
 * @param top {long} Position of top element in the Stack 
 * @param stack {int *} Reference to array to store values, that array is the stack
 * 
 */
typedef struct staticStack StaticStack;

/**
 * @brief Create a static stack
 * 
 * @param size Size of static stack
 * @return StaticStack* 
 */
StaticStack *create_static_stack(const long size);

/**
 * @brief Insert a new number at the top of stack
 * 
 * @param st A static stack
 * @param value A number to store inside static stack
 * @return true 
 * @return false 
 */
bool push(StaticStack *st, int value);

/**
 * @brief Validate if a static stack is empty
 * 
 * @param st A static stack
 * @return true
 * @return false
 */
bool is_empty(StaticStack *st);

/**
 * @brief Get the top value of stack
 * 
 * @attention return -12345690 if stack is empty
 * 
 * @param st Static static
 * @return long 
 */
long peek(StaticStack *st);

/**
 * @brief Return the top value of stack
 * 
 * @param st A static stack
 * @return long 
 */
long pop(StaticStack *st);

/**
 * @brief Get size of static statck
 * 
 * @param st A Static stack
 * @return long 
 */
long size(StaticStack *st);

/**
 * @brief Show all the values inside stack
 * 
 * @param st A static stack
 */
void show_values(StaticStack *st);

/**
 * @brief Check is static stack is full
 * 
 * @param st A Static stack
 * @return true
 * @return false 
 */
bool is_full(StaticStack *st);

/**
 * @brief Get the current top index of static stack
 * 
 * @param st A static stack
 * @return long 
 */
long current_top_index(StaticStack *st);

/**
 * @brief Desaloc memory of static stack
 * 
 * @param st A static stack
 * @param intire boolean to destroy intire stack of the memory
 */
void destroy(StaticStack **st, bool intire);

#endif