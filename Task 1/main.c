// Test program for the Queue module
// Marijonas Grenda 1 Grupe

#include "queue.h"

int main()
{
   int errorCheck = 0;
   dataType data;
   printf("Hello world!\n");

   Queue *queue = createQueue(&errorCheck);
   printf("Error check: %d\n", errorCheck);
   data.data = "Hello";
   enqueue(queue, data, &errorCheck);
   data.data = "World,";
   enqueue(queue, data, &errorCheck);
   data.data = "this";
   enqueue(queue, data, &errorCheck);
   data.data = "is";
   enqueue(queue, data, &errorCheck);
   data.data = "Marijonas";
   enqueue(queue, data, &errorCheck);

   printf("Is empty: %d\n", isEmpty(queue));
   printf("Is full: %d\n", isFull(queue));
   printf("Size of queue right now: %d\n", size(queue));
   printf("Front element: %s\n", peek(queue, &errorCheck));
   printQueue(queue);
   dequeue(queue, &errorCheck);
   dequeue(queue, &errorCheck);
   printQueue(queue);
   printf("Is empty: %d\n", isEmpty(queue));
   printf("Is full: %d\n", isFull(queue));
   printf("Size of queue right now: %d\n", size(queue));
   printf("hee Front element: %s\n", peek(queue, &errorCheck));
   dequeue(queue, &errorCheck);
   dequeue(queue, &errorCheck);
   dequeue(queue, &errorCheck);
   dequeue(queue, &errorCheck);
   printf("Error check: %d\n", errorCheck); // If dequeue is called when queue is empty
   printQueue(queue);
   printf("Is empty: %d\n", isEmpty(queue));
   printf("Is full: %d\n", isFull(queue));
   printf("Size of queue right now: %d\n", size(queue));
   for (int i = 0; i < 100; ++i)
   {
      data.data = "i";
      enqueue(queue, data, &errorCheck);
   }
   printf("Size of queue right now: %d\n", size(queue));
   printf("Is empty: %d\n", isEmpty(queue));
   printf("Is full: %d\n", isFull(queue));
   printQueue(queue);
   deleteQueue(queue);
}