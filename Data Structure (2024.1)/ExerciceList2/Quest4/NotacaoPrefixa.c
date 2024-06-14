#include <stdio.h>    // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h>   // Inclui a biblioteca padrão para alocação de memória e funções utilitárias
#include <ctype.h>    // Inclui a biblioteca para funções de manipulação de caracteres
#include <string.h>   // Inclui a biblioteca para manipulação de strings

#define MAX_SIZE 100  // Define um tamanho máximo para a expressão prefixa

// Definição de um nó da fila
typedef struct Node {
    char* data;          // Dado armazenado no nó (uma string)
    struct Node* next;   // Ponteiro para o próximo nó na fila
} Node;

// Definição da fila
typedef struct {
    Node* front;    // Ponteiro para o início da fila
    Node* rear;     // Ponteiro para o final da fila
} Queue;

// Função para criar e inicializar uma nova fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));  // Aloca memória para a fila
    q->front = NULL;   // Inicializa o início da fila como NULL
    q->rear = NULL;    // Inicializa o final da fila como NULL
    return q;          // Retorna o ponteiro para a fila criada
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return (q->front == NULL);  // Retorna 1 (true) se o início da fila for NULL, caso contrário retorna 0 (false)
}

// Função para enfileirar (inserir) um elemento na fila
void enqueue(Queue* q, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));   // Aloca memória para um novo nó
    newNode->data = strdup(data);                  // Copia a string para o novo nó
    newNode->next = NULL;                          // Inicializa o próximo nó como NULL
    if (isEmpty(q)) {                              // Se a fila estiver vazia
        q->front = newNode;                        // O novo nó será o início da fila
        q->rear = newNode;                         // O novo nó também será o final da fila
    } else {                                       // Se a fila não estiver vazia
        q->rear->next = newNode;                   // O novo nó é adicionado ao final da fila
        q->rear = newNode;                         // Atualiza o ponteiro do final da fila para o novo nó
    }
}

// Função para desenfileirar (remover) um elemento da fila
char* dequeue(Queue* q) {
    if (isEmpty(q)) {             // Se a fila estiver vazia
        printf("Fila vazia.\n");  // Imprime mensagem de erro
        exit(EXIT_FAILURE);       // Encerra o programa com falha
    }
    Node* temp = q->front;        // Guarda o nó atual do início da fila
    char* data = temp->data;      // Armazena o dado do nó a ser removido
    q->front = q->front->next;    // Atualiza o início da fila para o próximo nó
    if (q->front == NULL) {       // Se o novo início da fila for NULL
        q->rear = NULL;           // A fila está vazia, então o final também deve ser NULL
    }
    free(temp);                   // Libera a memória do nó removido
    return data;                  // Retorna o dado removido
}

// Função para avaliar a expressão prefixa
int evaluateExpression(Queue* q) {
    if (!isEmpty(q)) {              // Enquanto a fila não estiver vazia
        char* token = dequeue(q);   // Remove o próximo elemento da fila
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) { // Se o token for um dígito (operando)
            return atoi(token);     // Converte a string para inteiro e retorna
        } else {                    // Se o token for um operador
            int operand1 = evaluateExpression(q); // Avalia recursivamente o próximo operando
            int operand2 = evaluateExpression(q); // Avalia recursivamente o segundo operando
            switch (token[0]) {      // Realiza a operação correspondente ao operador
                case '+':
                    return operand1 + operand2;
                case '-':
                    return operand1 - operand2;
                case '*':
                    return operand1 * operand2;
                case '/':
                    if (operand2 != 0) {    // Verifica divisão por zero
                        return operand1 / operand2;
                    } else {
                        printf("Erro: Divisão por zero.\n");
                        exit(EXIT_FAILURE); // Encerra o programa com falha
                    }
                default:
                    printf("Erro: Operador inválido.\n");  // Operador desconhecido
                    exit(EXIT_FAILURE);                    // Encerra o programa com falha
            }
        }
    }
    return 0; // Retorno padrão (nunca deve chegar aqui)
}

// Função principal do programa
int main() {
    Queue* q = createQueue(); // Cria e inicializa uma fila

    printf("Digite a expressão prefixa (números separados por espaço): ");
    char expression[MAX_SIZE]; // Declara um array para armazenar a expressão
    fgets(expression, MAX_SIZE, stdin); // Lê a expressão digitada pelo usuário

    char* token = strtok(expression, " \n"); // Divide a expressão em tokens, considerando espaços e nova linha
    while (token != NULL) {
        enqueue(q, token); // Insere cada token na fila
        token = strtok(NULL, " \n");
    }

    int result = evaluateExpression(q); // Avalia a expressão prefixa
    printf("Resultado da expressão: %d\n", result); // Imprime o resultado

    return 0; // Encerra o programa
}
