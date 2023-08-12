
#include <stdio.h>

#include <DynamicStack.h>

int main(){

    DynamicStack *stack = create_dynamic_stack();

    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    push(stack, 8);
    push(stack, 9);
    
    printf("the first value of stack is: %d\n", first(stack));
    printf("the top value of stack is: %d\n", top(stack));

    show(stack, false);

    return 0;
}