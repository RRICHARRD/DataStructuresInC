#ifndef STATIC_QUEUE_SPECIFICATION
#define STATIC_QUEUE_SPECIFICATION

/**
 * @brief A doubly node struture
 * 
 * @attention Utilize DoublyNode or Node to refers to structure doublyNode
 * 
 * @param value {int} A value to insert inside a node
 * @param next_node {DoublyNode *} A pointer to next node
 * @param preview_node {DoublyNode *} A pointer to preview node
 */
typedef struct doublyNode DoublyNode, Node;

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
typedef struct dynamicQueue DynamicQueue, Queue;

/**
 * @brief Create a new node
 * 
 * @param value A number to store inside the node
 * @return DoublyNode* 
 */
DoublyNode *create_new_node(int value);

/**
 * @brief Create a new dynamic queue
 * 
 * @return DynamicQueue* 
 */
DynamicQueue *create_new_dynamic_queue();

/**
 * @brief Insert a new node in the final of queue
 * 
 * @param dq A Dynamic queue
 * @param value A value to insert inside the node
 */
void enqueue(DynamicQueue *dq, int value);

/**
 * @brief Get the size of queue
 * 
 * @param dq Dynamic Queue
 */
unsigned long int size(DynamicQueue *dq);

/**
 * @brief Show values from the first to last
 * 
 * @param dq Dynamic queue
 */
void show(DynamicQueue *dq);

/**
 * @brief Remove the first element of queue
 * 
 * @param dq Dynamics queue
 * @return int
 */
int dequeue(DynamicQueue *dq);

/**
 * @brief Eliminate one or more values from dynamic queue frenetically
 * 
 * @param sq Dynamic queue 
 * @param quantity Quantity of elements to dequeue
 */
void dequeue_frenetically(DynamicQueue *sq, unsigned long int quantity);

/**
 * @brief Destroy queue elements
 * 
 * @param dq Dynamic queue
 */
void destroy(DynamicQueue **dq);

#endif