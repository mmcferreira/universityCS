#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No{           //estrutura do Nó
    char character;
    int freq;
    struct No *prox;
} stNo;

typedef struct Lista         //estrutura da Lista
{
    int quantElem;
    stNo *prim;
    stNo *ultim;
} stLista;

stNo *criarNo(char charP)                     //cria nós, parâmetro é o caractere lido no arquivo
{
    stNo *no;                              
    no = (stNo *)malloc(sizeof(stNo));
    no->character = charP;                //declara que o conteúdo do nó é o caracter do arquivo
    no->freq = 1;                         //como o nó acabou de ser criado, ele só aparece uma vez
    no->prox = NULL;                      //inicializa o proximo do nó como nulo
    return no;                            // retorna o nó
}

void registraDado(char charP, stLista *listP)   //registra os dados dos nós na lista
{
    stNo *no, *antigoNo, *novoNo;               //cria um novo nó, um no anterior e reserva uma variavel para o primeiro no da lista
    antigoNo = NULL;                            //nó anterior é nulo
    no = listP->prim;                         //nó recebe o primeiro nó da lista

    if (!no)
    {
        listP->prim = criarNo(charP);          //cria o primeiro nó da lista
        listP->quantElem++;                     //aumenta em 1 a quantidade de elementos da nossa lista
    }

    else                                        //se existir um primeiro nó na lista
    {
        while (no){                            //enquanto esse nó existir
            if (no->character == charP)        //se o caracter lido for igual ao caracter do primeiro no
            {
                no->freq++;                    //a frequencia do no aumenta, pois se o conteudo é igual, o no é igual
                break;                         //nó existiu, caracter foi igual, soma um na frequencia desse nó e quebra o while
            }

            else                               //char do no diferente do char do primero elemento da lista, resulta em nós diferentes
            {
               if (no->character > charP)      //se o tamanho do char do primeiro no da lista for maior que o char lido
                {
                    novoNo = criarNo(charP);    //cria um novo nó com esse char lido
                    novoNo->prox = no;          //o proximo do novo nó criado é o primeiro nó da nossa lista
                                                // uma vez que o char lido é menor que o char desse nó
                    listP->quantElem++;//acrescentamos um no na lista, adicionamos mais um na quantidade de elementos da lista

                   if(antigoNo)//se existir um no anterior
                        antigoNo->prox = novoNo;//o proximo desse no anterior será o nosso novo no, que é menor que o first

                   else//se nao existe no anterior
                        listP->prim = novoNo;  //o primeiro no da lista passa a ser o novo no
                    break;//quebra o while
                }

                else {                           //se o novo caracter foi maior do que o caracter do no que ja esta na lista
                    antigoNo = no; //o anterior passa a ser o que ja existia na lista (first), que continua sendo o proprio first
                    no = no->prox;//o que até então era o first, passa a ser o proximo, já que passa a ter um antes dele
                }
            }
        }      
    }

    if(no == NULL){//caso o no seja nulo, pode ocorrer quando atribuímos a ele o next e o next nao existe
        novoNo = criarNo(charP);//criaremos um novo no
        novoNo->prox = NULL;//declaramos o proximo desse novo no como nulo
        listP->quantElem +=1;//aumentamos em um o total de elementos na lista
            if(antigoNo){antigoNo->prox = novoNo;}//se existir um no anterior, o proximo dele será o novo no que acabou de ser criado
    }

}

