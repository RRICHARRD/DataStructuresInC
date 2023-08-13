
#include <stdlib.h>

#include <StaticQueue.h>

int main(){

    Queue *queue = (StaticQueue *) create_static_queue(13); 

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    //enqueue(queue, 14); generate an "exception" 


    // printf("first value of queues: %d\n", peek_first(queue));
    // printf("last value of queue: %d\n", peek_last(queue));

    int quantity_to_dequeue = 9;
    for(int i=0; i<quantity_to_dequeue; i++){
        printf("dequed value is: %d\n", dequeue(queue));
    }

    peek_all(queue);

    return EXIT_SUCCESS;
}