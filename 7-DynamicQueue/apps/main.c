
#include <stdio.h>
#include <stdlib.h>

#include <DynamicQueue.h>

int main() {
    
    DynamicQueue *queue = (DynamicQueue *) create_new_dynamic_queue();

    printf("%p\n", queue);
    printf("%p\n", &queue);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 0);

    printf("the current size of queue is: %ld\n", size(queue));

    show(queue);

    printf("dequeued: %d\n", dequeue(queue));

    dequeue_frenetically(queue, 40);

    return EXIT_SUCCESS;
}