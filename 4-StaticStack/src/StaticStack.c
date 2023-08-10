#ifndef STATIC_STACK_IMPLEMENTATION
#define STATIC_STACK_IMPLEMENTATION

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
    long top;
    long size;
} StaticStack;

/**
 * @brief Create a static stack
 * 
 * @param size Size of static stack
 * @return StaticStack* 
 */
StaticStack *create_static_stack(const long size){
    StaticStack *new_static_stack = (StaticStack *) calloc(1, sizeof(StaticStack));
    new_static_stack->top = -1;
    new_static_stack->size = size;
    new_static_stack->stack = (int *) calloc(size, sizeof(int));
    return new_static_stack;
}   

/**
 * @brief Insert a new number at the top of stack
 * 
 * @param st A static stack
 * @param value A number to store inside static stack
 * @return true 
 * @return false 
 */
bool push(StaticStack *st, int value){
    if (st->top == (st->size)-1) return false; //arrays begin in zero index on pointer arithmetic, reason size-1

    int new_top_position = ++(st->top);
    st->stack[new_top_position] = value;
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
    if (st->top == -1) return true;
    return false;
}

#endif