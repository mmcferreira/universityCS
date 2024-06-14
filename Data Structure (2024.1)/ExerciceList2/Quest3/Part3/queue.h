// Estrutura de nó da fila
typedef struct Node {
  void *data;        // Ponteiro genérico para o dado
  struct Node *next; // Ponteiro para o próximo nó
} Node;

// Estrutura da fila
typedef struct {
  Node *front; // Ponteiro para o primeiro nó (front)
  Node *rear;  // Ponteiro para o último nó (rear)
  int size;    // Tamanho atual da fila
} Queue;

Queue *createQueue();

int isEmpty(Queue *queue);

void enqueue(Queue *queue, void *data);

void *dequeue(Queue *queue);

int size(Queue *queue);

void printQueue(Queue *queue);

void destroyQueue(Queue *queue);
