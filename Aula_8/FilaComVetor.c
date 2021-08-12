#include "Fila.h"

#define MAX 10

struct fila{
    int first;
    int tam;
    Produto* produto[MAX];
};

Fila* criaFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->first = 0;
    fila->tam = 0;
    return fila;
}

void destroiFila(Fila* fila){
    if(fila == NULL){
        return;
    }
    free(fila);
}

void insere(Fila* fila, Produto* produto){
    if(fila->tam >= MAX){
        printf("Fila cheia. Nao e possivel inserir elementos.\n");
        return;
    }
    
    fila->produto[(fila->first + fila->tam) % MAX] = produto;
    fila->tam++;
}

Produto* retira(Fila* fila){
    if(fila->tam == 0){
        printf("Fila vazia. Nao e possivel retirar elementos.\n");
        return NULL;
    }
    
    Produto* retirado = fila->produto[(fila->first + fila->tam) % MAX];
    fila->produto[(fila->first + fila->tam) % MAX] = NULL;
    fila->tam--;
    fila->first = (fila->first + 1) % MAX;
    return retirado;
}

void printFila(Fila* fila){
    for(int i = 0; i < fila->tam; i++){
        imprimeProduto(fila->produto[(fila->first + i) % MAX]);
        printf("\n");
    }
}
