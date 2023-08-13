
#include <stdlib.h>


#define SIZE 13
#include <StaticQueue.h>

int main(){

    Queue *queue = (StaticQueue *) create_static_queue(SIZE); 

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
    //enqueue(queue, 14); generate an "exception" correctly =)

    dequeue_frenetically(queue, 5);

    peek_all(queue);

    enqueue(queue, 14);
    enqueue(queue, 15);
    enqueue(queue, 16);
    enqueue(queue, 17);
    enqueue(queue, 18); //full size filled

    dequeue(queue);
    enqueue(queue, 19); //working correct =)

    // printf("first value of queues: %d\n", peek_first(queue));
    // printf("last value of queue: %d\n", peek_last(queue));

    printf("--- get new values after dequeue and enqueue again ---\n");
    peek_all(queue);

    dequeue_frenetically(queue, SIZE);

    peek_all(queue);

    return EXIT_SUCCESS;
}