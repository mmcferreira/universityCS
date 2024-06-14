#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

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
        printf("Erro ao alocar memoria...\n");
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
    
    // Remover espa�os e h�fens, e converter para minusculas
    while (phrase[i] != '\0') {
        if (phrase[i] != ' ' && phrase[i] != '-') {
            temp[j++] = tolower(phrase[i]);
        }
        i++;
    }
    temp[j] = '\0';
    
    // Copiar de volta para a string original
    strcpy(phrase, temp);
    
    // Substituir caracteres acentuados
    i = 0;
    while (phrase[i] != '\0') {
        switch (phrase[i]) {
            case '�': case '�': case '�': case '�': phrase[i] = 'a'; break;
            case '�': case '�': case '�': case '�': phrase[i] = 'o'; break;
            case '�': case '�': case '�': phrase[i] = 'e'; break;
            case '�': case '�': phrase[i] = 'u'; break;
            case '�': case '�': phrase[i] = 'i'; break;
            case '�': phrase[i] = 'c'; break;
        }
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
            return 0;  // Nao � um palindromo
        }
    }
    return 1;  // � um palindromo
}

int main() {
	setlocale(LC_ALL,"portuguese");
    Node *stack = NULL;
    char phrase[SIZE];
    
    printf("Teste se a frase escrita � um pal�ndromo:\n");
    fgets(phrase, SIZE, stdin);
    
    // Remove o caractere de nova linha lido pelo fgets
    size_t len = strlen(phrase);
    if (len > 0 && phrase[len - 1] == '\n') {
        phrase[len - 1] = '\0';
    }
    
    if (palindrom_test(&stack, phrase)) {
        printf("� pal�ndromo!!\n");
    } else {
        printf("N�o � pal�ndromo!!\n");
    }
    printf("%s \n",phrase);
    return 0;
}
