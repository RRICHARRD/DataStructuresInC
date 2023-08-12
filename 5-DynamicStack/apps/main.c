
#include <stdio.h>

#include <DynamicStack.h>

int main(){

    DynamicStack *stack = create_dynamic_stack();

    push(stack, 1);
    push(stack, 2);
    
    return 0;
}