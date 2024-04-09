#include <stdlib.h>  // random
#include <time.h>

void matrizEntrada (int mat[10][10]){
    int i,j;

    srand (time(0));
    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            mat[i][j]=rand() %100;
        }
    }
}

void mostrarMatriz (int mat[10][10]){
    int i, j;

    for ( i = 0; i < 10; i++){
        printf("\n");
        for (j=0;j<10;j++){
            printf(" %d", mat[i][j]);
        }
    }
   
}

void vetorParametro(int k, int vetorK[10], int mat[10][10]) {
    int r, i, j;

    srand(time(0));
    for (r = 0; r < k; r++) {
        i = rand() % 10;
        j = rand() % 10;
        vetorK[r] = mat[i][j];
    }
}

void mostrarVet(int k, int v[10]) {
    int i;

    for (i = 0; i < k; i++) {
        printf(" %d ", v[i]);
    }
}

void calcVetorNovo(int k, int vetNovo[10], int matEnt[10][10], int matIndice[10][10]){
    int vetCont[10], i, j, r;

    for (i = 0; i < k; i++) {
        vetCont[i] = 0;
        vetNovo[i] = 0;
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            r = matIndice[i][j];
            vetNovo[r] += matEnt[i][j];
            vetCont[r] += 1;
        }
    }

    for (i = 0; i < k; i++) {
        vetNovo[i]/=(float)vetCont[i];
    }
}

void gerarMatInd(int k, int vetorK[10], int matEnt[10][10], int matIndice[10][10]) {
    int i, j, r, rMin, dist, distMin;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++) {
            distMin = 500;
            for (r = 0; r < k; r++) {
                dist = abs(matEnt[i][j] - vetorK[r]);
                if (distMin > dist) {
                    distMin = dist;
                    rMin = r;
                }
            }
            matIndice[i][j] = rMin;
        }
}

int calcDist(int k, int vetParam[10], int vetNovo[10]){
    int i, distancia=0;

    for(i=0; i<k; i++){
        distancia+=abs(vetNovo[i]-vetParam[i]);
    }
    return distancia;
}

void transfVetor(int k, int vetParam[10], int vetNovo[10]){
    int i;

    for (i = 0; i<k; i++){
        vetParam[i]=vetNovo[i];
    }
}

void matrizSaida(int vetNovo[10], int matIndice[10][10], int matSaida[10][10]){
    int i,j;

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            int indice=matIndice[i][j];
            matSaida[i][j]=vetNovo[indice];
        }
    }
}

int main(void) {
    int matEnt[10][10], matIndice[10][10], matSaida[10][10];
    int k,d, limite=5;
    int vetParam[10],vetNovo[10];

    printf("\n Matriz de Entrada:\n");
        matrizEntrada(matEnt);                                             //cria a Matriz Entrada
        mostrarMatriz(matEnt);

    printf("\n\n Digite o valor de K (inteiro): ");
    scanf("%d",&k);

    vetorParametro(k,vetParam,matEnt);                                 //cria o vetor parâmetro
        printf("\n Vetor de Parametro:\n");
        mostrarVet(k,vetParam);

    while (1){
        printf("\n");
        gerarMatInd(k, vetParam, matEnt, matIndice);                       //gera matriz índice
            printf("\n\n Matriz Indice:\n");
            mostrarMatriz(matIndice);

        calcVetorNovo(k,vetNovo,matEnt,matIndice);                         //calcula o novo vetor parâmetro
            printf("\n\n Vetor de Parametro Novo:\n");
            mostrarVet(k,vetNovo);  

        d=calcDist(k,vetParam,vetNovo);                               //Calcular distância dos valores dos vetores
            if(d<limite){
              break;
         }
            else{
            transfVetor(k,vetParam,vetNovo);
        }  
 }

    matrizSaida(vetNovo, matIndice, matSaida);
        printf("\n");
        mostrarMatriz(matSaida);
}