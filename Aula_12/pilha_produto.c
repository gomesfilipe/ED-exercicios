#include "pilha_produto.h"
#include <math.h>

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
    return 1; // Continuar no loop, pois para imprimir deve percorrer tudo.
}

static int compara_nomes(void* produto, void* dado){ // Adaptado para callback.
    char* nomeProduto = getNome(produto);
    return strcmp(nomeProduto, dado); // Iguais retorna 1 (continuar loop), diferentes retorna 0 (parar loop).
}

static int acumula_precos(void* produto, void* dado){ // Adaptado para callback.
    float* soma = (float*) dado;
    *soma += getPreco(produto) * getEstoque(produto);
    return 1; // Continuar no loop.
}

static int acumula_custos(void* produto, void* dado){ // Adaptado para callback.
    float* soma = (float*) dado;
    *soma += getCusto(produto) * getEstoque(produto);
    return 1; // Continuar no loop.
}

static int acumula_estoque(void* produto, void* dado){ // Adaptado para callback.
    int* soma = (int*) dado;
    *soma += getEstoque(produto);
    return 1; // Continuar no loop.
}

static int acumula_produtos_distintos(void* produto, void* dado){ // Adaptado para callback.
    int* soma = (int*) dado;
    *soma += 1;
    return 1; // Continuar no loop.
}

static int acumula_quadrado_precos(void* produto, void* dado){ // Adaptado para callback.
    float* soma = (float*) dado; // estoque i * preço i * preço i
    *soma += getEstoque(produto) * getPreco(produto) * getPreco(produto);
    return 1; // Continuar no loop.
}

static int acumula_quadrado_custos(void* produto, void* dado){ // Adaptado para callback.
    float* soma = (float*) dado; // estoque i * custo i * custo i
    *soma += getEstoque(produto)* getCusto(produto) * getCusto(produto);
    return 1; // Continuar no loop.
}

void imprime_pilha(Pilha* pilha){
    percorre_pilha_gen(pilha, imprime_produto, NULL);
}

int pertence_pilha(Pilha* pilha, char* chave){
    // Se houve interrupção, a função percorre retorna 0. Então devemos negar o retorno
    // dessa função para indicar se ele está ou não. 
    return !percorre_pilha_gen(pilha, compara_nomes, chave);
}

float custo_total(Pilha* pilha){
    float soma = 0.0;
    percorre_pilha_gen(pilha, acumula_custos, &soma); // Soma teve que ser ponteiro para adaptar a função de callback.
    return soma;
}

float venda_total(Pilha* pilha){
    float soma = 0.0;
    percorre_pilha_gen(pilha, acumula_precos, &soma); // Soma teve que ser ponteiro para adaptar a função de callback.
    return soma;
}

int qtd_estoque(Pilha* pilha){
    int soma = 0;
    percorre_pilha_gen(pilha, acumula_estoque, &soma); // Soma teve que ser ponteiro para adaptar a função de callback.
    return soma;
}

int qtd_produtos_distintos(Pilha* pilha){
    int soma = 0;
    percorre_pilha_gen(pilha, acumula_produtos_distintos, &soma); // Soma teve que ser ponteiro para adaptar a função de callback.
    return soma;
}

float media_precos(Pilha* pilha){
    return venda_total(pilha) / qtd_estoque(pilha);
}

float media_custos(Pilha* pilha){
    return custo_total(pilha) / qtd_estoque(pilha);
}

float variancia_precos(Pilha* pilha){
    float quadrados = 0.0; // Somátório de estoque i * preço i * preço i de 1 até N (N é o estoque total).
    percorre_pilha_gen(pilha, acumula_quadrado_precos, &quadrados);

    float soma = venda_total(pilha);
    float media = media_precos(pilha);
    float estoque = qtd_estoque(pilha);
    // Expandindo o somatório do desvio padrão, temos a expressão abaixo: 
    float variancia = (quadrados -2.0*media*soma + estoque*media*media) / qtd_estoque(pilha);
    return variancia;
}

float variancia_custos(Pilha* pilha){
    float quadrados = 0.0; // Somátório de estoque i * custo i * custo i de 1 até N (N é o estoque total).
    percorre_pilha_gen(pilha, acumula_quadrado_custos, &quadrados);

    float soma = custo_total(pilha);
    float media = media_custos(pilha);
    float estoque = qtd_estoque(pilha);
    // Expandindo o somatório do desvio padrão, temos a expressão abaixo: 
    float variancia = (quadrados -2.0*media*soma + estoque*media*media) / qtd_estoque(pilha);
    return variancia;
}

float desvio_padrao_precos(Pilha* pilha){
    return sqrt(variancia_precos(pilha));
}

float desvio_padrao_custos(Pilha* pilha){
    return sqrt(variancia_custos(pilha));
}
