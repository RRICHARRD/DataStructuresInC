#ifndef STATIC_QUEUE_IMPLEMENTATION
#define STATIC_QUEUE_IMPLEMENTATION

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

#endif