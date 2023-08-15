#ifndef STATIC_QUEUE_SPECIFICATION
#define STATIC_QUEUE_SPECIFICATION

#include <stdio.h> 
#include <stdbool.h>

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
typedef struct staticQueue StaticQueue, Queue;

/**
 * @brief Create a static queue
 * 
 * @param total_size Full size of queue
 * @return StaticQueue* 
 */
StaticQueue *create_static_queue(const unsigned long total_size);

/**
 * @brief Enqueue a new value inside the static queue
 * 
 * @param sq A static queue
 * @param number A value to enqueue
 */
void enqueue(StaticQueue *sq, int number);

/**
 * @brief Show the value inside the first position of the queue
 * 
 * @param sq A static queue
 * @return int 
 */
int peek_first(StaticQueue *sq);

/**
 * @brief Show the value inside the last position of the queue
 * 
 * @param sq A staic queue
 * @return int 
 */
int peek_last(StaticQueue *sq);

/**
 * @brief Remove the first element of queue 
 * 
 * @param sq A static stack
 * @return int 
 */
int dequeue(StaticQueue *sq);

/**
 * @brief Print all values inside the queue
 * 
 * @param sq A static stack
 */
void peek_all(StaticQueue *sq);

/**
 * @brief Get the total size static queue
 * 
 * @param sq A static queue 
 * @return unsigned long 
 */
unsigned long get_total_size(StaticQueue *sq);

/**
 * @brief Get the current fill size of static queue
 * 
 * @param sq A static queue
 * @return unsigned long 
 */
unsigned long get_fill_size(StaticQueue *sq);

/**
 * @brief dequeue values one behind the other
 * 
 * @param sq Static queue
 * @param how_much Quantity of values to dequeue from static queue
 */
void dequeue_frenetically(StaticQueue *sq, unsigned long how_much);

/**
 * @brief Destroy data structure from memory
 * 
 * @param sq A static Queue
 * @param intirely A boolean to validade full destroy of data strutucture from memory
 */
void destroy(StaticQueue **sq, bool intirely);

#endif