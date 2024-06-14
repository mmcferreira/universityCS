#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// #include <locale.h>

#define SIZE 100

typedef struct Node {
  char letter;
  struct Node *next;
} Node;

void push(Node **stack, char letter) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode) {
    newNode->letter = letter;
    newNode->next = *stack;
    *stack = newNode;
  } else {
    printf("Erro ao alocar memória...\n");
  }
}

char pop(Node **stack) {
  if (*stack) {
    Node *top = *stack;
    char letter = top->letter;
    *stack = top->next;
    free(top);
    return letter;
  } else {
    return '\0';
  }
}

void standardizePhrase(char phrase[SIZE]) {
  int i = 0, j = 0;
  char temp[SIZE];

  // Remover espaços e hífens, e converter para minúsculas
  while (phrase[i] != '\0') {
    if (phrase[i] != ' ' && phrase[i] != '-') {
      char *comAcento = "áàâãéèêíìîóòôõúùûçÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇ";
      char *semAcento = "aaaaeeeiiioooouuucAAAAEEEIIIOOOOUUUC";

  for (int j = 0; comAcento[j] != '\0'; j++) {
    if (phrase[j] == comAcento[j]) {
      phrase[j] = semAcento[j];
      i++;
    }
      temp[j++] = tolower(phrase[i]);
    }
    i++;
  }
  temp[j] = '\0';

  // Copiar de volta para a string original
  strcpy(phrase, temp);
    i++;
  }
}

int palindrom_test(Node **stack, char phrase[]) {
  int i = 0, j;
  char stringTest[SIZE];

  standardizePhrase(phrase);

  while (phrase[i] != '\0') {
    push(stack, phrase[i]);
    i++;
  }

  for (j = 0; j < i; j++) {
    stringTest[j] = pop(stack);
  }
  stringTest[j] = '\0';

  for (j = 0; j < i; j++) {
    if (phrase[j] != stringTest[j]) {
      return 0;  // Não é um palíndromo
    }
  }
  return 1;  // É um palíndromo
}

int main() {

  // setlocale(LC_ALL,"portuguese");
  Node *stack = NULL;
  char phrase[SIZE];

  printf("Teste se a frase escrita é um palíndromo:\n");
  fgets(phrase, SIZE, stdin);

  // Remove o caractere de nova linha lido pelo fgets
  size_t len = strlen(phrase);
  if (len > 0 && phrase[len - 1] == '\n') {
    phrase[len - 1] = '\0';
  }

  if (palindrom_test(&stack, phrase)) {
    printf("É palíndromo!!\n");
  } else {
    printf("Não é palíndromo!!\n");
  }
  printf("%s \n",phrase);


  return 0;
}
