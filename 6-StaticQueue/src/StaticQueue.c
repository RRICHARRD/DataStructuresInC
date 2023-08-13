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
 * 
 * @cite I saw somthing like (current_index + 1) % my_total_size to know the next position of last element, 
 * that works but is more complex, I project that line to validade tha last index, is more easy to understand and simple
 *  
 */
void enqueue(StaticQueue *sq, int number){
    if (sq->current_size == sq->total_size){
        printf("EXCEPTION: QUEUE IS FULL | dequeue before enqueue another value\n");
        exit(EXIT_FAILURE);
    }

    if (sq->last > sq->total_size-1) sq->last = 0;

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
        printf("EXCEPTION: QUEUE IS EMPTY | enqueue some value before dequeue some value\n");
        exit(EXIT_FAILURE);
    }

    int first_queue_element = sq->queue[sq->first];
    
    sq->first++;
    if (sq->first > sq->total_size-1) sq->first = 0;
    
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

    for (unsigned long i=sq->first, count=1; count <= sq->current_size; i++){
        if (i > sq->total_size-1) i = 0;

        printf("queue[%ld]: %d\n", i, sq->queue[i]);
        count++;
    }
}

/**
 * @brief Get the total size static queue
 * 
 * @param sq A static queue 
 * @return unsigned long 
 */
unsigned long get_total_size(StaticQueue *sq){
    return sq->total_size;
}

/**
 * @brief Get the current fill size of static queue
 * 
 * @param sq A static queue
 * @return unsigned long 
 */
unsigned long get_fill_size(StaticQueue *sq){
    return sq->current_size;
}

/**
 * @brief dequeue values one behind the other successively
 * 
 * @param sq Static queue
 * @param how_much Quantity of values to dequeue from static queue
 */
void dequeue_frenetically(StaticQueue *sq, unsigned long how_much){
    for(int i=1; i<=how_much; i++){
        printf("dequeued: %d\n", dequeue(sq));
    }
}

#endif 