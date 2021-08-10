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
}

void push(){ // Insere.

}

void pop(){ // Remove.

}