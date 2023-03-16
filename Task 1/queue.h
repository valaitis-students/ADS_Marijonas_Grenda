#ifndef GENERAL_QUEUE_MODULE
#define GENERAL_QUEUE_MODULE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for data type
typedef struct dataType
{
   char *data;
} dataType;

// Struct for QueueNode
typedef struct QueueNode
{
   dataType data;
   struct QueueNode *next;
} QueueNode;

// Struct for Queue
typedef struct Queue
{
   QueueNode *front;
   QueueNode *rear;
} Queue;

// Creation functions-----------
QueueNode *createNode(dataType data); // Node creation (no usage seperately, automatically used in other functions)

Queue *createQueue(int *errorCheck); // Returns a pointer to the queue
                                     // errorCheck will turn to -1 if malloc fails, 1 if everything is fine
// Enqueue and dequeue--------------

void enqueue(Queue *queue, dataType data, int *errorCheck); // Insert a int element into the queue
                                                            // errorCheck will turn to -1 if malloc fails, 1 if everything is fine

dataType dequeue(Queue *queue, int *errorCheck); // Dequeue the element from the front of the queue, errorCheck will turn to -1 if queue is empty
                                                 // errorCheck will turn to -1 if queue is empty, 1 if everything is fine
// Functions for information about the queue-----------------------

dataType peek(Queue *queue, int *errorCheck); // Get the element from the front of the queue without removing it
                                              // errorCheck will turn to -1 if queue is empty, 1 if everything is fine

int isEmpty(Queue *queue); // Check if the queue is empty (returns 0 if not empty, 1 if empty)

int isFull(Queue *queue); // Check if the queue is full (returns 0 if not full, 1 if full)

int size(Queue *queue); // Returns the size (element count) of the queue

void printQueue(Queue *queue); // Prints the contents of the queue

// Deletion-----------------------------------

void deleteQueue(Queue *queue); // Deletes the queue (Valgrind confirmed it works well | ;)) | )

#endif