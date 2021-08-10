#ifndef PRODUTO_H_
#define PRODUTI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto Produto;

/**
 * @brief Retorna o ponteiro para o nome de um produto.
 * @param produto Produto.
 * @return Ponteiro para nome do produto.
 **/
char* getNome(Produto* produto);

/**
 * @brief Retorna o custo de um produto.
 * @param produto Produto.
 * @return Custo do produto.
 **/
float getCusto(Produto* produto);

/**
 * @brief Retorna o preço de um produto.
 * @param produto Produto.
 * @return Preço do produto.
 **/
float getPreco(Produto* produto);

/**
 * @brief Retorna o estoque de um produto.
 * @param produto Produto.
 * @return Estoque do produto.
 **/
int getEstoque(Produto* produto);

/**
 * @brief Atualiza o campo nome de um produto.
 * @param produto Produto.
 * @param nome Novo nome do produto.
 * @return Produto com nome atualizado.
 **/
Produto* setNome(Produto* produto, char* nome);

/**
 * @brief Atualiza o campo custo de um produto.
 * @param produto Produto.
 * @param custo Novo custo do produto.
 * @return Produto com custo atualizado.
 **/
Produto* setCusto(Produto* produto, float custo);

/**
 * @brief Atualiza o campo preço de um produto.
 * @param produto Produto.
 * @param preco Novo preço do produto.
 * @return Produto com preço atualizado.
 **/
Produto* setPreco(Produto* produto, float preco);

/**
 * @brief Atualiza o campo estoque de um produto.
 * @param produto Produto.
 * @param estoque Novo estoque do produto.
 * @return Produto com estoque atualizado.
 **/
Produto* setEstoque(Produto* produto, int estoque);

/**
 * @brief Aloca memória para um produto e o inicializa.
 * @param nome Nome do produto.
 * @param custo Custo do produto.
 * @param preco Preço do produto.
 * @param estoque Estoque do produto.
 * @return Ponteiro para produto inicializado.
 **/
Produto* criaProduto(char* nome, float custo, float preco, float estoque);

/**
 * @brief Libera um tipo produto da memória.
 * @param produto Produto que será liberado.
 **/
void destroiProduto(Produto* produto);

/**
 * @brief Imprime um tipo produto.
 * @param produto Produto que será impresso.
 **/
void imprimeProduto(Produto* produto);

#endif
