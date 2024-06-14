typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *start;
  Node *end;
  int size;
} Queue;

Queue *createQueue();
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
void printQueue(Queue *queue);
