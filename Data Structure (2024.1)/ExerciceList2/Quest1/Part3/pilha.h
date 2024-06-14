typedef struct stack {
  void *data;
  struct stack *link;
} StackElements;

//É através desta "cabeça da pilha" que acessaremos a pilha
typedef struct {
  int count;
  StackElements *top;
} HeadStack;

HeadStack *createStack();
int empty(HeadStack *head);
void push(HeadStack *head, void *data);
void *pop(HeadStack *head);
void *elementTop(HeadStack *head);
int totalElements(HeadStack *head);
HeadStack *freeStack(HeadStack *head);