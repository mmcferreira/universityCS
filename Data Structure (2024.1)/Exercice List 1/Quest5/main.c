#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void busca_recursiva(char *string, char *substring, int index) {
    static int aux = 0; // Variável estática para contar o número de ocorrências
    int i, j = 0;
    int start, end;
    for (i = index; i < strlen(string); i++) {
        if (string[i] == substring[j]) {
            j++;
        } else {
            j = 0;
        }
        if (j == strlen(substring)) { // Encontrou a substring
            aux++;
            start = i - strlen(substring) + 1;
            end = i;
            printf("%dª ocorrência encontrada da posição %d até a posição %d\n", aux, start, end);
            // Chama recursivamente para procurar a próxima ocorrência
            return busca_recursiva(string, substring, i + 1);;
        }
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");
    char string[100];
    char substring[100];
   
    printf("Insira a string desejada:\n");
    fgets(string, 100, stdin);
    printf("Insira a substring a ser buscada:\n");
    fgets(substring, 100, stdin);
   
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
    if (substring[strlen(substring) - 1] == '\n') {
        substring[strlen(substring) - 1] = '\0';
    }
   
    busca_recursiva(string, substring, 0); // Chama a função de busca recursiva
   
    return 0;
}
