#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned long long int id;
    float cr;
} Student;

typedef struct node {
    Student *student;
    struct node *next;    
} Node;

Node* insert_student(Node** lista, unsigned long long int id, float cr) {
    Node *newStudent = (Node*)malloc(sizeof(Node));
    if (newStudent) {
        newStudent->student = (Student*)malloc(sizeof(Student)); // Aloca memória para o aluno
        if (newStudent->student) {
            newStudent->student->id = id;
            newStudent->student->cr = cr;
            newStudent->next = NULL;
            if (*lista == NULL) {
                *lista = newStudent;
            } else {
                // Insira o novo aluno no final da lista
                Node *temp = *lista;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newStudent;
            }
        } else {
            printf("Erro ao alocar memória para o aluno.\n");
        }
    } else {
        printf("Erro ao alocar memória para o nó.\n");
    }
    return *lista;
}

void sortList(Node **list) {
    int troca;
    Node *p;
    Node *last = NULL;

    if (*list == NULL || (*list)->next == NULL)
        return;

    do {
        troca = 0;
        p = *list;

        while (p->next != last) {
            if (p->student->cr > p->next->student->cr) {
                // Troca os alunos
                Student *temp = p->student;
                p->student = p->next->student;
                p->next->student = temp;
                troca = 1;
            }
            p = p->next;
        }
        last = p;
    } while (troca);
}

void print_list(Node *lista) {
    Node *temp = lista;
    if(!temp){
    printf("\nLista vazia!!\n");
}
    while (temp) {
        printf("ID: %llu, CR: %.1f\n", temp->student->id, temp->student->cr);
        temp = temp->next;
    }
}

void write_students_to_file(Node *lista, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Node *aux = lista;
    while (aux) {
        fprintf(file, "%llu - %.2f\n", aux->student->id, aux->student->cr);
        aux = aux->next;
    }

    fclose(file);
}

Node* read_students_from_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    Node *lista = NULL;
    unsigned long long int id;
    float cr;
    while (fscanf(file, "%llu %f", &id, &cr) != EOF) {
        insert_student(&lista, id, cr);
    }

    fclose(file);
    return lista;
}

int main() {
    Node *lista = NULL;
    unsigned long long int id;
    short int select;
    float cr;
    do {
    printf("--------------------------------\n");
        printf("0-Sair\n1-Inserir aluno\n2-Mostrar lista\n3-Salvar lista ordenada em arquivo\n4-Recuperar lista do arquivo\n");
        printf("--------------------------------\n");
        scanf("%hd",&select);
        switch(select){
            case 1:
                printf("Informe seu id:\n");
                scanf("%llu", &id);
                printf("Informe seu CR:\n");
                scanf("%f", &cr);
                insert_student(&lista, id, cr);
                break;
            case 2:
                printf("Lista de estudantes:\n");
                print_list(lista);
                break;
            case 3:
                printf("Ordenando lista por CR...\n");
                sortList(&lista);
                printf("Salvando lista ordenada em arquivo...\n");
                write_students_to_file(lista, "alunos_ordenados.txt");
                printf("Lista ordenada foi salva no arquivo 'alunos_ordenados.txt'.\n");
                break;
            case 4:
                printf("Recuperando lista do arquivo...\n");
                lista = read_students_from_file("alunos_ordenados.txt");
                if (lista != NULL) {
                    printf("Lista recuperada do arquivo:\n");
                    print_list(lista);
                }
                break;
            default:
                printf("\nOpcao invalida\n");    
                break;
       }  
    } while(select != 0);

    return 0;
}
