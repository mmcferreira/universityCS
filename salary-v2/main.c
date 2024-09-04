#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define LIMPA_TELA "cls"
#else
    #define LIMPA_TELA "clear"
#endif

typedef struct {
    int inicio_horas;
    int inicio_minutos;
    int fim_horas;
    int fim_minutos;
} IntervaloHoras;

int alocaIntervalos(IntervaloHoras **pIntervalos, int *tamanho) {
    int inicio_horas, inicio_minutos, fim_horas, fim_minutos;

    printf("Digite a hora de início (HH MM): ");
    scanf("%d %d", &inicio_horas, &inicio_minutos);
    
    printf("\nDigite a hora de término (HH MM): ");
    scanf("%d %d", &fim_horas, &fim_minutos);

    // Ajusta o horário de término se for antes do horário de início
    if (fim_horas < inicio_horas || (fim_horas == inicio_horas && fim_minutos < inicio_minutos)) {
        printf("\nO horário de término é anterior ao horário de início.\n");
        // Ajuste para cruzar a meia-noite
        fim_horas += 24;
    }

    *tamanho += 1;
    *pIntervalos = (IntervaloHoras*) realloc(*pIntervalos, *tamanho * sizeof(IntervaloHoras));
    if (*pIntervalos == NULL) {
        printf("\nErro na alocação de memória.\n");
        exit(1);  // Encerrar o programa em caso de falha na alocação
    }

    (*pIntervalos)[*tamanho - 1].inicio_horas = inicio_horas;
    (*pIntervalos)[*tamanho - 1].inicio_minutos = inicio_minutos;
    (*pIntervalos)[*tamanho - 1].fim_horas = fim_horas;
    (*pIntervalos)[*tamanho - 1].fim_minutos = fim_minutos;

    return 1;
}


void exibeIntervalos(IntervaloHoras *intervalos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        // Ajusta o horário de término se ultrapassar a meia-noite
        int fim_horas_ajustado = intervalos[i].fim_horas;
        int fim_minutos_ajustado = intervalos[i].fim_minutos;
        if (fim_horas_ajustado < intervalos[i].inicio_horas || 
           (fim_horas_ajustado == intervalos[i].inicio_horas && fim_minutos_ajustado < intervalos[i].inicio_minutos)) {
            fim_horas_ajustado += 24;
        }
        
        printf("\nIntervalo %d: Início - %02d:%02d | Fim - %02d:%02d", 
               i + 1, intervalos[i].inicio_horas, intervalos[i].inicio_minutos, 
               fim_horas_ajustado % 24, fim_minutos_ajustado);
    }
    printf("\nPressione Enter para continuar.");
    while (getchar() != '\n');  // Limpa o buffer de entrada
}

void excluirIntervalo(IntervaloHoras **pIntervalos, int *tamanho) {
    int indice;

    if (*tamanho == 0) {
        printf("\nNenhum intervalo cadastrado.\n");
        return;
    }

    // Exibe os intervalos atuais
    exibeIntervalos(*pIntervalos, *tamanho);

    printf("\nDigite o número do intervalo a ser excluído (1 a %d) ou 0 para sair: ", *tamanho);
    scanf("%d", &indice);

    if (indice < 1 || indice > *tamanho) {
        printf("\nErro: Índice inválido.\n");
        return;
    }

    // Remove o intervalo selecionado
    for (int i = indice - 1; i < *tamanho - 1; i++) {
        (*pIntervalos)[i] = (*pIntervalos)[i + 1];
    }

    *tamanho -= 1;
    *pIntervalos = (IntervaloHoras*) realloc(*pIntervalos, *tamanho * sizeof(IntervaloHoras));
    if (*pIntervalos == NULL && *tamanho > 0) {
        printf("\nErro na alocação de memória.\n");
        exit(1);  // Encerrar o programa em caso de falha na alocação
    }
    printf("\nIntervalo excluído com sucesso.\n");
}


void calculaPagamento(IntervaloHoras *intervalos, int tamanho, int valorPorHora) {
    int total_horas = 0, total_minutos = 0;
    float valor;

    for (int i = 0; i < tamanho; i++) {
        int horas = intervalos[i].fim_horas - intervalos[i].inicio_horas;
        int minutos = intervalos[i].fim_minutos - intervalos[i].inicio_minutos;

        // Ajusta se minutos são negativos
        if (minutos < 0) {
            minutos += 60;
            horas -= 1;
        }

        // Ajusta se horas são negativas
        if (horas < 0) {
            horas += 24;
        }

        total_horas += horas;
        total_minutos += minutos;
    }

    total_horas += total_minutos / 60;
    total_minutos = total_minutos % 60;

    valor = ((float)(total_horas) + (float)(total_minutos) / 60) * valorPorHora;

    // Exibe o total de horas e minutos trabalhados e o valor a ser pago
    printf("\nTotal de horas e minutos trabalhados: %d:%02d\n", total_horas, total_minutos);
    printf("Valor a ser pago: R$%.2f\n", valor);
    printf("\nPressione Enter para continuar.");
    while (getchar() != '\n');  // Limpa o buffer de entrada
}

int main() {
    IntervaloHoras *pIntervalos = NULL;
    int tamanho = 0;
    int opcao;
    int valorPorHora;
    char mensagem[100] = "";  // Variável para armazenar a mensagem da execução anterior

    do {
        // Limpa a tela e exibe a mensagem anterior
        system(LIMPA_TELA);
        printf("%s\n", mensagem);

        printf("\n[1] - Incluir Intervalo");
        printf("\n[2] - Consultar Intervalos");
        printf("\n[3] - Excluir Intervalo");
        printf("\n[4] - Calcular Pagamento");
        printf("\n[0] - Sair\n");
        printf("\nEntre com uma opcao: ");
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer de entrada após a leitura da opção

        switch (opcao) {
            case 1:
                if (alocaIntervalos(&pIntervalos, &tamanho)) {
                    snprintf(mensagem, sizeof(mensagem), "Intervalo adicionado com sucesso.");
                } else {
                    snprintf(mensagem, sizeof(mensagem), "Erro ao adicionar intervalo.");
                }
                break;
            case 2:
                if (tamanho > 0) {
                    exibeIntervalos(pIntervalos, tamanho);
                } else {
                    snprintf(mensagem, sizeof(mensagem), "Nenhum intervalo cadastrado.");
                }
                break;
            case 3:
                if (tamanho > 0) {
                    excluirIntervalo(&pIntervalos, &tamanho);
                    snprintf(mensagem, sizeof(mensagem), "Intervalo excluído com sucesso.");
                } else {
                    snprintf(mensagem, sizeof(mensagem), "Nenhum intervalo cadastrado para excluir.");
                }
                break;
            case 4:
                if (tamanho > 0) {
                    printf("\nDigite o valor por hora: ");
                    scanf("%d", &valorPorHora);
                    getchar();  // Limpa o buffer de entrada após a leitura do valor por hora
                    calculaPagamento(pIntervalos, tamanho, valorPorHora);
                    snprintf(mensagem, sizeof(mensagem), "Cálculo do pagamento realizado com sucesso.");
                } else {
                    snprintf(mensagem, sizeof(mensagem), "Nenhum intervalo cadastrado para calcular pagamento.");
                }
                break;
            case 0:
                snprintf(mensagem, sizeof(mensagem), "Saindo...");
                break;
            default:
                snprintf(mensagem, sizeof(mensagem), "Opção inválida!");
                break;
        }
    } while (opcao != 0);

    free(pIntervalos);

    return 0;
}