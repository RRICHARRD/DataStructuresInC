#ifndef STATIC_QUEUE_IMPLEMENTATION
#define STATIC_QUEUE_IMPLEMENTATION

#include <stdlib.h>

#include <StaticQueue.h>

/**
 * @brief A static queue structure
 * 
 * @attention Use StaticQueue or Queue to refers to struct staticQueue
 * 
 * @param queue {int *} Array to store queue 
 * @param last {unsigned long} Last index of element in queue
 * @param first {unsigned long} First index of element in queue
 * @param total_size {unsigned long} Total size of queue
 * @param current_size {unsigned long} Current fill size of queue
 */
typedef struct staticQueue {
    int *queue;
    unsigned long last;
    unsigned long first;
    unsigned long total_size;
    unsigned long current_size;
} StaticQueue, Queue;

/**
 * @brief Create a static queue
 * 
 * @param total_size Full size of queue
 * @return StaticQueue* 
 */
StaticQueue *create_static_queue(const unsigned long total_size){
    StaticQueue *new_static_queue = (StaticQueue *) calloc(1, sizeof(StaticQueue)); //current_size, first and last is zero
    new_static_queue->total_size = total_size;
    new_static_queue->queue = (int *) calloc(total_size, sizeof(int));
    return new_static_queue;
}

/**
 * @brief Enqueue a new value inside the static queue
 * 
 * @param sq A static queue
 * @param number A value to enqueue
 */
void enqueue(StaticQueue *sq, int number){
    if (sq->current_size == sq->total_size){
        printf("EXCEPTION: QUEUE IS FULL | dequeue before enqueue another value\n");
        exit(EXIT_FAILURE);
    }

    sq->queue[sq->last] = number;
    
    sq->last++;
    sq->current_size++;
}

/**
 * @brief Show the value inside the first position of the queue
 * 
 * @param sq A static queue
 * @return int 
 */
int peek_first(StaticQueue *sq){
    if (sq->current_size == 0) {
        printf("EXCEPTION: QUEUE IS EMPTY | enqueue before show the first value\n");
        exit(EXIT_FAILURE);
    }

    return sq->queue[sq->first];
}

/**
 * @brief Show the value inside the last position of the queue
 * 
 * @param sq A staic queue
 * @return int 
 */
int peek_last(StaticQueue *sq){
    if (sq->current_size == 0) {
        printf("EXCEPTION: QUEUE IS EMPTY | enqueue before show the last value\n");
        exit(EXIT_FAILURE);
    }

    return sq->queue[sq->last-1]; //last always is one index in the front
}

/**
 * @brief Remove the first element of queue 
 * 
 * @param sq A static stack
 * @return int 
 */
int dequeue(StaticQueue *sq){
    if (sq->current_size == 0){
        printf("EXCEPTION: QUEUE IS EMPTY | enqueue before dequeue first value\n");
        exit(EXIT_FAILURE);
    }

    int first_queue_element = sq->queue[sq->first];
    sq->first++;
    sq->current_size--;
    return first_queue_element;
}

/**
 * @brief Print all values inside the queue
 * 
 * @param sq A static stack
 */
void peek_all(StaticQueue *sq){
    if (sq->current_size == 0){
        printf("EXCEPTION: QUEUE IS EMPTY | enqueue one value before show some value in the queue\n");
        exit(EXIT_FAILURE);
    }

    for (int i=sq->first, count=0; count != sq->current_size; i++){
        printf("%d\n", sq->queue[i]);
        count++;
    }
}

#endif 