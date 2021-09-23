#ifndef HASH_H_
#define HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

typedef struct hash Hash;

/**
 * @brief Cria uma tabela hash de determinado tamanho.
 * @param tam Tamanho da tabela hask criada.
 * @return Tabela hash inicializada.
 **/
Hash* cria_hash(int tam);

/**
 * @brief Busca uma determinada string na tabela hash. Se ela não estiver na hash,
 * a função a insere.
 * @param hash Tabela hash.
 * @param string Chave de busca.
 * @return Ponteiro para palavra encontrada ou inserida.
 **/
Palavra* acessa(Hash* hash, char* string);

/**
 * @brief Contabiliza quantas palavras há na tabela hash.
 * @param hash Tabela hash que será contabilizada.
 * @return Quantidade de palavras distintas na tabela hash.
 **/
int conta_palavras(Hash* hash);

/**
 * @brief Imprime uma tabela hash.
 * @param hash Tabela hash que será impressa.
 **/
void imprime_hash(Hash* hash);

/**
 * @brief Libera uma tabela hash da memória.
 * @param hash Tabela hash que será liberada.
 **/
void libera_hash(Hash* hash);

/**
 * @brief Aplica a função de hash numa determinada string.
 * @param string String que será aplicada na função de hash.
 * @param tam Tamanho da tabela hash (é usada no cálculo do índice do vetor).
 * @return índice da tabela hash para essa determinada string.
 **/
int funcao_hash(char* string, int tam);

#endif
