#ifndef PRODUTO_LIST_H
#define PRODUTO_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "pilha_generica.h"
#include <math.h>

typedef struct pilha Pilha;

/**
 * @brief Cria uma pilha vazia.
 * @return Pilha vazia (NULL).
 **/
Pilha* cria_pilha();

/**
 * @brief Libera uma pilha da memória.
 * @param pilha Pilha que será liberada da memória.
 **/
void destroi_pilha(Pilha* pilha);

/**
 * @brief Insere um produto na primeira posição de uma pilha.
 * @param pilha Pilha que terá um item inserido.
 * @param produto Produto que será inserido.
 * @return Ponteiro para pilha atualizado.
 **/
Pilha* push(Pilha_gen* pilha, Produto* produto);

/**
 * @brief Remove o primeiro produto de uma pilha.
 * @param pilha Pilha que terá um produto removido.
 * @return Ponteiro para pilha atualizado.
 **/
Pilha* pop(Pilha_gen* pilha);

/**
 * @brief Imprime os pridutos de uma pilha no terminal.
 * @param pilha Pilha que terá seus produtos impressos.
 **/
void imprime_pilha(Pilha* pilha);

/**
 * @brief Função booleana que identifica se um produto pertence a pilha ou não.
 * @param pilha Pilha que será percorrida.
 * @param chave Nome do produto.
 * @return 1, Caso pertença e 0, caso não pertença.
 **/
int pertence_pilha(Pilha* pilha, char* chave);

/**
 * @brief Verifica o total do custo de todos os produtos de uma pilha.
 * @param pilha Pilha que terá seu custo calculado.
 * @return Valor do custo.
 **/
float custo_total(Pilha* pilha);

/**
 * @brief Verifica o valor total da venda todos os produtos de uma pilha.
 * @param pilha Pilha que terá seu patrimônio calculado.
 * @return Valor de todas as vendas.
 **/
float venda_total(Pilha* pilha);

/**
 * @brief Calcula o total de produtos distintos que uma pilha possui.
 * @param pilha Pilha que terá sua variedade de produtos calculada.
 * @return Total de produtos distintos.
 **/
int quantidade_produtos_distintos(Pilha* pilha);

/**
 * @brief Calcula o estoque total de uma pilha.
 * @param pilha Pilha que terá seu estoque calculado.
 * @return Total do estoque.
 **/
int estoque_total(Pilha* pilha);

/**
 * @brief Calcula a média de preços dos produtos de uma pilha.
 * @param pilha Pilha que terá sua média de preços calculada.
 * @return Média dos preços dos produtos.
 **/
float media_precos(Pilha* pilha);

/**
 * @brief Calcula a média de custos dos produtos de uma pilha.
 * @param pilha Pilha que terá sua média de custos calculada.
 * @return Média dos custos dos produtos.
 **/
float media_custos(Pilha* pilha);

/**
 * @brief Calcula a variância de custos dos produtos de uma pilha.
 * @param pilha Pilha que terá sua variância de custos calculada.
 * @return Variância dos custos dos produtos.
 **/
float variancia_custos(Pilha* pilha);

/**
 * @brief Calcula a variância de precos dos produtos de uma pilha.
 * @param pilha Pilha que terá sua variância de precos calculada.
 * @return Variância dos precos dos produtos.
 **/
float variancia_precos(Pilha* pilha);

/**
 * @brief Calcula o desvio padrão dos preços dos produtos de uma pilha.
 * @param pilha Pilha que terá sua desvio padrão dos preços calculada.
 * @return Desvio padrão dos preços dos produtos.
 **/
float desvio_padrao_precos(Pilha* pilha);

/**
 * @brief Calcula o desvio padrão dos custos dos produtos de uma pilha.
 * @param pilha Pilha que terá sua desvio padrão dos custos calculada.
 * @return Desvio padrão dos custos dos produtos.
 **/
float desvio_padrao_custos(Pilha* pilha);

/**
 * @brief Calcula o total do estoque de uma pilha.
 * @param pilha Pilha que será percorrida.
 * @return Quantidade de estoque total.
 **/
int qtd_estoque(Pilha* pilha);

/**
 * @brief Calcula a quantidade de produtos distintos de uma pilha.
 * @param pilha Pilha que será percorrida.
 * @return Quantidade de produtos distintos.
 **/
int qtd_produtos_distintos(Pilha* pilha);

#endif
