typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *startList;
    Node *endList;
    int size;
} List;

List *createList();
void insertInList(List *list, int value);
void printList(List *list);
void freeList(List *list);