#include "pilha_produto.h"

struct pilha{
    Produto* p;
    Pilha* next;
};

Pilha* cria_pilha(){
    return cria_pilha_gen();
}

void destroi_pilha(Pilha* pilha){
    destroi_pilha_gen(pilha); // O casting ocorre automaticamente.
}

Pilha* push(Pilha_gen* pilha, Produto* produto){
    return push_gen(pilha, produto); // O casting ocorre automaticamente.
}

Pilha* pop(Pilha_gen* pilha){
    return pop_gen(pilha); // O casting ocorre automaticamente.
}

void imprime_pilha(Pilha* pilha){

}

int pertence_pilha(Pilha* pilha, char* chave){

}

Produto* busca_pilha(Pilha* pilha, char* chave){

}

float media_precos(Pilha* pilha){

}

float media_custos(Pilha* pilha){

}

float custo_total(Pilha* pilha){

}

float venda_total(Pilha* pilha){

}

float desvio_padrao_precos(Pilha* pilha){

}

float desvio_padrao_custos(Pilha* pilha){

}
