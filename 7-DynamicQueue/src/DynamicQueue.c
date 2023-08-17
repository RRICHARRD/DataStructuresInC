#ifndef STATIC_QUEUE_IMPLEMENTATION
#define STATIC_QUEUE_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#include <DynamicQueue.h>

/**
 * @brief A doubly node struture
 * 
 * @attention Utilize DoublyNode or Node to refers to structure doublyNode
 * 
 * @param value {int} A value to insert inside a node
 * @param next_node {DoublyNode *} A pointer to next node
 * @param preview_node {DoublyNode *} A pointer to preview node
 */
typedef struct doublyNode {
    int value;
    struct doublyNode *next_node;
    struct doublyNode *preview_node;
} DoublyNode, Node;

/**
 * @brief A Dynamic Queue strucuture
 * 
 * @attention Utilize DynamicQueue or Queue to refers to struct dynamicQueue
 * 
 * @param queue {DoublyNode *} First node of queue
 * @param last_node {DoublyNode *} Last node of queue
 * @param size {unsigned long int} Integer number to identify size of queue  
 * 
 */
typedef struct dynamicQueue {
    DoublyNode *queue;
    DoublyNode *last_node;
    unsigned long int size;
} DynamicQueue, Queue;

/**
 * @brief Create a new node
 * 
 * @param value A number to store inside the node
 * @return DoublyNode* 
 */
DoublyNode *create_new_node(int value) {
    DoublyNode *new_doubly_node = (DoublyNode *) calloc(1, sizeof(DoublyNode));
    new_doubly_node->value = value;
    return new_doubly_node;
}

/**
 * @brief Create a new dynamic queue
 * 
 * @return DynamicQueue* 
 */
DynamicQueue *create_new_dynamic_queue() {
    return (DynamicQueue *) calloc(1, sizeof(DynamicQueue)); //queue is NULL
}

/**
 * @brief Insert a new node in the final of queue
 * 
 * @param dq A Dynamic queue
 * @param value A value to insert inside the node
 */
void enqueue(DynamicQueue *dq, int value) {
    if (dq->queue == NULL) {
        dq->queue = (DoublyNode *) calloc(1, sizeof(DoublyNode));
        dq->last_node = dq->queue;
        dq->queue->value = value;
        dq->size++;

        return;
    }

    //better than iterate each node from first to last
    DoublyNode *new_doubly_node = (DoublyNode *) calloc(1, sizeof(DoublyNode));
    new_doubly_node->preview_node = dq->last_node;
    dq->last_node->next_node = new_doubly_node;
    dq->last_node = new_doubly_node;
    new_doubly_node->value = value;
    
    dq->size++;
}

/**
 * @brief Get the size of queue
 * 
 * @param dq Dynamic Queue
 */
unsigned long int size(DynamicQueue *dq) {
    return dq->size;
}

/**
 * @brief Show values from the first to last
 * 
 * @param dq Dynamic queue
 */
void show(DynamicQueue *dq) {
    if (dq->size == 0) {
        printf("EXEPTION: QUEUE IS EMPTY | enqueue a new value before show any value from queue");
        exit(EXIT_FAILURE);
    }

    DoublyNode *node_reader = dq->queue;

    while (node_reader->next_node != NULL) {
        printf("address: %p value: %ld\n", node_reader, node_reader->value);
        node_reader = node_reader->next_node;
    }
    printf("address: %p value: %ld\n", node_reader, node_reader->value);
}

/**
 * @brief Remove the first element of queue
 * 
 * @param dq Dynamics queue
 * @return int
 */
int dequeue(DynamicQueue *dq) {
    if (dq->size == 0) {
        printf("EXECEPTION: QUEUE IS EMPTY | Enqueue one value before dequeue");
        exit(EXIT_FAILURE);
    }

    DoublyNode *first_node = dq->queue;
    dq->queue = dq->queue->next_node;
    int value = first_node->value; 
    free(first_node);

    return value;
}

#endif