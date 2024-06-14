#include <stdio.h>
#include "StaticStack.h"

void initialize_stack(Stack *s) {
    int i;
    s->count = 0;
    for (i = 0; i < SIZE; i++) {
        s->stack[i] = -1;
    }
}

void push(Stack *s, int num) {
    int i;
    if (s->count == SIZE) {
        printf("The stack is full!!\n");
    } else {
        for (i = SIZE - 1; i >= 0; i--) {
            if (s->stack[i] == -1) {
                s->stack[i] = num;
                s->count++;
                break;
            }
        }
    }
}

int pop(Stack *s) {
    int i;
    int element;
    if (s->stack[SIZE - 1] == -1) {
        return -1;
    } else {
        for (i = 0; i < SIZE; i++) {
            if (s->stack[i] != -1) {
                element = s->stack[i];
                s->stack[i] = -1;
                s->count--;
                return element; // Retorna o elemento aqui
            }
        }
    }
    return -1; //Retorno adicional para o caso de nao encontrar um elemento
}

void printStack(Stack *s) {
    int i;
    if(s->stack[SIZE-1]==-1){
    	printf("The stack is empty\n");
	}
	else{
    for (i = 0; i < SIZE; i++) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
    }
}
