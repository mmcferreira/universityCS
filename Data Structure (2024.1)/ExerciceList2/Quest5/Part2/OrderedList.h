// Estrutura de nó da lista
typedef struct Node {
  void *data;        // Ponteiro genérico para o dado
  struct Node *next; // Ponteiro para o próximo nó
} Node;

// Estrutura da lista
typedef struct {
  Node *head; // Ponteiro para o primeiro nó (head)
  int size;   // Tamanho atual da lista
} OrderedList;

// Função para inicializar a lista
OrderedList *createOrderedList();

// Função para verificar se a lista está vazia
int isOrderedListEmpty(OrderedList *list);

// Função para inserir um elemento na lista
void insert(OrderedList *list, void *data);

// Função para imprimir a lista
void printOrderedList(OrderedList *list);

// Função para liberar a memória ocupada pela lista
void destroyOrderedList(OrderedList *list);