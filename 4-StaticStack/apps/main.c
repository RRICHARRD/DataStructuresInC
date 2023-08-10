
#include <stdlib.h>
#include <stdio.h>

#include <StaticStack.h>

int main(){

    StaticStack *stack = (StaticStack *) create_static_stack(5);
    
    printf("Stack is empty: %s\n", is_empty(stack) ? "true" : "false");

    push(stack, 45);
    printf("Stack is empty: %s\n", is_empty(stack) ? "true" : "false");

    printf("Current top number is: %ld\n", peek(stack));

    push(stack, 90);
    printf("Current top number is: %ld\n", peek(stack));

    printf("Poped value: %ld\n", pop(stack));
    printf("Poped value: %ld\n", pop(stack));
    printf("Poped value: %ld\n", pop(stack));

    return EXIT_SUCCESS;
}