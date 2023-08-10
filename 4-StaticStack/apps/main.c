
#include <stdlib.h>
#include <stdio.h>

#include <StaticStack.h>

int main(){

    StaticStack *stack = (StaticStack *) create_static_stack(5);
    
    printf("Stack is empty: %s\n", is_empty(stack) ? "true" : "false");

    push(stack, 1);
    printf("Stack is empty: %s\n", is_empty(stack) ? "true" : "false");

    return EXIT_SUCCESS;
}