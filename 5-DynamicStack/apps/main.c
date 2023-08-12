
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
    
    printf("stack has %ld values\n", quantity(stack));
    
    printf("the first value of stack is: %d\n", first(stack));
    printf("the top value of stack is: %d\n", top(stack));

    show(stack, false);

    printf("### poping values...\n");
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);

    show(stack, true);

    printf("the last pop() without any value need to be -321: %d\n", pop(stack)); //excelent

    destroy(&stack, false);

    push(stack, 66); //segmentation fault if intire param of destroy() is true
    show(stack, false);

    return 0;
}