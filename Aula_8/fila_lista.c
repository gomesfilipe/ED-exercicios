#include "fila.h"

struct celula{
    Produto* produto;
    Celula* next;
};

struct fila{
    Celula* first;
    Celula* last;
};

Fila* criaFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->first = NULL;
    fila->last = NULL;
    return fila;
}

void destroiFila(Fila* fila){
    Celula* i = fila->first;
    Celula* aux;
    while(i != NULL){
        aux = i;
        i = i->next;
        free(aux);
    }
    free(fila);
}

void insere(Fila* fila, Produto* produto){
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->produto = produto;
    nova->next = NULL;

    if(fila->first == NULL){
        fila->first = nova;
    } else{
        fila->last->next = nova;
    }
    
    fila->last = nova;
}

Produto* retira(Fila* fila){
    if(fila->first == NULL && fila->last == NULL){
        return NULL;
    }
    
    Celula* aux = fila->first;
    fila->first = fila->first->next;
    
    if(fila->first == fila->last){
        fila->last = NULL;
    }

    Produto* removido = aux->produto;
    free(aux);
    return removido;
}

void printFila(Fila* fila){
    Celula* i = fila->first;
    while(i != NULL){
        imprimeProduto(i->produto);
        printf("\n");
        i = i->next;
    }
}
