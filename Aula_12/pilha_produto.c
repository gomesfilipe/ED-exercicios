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

static int imprime_produto(void* produto, void* dado){ // Adaptado para callback.
    imprimeProduto(produto);
    return 1; // Continuar no loop.
}

static int compara_nomes(void* produto, void* dado){
    char* nomeProduto = getNome(produto);
    return strcmp(nomeProduto, dado); // Iguais retorna 1, diferentes retorna 0.
}

void imprime_pilha(Pilha* pilha){
    percorre_pilha_gen(pilha, imprime_produto, NULL);
}

int pertence_pilha(Pilha* pilha, char* chave){
    return !percorre_pilha_gen(pilha, compara_nomes, chave);
}

float custo_total(Pilha* pilha){

}

float venda_total(Pilha* pilha){

}

float media_precos(Pilha* pilha){

}

float media_custos(Pilha* pilha){

}

float desvio_padrao_precos(Pilha* pilha){

}

float desvio_padrao_custos(Pilha* pilha){

}
