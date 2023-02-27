#include "queue.h"

// Function to create a new node for the Queue
QueueNode *createNode(dataType data)
{
   QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// Function to initialize a Queue
Queue *createQueue(int *errorCheck)
{
   Queue *queue = (Queue *)malloc(sizeof(Queue));
   // if (((*queue)) == NULL)
   // {
   //    *errorCheck = -1;
   // }
   queue->front = queue->rear = NULL;
   *errorCheck = 1;
   return queue;
}

// Function to add an element to the rear of the Queue
void enqueue(Queue *queue, dataType data, int *errorCheck)
{
   QueueNode *newNode = createNode(data);
   if (newNode == NULL)
   {
      *errorCheck = -1;
   }

   if (queue->rear == NULL)
   {
      queue->front = queue->rear = newNode;
      *errorCheck = 1;
      return;
   }
   queue->rear->next = newNode;
   queue->rear = newNode;
   *errorCheck = 1;
}

// Function to remove an element from the front of the Queue
dataType dequeue(Queue *queue, int *errorCheck)
{
   if (isEmpty(queue))
   {
      *errorCheck = -1;
      return;
   }
   QueueNode *temp = queue->front;
   dataType data = temp->data;
   queue->front = queue->front->next;
   if (queue->front == NULL)
   {
      queue->rear = NULL;
   }
   free(temp);
   *errorCheck = 1;
   return data;
}

// Function to check if the Queue is empty
int isEmpty(Queue *queue)
{
   return queue->front == NULL;
}

// Function to check whether the queue is full
int isFull(Queue *queue)
{
   QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
   if (temp == NULL)
   {
      return 1; // Malloc failed to allocate memory, so the queue is "full"
   }
   free(temp);
   return 0;
}

// Function to check the size (element count) of queue
int size(Queue *queue)
{
   int count = 0;
   QueueNode *current = queue->front;
   while (current != NULL)
   {
      count++;
      current = current->next;
   }
   return count;
}

// Function to print the contents of the Queue
void printQueue(Queue *queue)
{
   if (isEmpty(queue))
   {
      printf("Queue is empty.\n");
      return;
   }
   QueueNode *current = queue->front;
   printf("Queue contents: ");
   while (current != NULL)
   {
      printf("%s ", current->data); // Change data output depending on the dataType, for strings %s, for ints %d, etc.
      current = current->next;
   }
   printf("\n");
}

// Function to check the front element of the queue
dataType peek(Queue *queue, int *errorCheck)
{
   if (isEmpty(queue))
   {
      *errorCheck = -1;
   }
   *errorCheck = 1;
   return queue->front->data;
}

// Function to delete the queue
void deleteQueue(Queue *queue)
{
   QueueNode *current = queue->front;
   while (current != NULL)
   {
      QueueNode *temp = current;
      current = current->next;
      free(temp);
   }
   free(queue);
}