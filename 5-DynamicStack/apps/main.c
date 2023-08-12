
#include <stdio.h>

#include <DynamicStack.h>

int main(){

    DynamicStack *stack = create_dynamic_stack();

    printf("%p\n", stack);
    printf("%p\n", &stack);
    
    return 0;
}