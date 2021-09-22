#ifndef PALAVRA_H_
#define PALAVRA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra Palavra;

/**
 * @brief Aloca espaço na memória para uma palavra e a inicializa.
 * @param string String que representa a palavra.
 * @return Ponteiro para palavra inicializada.
 **/
Palavra* cria_palavra(char* string);

/**
 * @brief Retorna o ponteiro para o campo string de uma palavra.
 * @param palavra Palavra que terá seu campo string retornado.
 * @return Ponteiro para o campo string de uma palavra.
 **/
char* get_string(Palavra* palavra);

/**
 * @brief Retorna o campo ocorrencias de uma palavra.
 * @param palavra Palavra que terá seu campo ocorrencias retornado.
 * @return Valor do campo ocorrencias de uma palavra.
 **/
int get_ocorrencias(Palavra* palavra);

/**
 * @brief Incrementa em 1 o campo ocorrencias de uma palavra.
 * @param Palavra que terá seu campo ocorrencias incrementado.
 **/
void atualiza_ocorrencias(Palavra* palavra);

/**
 * @brief Busca uma palavra numa lista de colisões.
 * @param palavra Ponteiro para lista de colisões.
 * @param string Chave de busca.
 * @return Ponteiro para a palavra encontrada. Caso retorne NULL, não encontrou.
 **/
Palavra* busca_palavra(Palavra* palavra, char* string);

/**
 * @brief Insere uma palavra no início da lista de colisões.
 * @param lista Lista de colisões
 * @param inserida Palavra que será inserida.
 * @return Ponteiro para lista de colisões atualizado.
 **/
Palavra* insere_palavra_lista(Palavra* lista, Palavra* inserida);

/**
 * @brief Calcula a quantidade de palavras numa lista de colisões.
 * @param palavra Lista de colisões.
 * @return Valor da quantidade de palavras na lista de colisões.
 **/
int conta_palavras_lista(Palavra* palavra);

/**
 * @brief Imprime uma lista de palavras.
 * @param palavra Lista de palavras que será impressa.
 **/
void imprime_lista_palavra(Palavra* palavra);

/**
 * @brief Libera uma lista de palavras da memória.
 * @param palavra Lista de palavras que será liberada da memória.
 **/
void libera_lista_palavra(Palavra* palavra);

#endif
