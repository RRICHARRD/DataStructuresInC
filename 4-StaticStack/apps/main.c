
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
    printf("Poped value: %ld\n", pop(stack));

    printf("Size: %ld\n", size(stack));

    show_values(stack); //correct, here stack does not have elements

    
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    
    show_values(stack);

    printf("Is full: %s\n", is_full(stack) ? "true" : "false");
    pop(stack);

    printf("Is full: %s\n", is_full(stack) ? "true" : "false");

    printf("the index of top value is: %ld\n", current_top_index(stack));

    return EXIT_SUCCESS;
}