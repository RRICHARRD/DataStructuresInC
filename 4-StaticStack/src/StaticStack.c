#ifndef STATIC_STACK_IMPLEMENTATION
#define STATIC_STACK_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#include <StaticStack.h>

/**
 * @brief Stack structure
 * 
 * @attention Utilize StaticStack to referes to struct staticStack
 * 
 * @param size {long} The size of the stack
 * @param top {long} Position of top element in the Stack 
 * @param stack {int *} Reference to array to store values, that array is the stack
 * 
 * @link bytes alocated for each data type https://www.tutorialspoint.com/cprogramming/c_data_types.htm
 * 
 */
typedef struct staticStack {
    int *stack;
    long size;
    long current_top_index;
} StaticStack;

/**
 * @brief Create a static stack
 * 
 * @param size Size of static stack
 * @return StaticStack* 
 */
StaticStack *create_static_stack(const long size){
    StaticStack *new_static_stack = (StaticStack *) calloc(1, sizeof(StaticStack));
    new_static_stack->current_top_index = -1;
    new_static_stack->size = size;
    new_static_stack->stack = (int *) calloc(size, sizeof(int));
    return new_static_stack;
}   

/**
 * @brief Insert a new number at the top of stack
 * 
 * @attention For that example, that stack only receive positive values
 * 
 * @param st A static stack
 * @param value A number to store inside static stack
 * @return true 
 * @return false 
 */
bool push(StaticStack *st, int value){
    if (st->current_top_index == (st->size)-1) return false; //arrays begin in zero index on pointer arithmetic, reason size-1

    int new_top_position = ++(st->current_top_index);
    st->stack[new_top_position] = value;
    st->current_top_index = new_top_position;
    return true;
}

/**
 * @brief Validate if a static stack is empty
 * 
 * @param st A static stack
 * @return true
 * @return false
 */
bool is_empty(StaticStack *st){
    if (st->current_top_index == -1) return true;
    return false;
}

/**
 * @brief Get the top value of stack
 * 
 * @attention return -1234567890 if stack is empty
 * 
 * @param st Static static
 * @return long 
 */
long peek(StaticStack *st){
    if (is_empty(st)) return -1234567890;
    
    int current_top_index = st->current_top_index;
    return st->stack[current_top_index];
}

/**
 * @brief Return the top value of stack
 * 
 * @param st A static stack
 * @return long 
 */
long pop(StaticStack *st){
    if (is_empty(st)) return -1;

    long current_top_element = st->stack[st->current_top_index];
    st->stack[st->current_top_index] = 0; //not obligatory, just to "remove" the data from stack
    st->current_top_index = --(st->current_top_index);

    return current_top_element;
}

/**
 * @brief Get size of static statck
 * 
 * @param st A Static stack
 * @return long 
 */
long size(StaticStack *st){
    return st->size;
}

/**
 * @brief Show all the values inside stack
 * 
 * @param st A static stack
 */
void show_values(StaticStack *st){
    if (is_empty(st)) return;
    
    long current_top_index = st->current_top_index; 
    while (current_top_index != -1)
        printf("top index: %ld element: %ld\n", current_top_index--, st->stack[current_top_index]);

}

#endif