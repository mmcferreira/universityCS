#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* criaVetor(int elem){ 											//define o vetor, o asterisco depois do tipo da função retorna um ponteiro.  
    int *vet, j;
    vet = (int*)malloc(elem*sizeof(int));						   //separa um espaço na memória para que o vetor seja criado
    
    if(!vet){
        printf("Erro no malloc!!");
        exit(1);
    }

	srand(time(NULL));
    for(j=0; j<elem; j++){
        vet[j] = rand()%100;
    }
    
    return vet;
}

void mostrarVet(int elem, int *vet){								//exibe o vetor
    int j = 0;
    
    for(j=0; j<elem; j++){
        printf("%d  ", vet[j]);
    }
}

int trocarPosicao(int posInicial, int posFinal, int *vet){
    int startP, centro, temp;

    startP = posInicial;
    centro = vet[posInicial];
    posInicial++;

    while(posInicial<=posFinal){
        while(centro>=vet[posInicial]&&posInicial<=posFinal)
                posInicial++;
        while(posFinal>=0&&centro<vet[posFinal])
            posFinal--;


        if(posInicial<posFinal){
                temp = vet[posInicial];
                vet[posInicial] = vet[posFinal];
                vet[posFinal] = temp;
                posFinal--;
                posInicial++;
        }      
    }
    vet[startP] = vet[posFinal];
    vet[posFinal] = centro;
    return posFinal;
}

void ordenacao(int a, int b, int *vet){
	int p;
	if (a<b){
		p=trocarPosicao(a,b,vet);
		ordenacao(a,p-1,vet);
		ordenacao(p+1,b,vet);
	}
}


 int main (void){
    int elem, *vet, posF; //pivo é o elemento que deve ser colocado na posição certa
    printf("Digite o num. de posicoes do vetor: ");
    	scanf("%d", &elem);
    	vet = criaVetor(elem);
    	    printf("\n Vetor Inicial: \n");
    	mostrarVet(elem,vet);
    	
    posF = trocarPosicao(0, elem-1, vet);
    	printf("\n\n Posicao do Pivo no Vetor Inicial: %d\n", posF);
    	printf("\n Vetor Novo:\n");
    	mostrarVet(elem, vet);
    	
	ordenacao(0,elem-1,vet);
		printf("\n\nVetor Organizado:\n");
		mostrarVet(elem,vet);
    free(vet);

    return 0;
 }

