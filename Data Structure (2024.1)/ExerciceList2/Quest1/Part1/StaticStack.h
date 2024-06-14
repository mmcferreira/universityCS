#define SIZE 10

typedef struct stack {
  int stack[SIZE];
  int count;
} Stack;

void initialize_stack(Stack *s);
void push(Stack *s, int num);
int pop(Stack *s);
void printStack(Stack *s);