void showList(stNo *nodeP)      //funcao que mostra a lista
{
    while (nodeP)
    {
        printf("%c: %d \n", nodeP->character, nodeP->freq);
        nodeP = nodeP->prox;        //o no vira o proximo no da lista, o que é a condição de break do while
    }
}
\
void switchPosition(stNo *nodeP, stLista *listP){   //funcao para organizacao com base na frequencia
    stNo *novoNo,*antigNo;                        //cria um novo nó e um no anterior
    novoNo = listP->prim;                 //o novo no começa sendo o primeiro no da lista
    antigNo = NULL;//o no anterior começa nulo

    if(!novoNo){//se nao existir um newNode, ou seja, se nao existir um first na lista
        nodeP->prox = NULL;//o proximo no do nosso no de parametro é nulo
        listP->prim = nodeP;//o primeiro no da lista passa a ser o nosso no de parametro
        return;
    }

    while(novoNo){//enquanto existir um novo no
        if(novoNo->freq > nodeP->freq){//se esse novo no aparecer mais vezes do que o no passado como parametro
            if(antigNo){//se tiver no anterior
                antigNo->prox = nodeP;//o proximo do no anterior é o no parametro, que aparece menos que o novo no
                nodeP->prox = novoNo;//o proximo do no parametro é o novo no, ja que ele aparece mais vezes
            }

            else{//se nao tiver no anterior
                nodeP->prox = listP->prim;//o proximo do no parametro é o first da lista
                listP->prim = nodeP;//o primeiro da lista é o no parametro
            }
            return;
        }
        
        else{//freq do novo no menor que a do no parametro
        antigNo = novoNo;//no anterior recebe novo no
        novoNo = novoNo->prox;//novo no recebe o proximo dele
        }
    }

    if(antigNo){//se existir no anterior
        antigNo->prox = nodeP;//o proximo do no anterior é o no parametro
        nodeP->prox = NULL;//proximo do no parametro é nulo
    }

}

void organizando(stLista *listP){//organizando a lista pela frequencia
    stLista nLista;//criamos uma nova lista
    nLista.prim = nLista.ultim = NULL;
    nLista.quantElem = 0;
    
    stNo *node, *next;//criamos dois novos nos
    node = listP->prim;//no recebe o primeiro elemento da nossa lista
    while(node){//enquanto o no existir
        next = node->prox;//o proximo é o proximo do no
        node->prox = NULL;//o proximo do no passa a ser nulo
        switchPosition(node, &nLista);//usamos a funcao de trocar posicao e passamos para ela o first da lista junto com a nova lista
        node = next;//nosso no passa a ser o proximo
    }

    listP->prim = nLista.prim;//trocamos os dados da primeira lista pelos da segunda
    listP->ultim = nLista.ultim;
    listP->quantElem = nLista.quantElem;

}

void freeList(stLista *listP)//liberar a lista 
{
    stNo *no = listP->prim; // recebe o endereço do primeiro elemento da lista
    while (no)//enquanto a lista tiver um primeiro elemento
    {
        listP->prim = no->prox; // o primeiro elemento se torna o proximo
        free(no);                // liberamos o no que declaramos como primeiro elemento da lista
        no = listP->prim;       // depois de liberar o antigo no, colocamos novamente o primeiro elemento da lista nesse no
                                   //pois o primeiro elemento da lista foi alterado para o que era o proximo
    }
}

int main(void)
{
    FILE *arq; //declarando arquivo
    stLista myList; // não coloca ponteiro para colocar dentro da função e passar o parametro com &
    char charM;//char que será lido no arquivo

    myList.prim = myList.ultim = NULL;//iniciando lista
    myList.quantElem = 0;

    arq = fopen("Texto.txt", "r");//abrindo texto como leitura

    if (!arq)//caso nao exista arquivo
    {
        printf("Error on the txt.");
        exit(0);
    }

    //situacao quando o arquivo existe
    fscanf(arq, "%c", &charM); //lemos o primeiro char do arquivo
    while (!feof(arq))//enquanto o arquivo nao acabar
    {
        registraDado(charM, &myList);//registramos um no para o char lido antes do while
        fscanf(arq, "%c", &charM);//lemos um novo char
    }

    fclose(arq);//fecha arquivo
    showList(myList.prim);
    organizando(&myList);//organizando lista pela frequencia
    printf("----------------");
    showList(myList.prim);
    freeList(&myList);//liberando lista
    return 0;
}