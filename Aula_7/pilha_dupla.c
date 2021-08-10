#include "pilha_dupla.h"

#define MaxTam 1000

struct indicePilha{
    int topo;
    int base;
};

struct pilhaDupla{
    Produto* produto[MaxTam]; // Vetor onde os itens são guardados.
    IndicePilha pilha1; // Cada pilha tem seus índices topo e base.
    IndicePilha pilha2;
};

PilhaDupla* criaPilhaDupla(){
    PilhaDupla* pilhaDupla = (PilhaDupla*) malloc(sizeof(PilhaDupla));
    
    pilhaDupla->pilha1.base = 0;
    pilhaDupla->pilha1.topo = -1; /* cresce para a direita */
    
    pilhaDupla->pilha2.base = MaxTam - 1;
    pilhaDupla->pilha2.topo = MaxTam; /* cresce para a esquerda */

    return pilhaDupla;
}

void destroiPilhaDupla(PilhaDupla* pilhaDupla){
    // Pilha 1 vai da base até seu topo do início do vetor para a direita.
    for(int i = pilhaDupla->pilha1.base; i <= pilhaDupla->pilha1.topo; i++){
        destroiProduto(pilhaDupla->produto[i]);
    }

    // Pilha 2 vai da base até seu topo do fim do vetor para a esquerda.
    for(int i = pilhaDupla->pilha2.base; i >= pilhaDupla->pilha2.topo; i--){
        destroiProduto(pilhaDupla->produto[i]);
    }
    free(pilhaDupla);
}

void push(PilhaDupla* pilhaDupla, Produto* produto, int numPilha){ // Insere.
    // Verificando se a pilha está cheia (ou seja, se é possível inserir elementos).
    if(pilhaDupla->pilha1.topo + 1 == pilhaDupla->pilha2.topo){
        printf("Pilha cheia. Nao eh possivel inserir elementos.\n");
        return;
    }
    
    if(numPilha == 1){
        pilhaDupla->pilha1.topo++;
        pilhaDupla->produto[pilhaDupla->pilha1.topo] = produto;
    
    } else if(numPilha == 2){
        pilhaDupla->pilha2.topo--;
        pilhaDupla->produto[pilhaDupla->pilha2.topo] = produto;
    
    } else{
        printf("Pilha %d não existe. Coloque uma pilha valida.\n", numPilha);
    }
}

void pop(PilhaDupla* pilhaDupla, int numPilha){ // Remove.
    if(numPilha == 1){
        // Verificando se é possível remover elementos.
        if(pilhaDupla->pilha1.topo == -1){
            printf("Nao ha elementos para retirar da pilha %d.\n", numPilha);
            return;
        
        } else{
            destroiProduto(pilhaDupla->produto[pilhaDupla->pilha1.topo]);
            pilhaDupla->pilha1.topo--;
        }


    } else if(numPilha == 2){
        // Verificando se é possível remover elementos.
        if(pilhaDupla->pilha2.topo == MaxTam){
            printf("Nao ha elementos para retirar da pilha %d.\n", numPilha);
            return;
        
        } else{
            destroiProduto(pilhaDupla->produto[pilhaDupla->pilha2.topo]);
            pilhaDupla->pilha2.topo++;
        }
    } else{
        printf("Pilha %d não existe. Coloque uma pilha valida.\n", numPilha);
    }
}

void printPilha(PilhaDupla* pilhaDupla){
    // Imprimindo pilha 1.
    printf("Pilha 1:\n\n");
    for(int i = pilhaDupla->pilha1.topo; i >= pilhaDupla->pilha1.base; i--){
        imprimeProduto(pilhaDupla->produto[i]);
        printf("\n");
    }

    // Imprimindo pilha 2.
    printf("Pilha 2:\n\n");
    for(int i = pilhaDupla->pilha2.topo; i <= pilhaDupla->pilha2.base; i++){
        imprimeProduto(pilhaDupla->produto[i]);
        printf("\n");
    }
}
