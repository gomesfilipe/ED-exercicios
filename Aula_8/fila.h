#ifndef FILA_H_
#define FILA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

typedef struct celula Celula;
typedef struct fila Fila;

/**
 * @brief Cria uma fila vazia.
 * @return Ponteiro para fila.
 **/
Fila* criaFila();

/**
 * @brief Libera uma fila da memória. Obs: Não libera os elementos inseridos nela.
 * @param fila Fila que será liberada.
 **/
void destroiFila(Fila* fila);

/**
 * @brief Insere o último elemento da fila.
 * @param fila Fila que terá um elemento inserido.
 * @param produto Elemento que será inserido.
 **/
void insere(Fila* fila, Produto* produto);

/**
 * @brief Remove o primeiro elemento da fila.
 * @param fila Fila que terá um elemento retirado.
 * @return Elemento da célula que foi removida da fila.
 **/
Produto* retira(Fila* fila);

/**
 * @brief Imprime todos os elementos de uma fila, do início para o final.
 * @param fila Fila que será impressa.
 **/
void printFila(Fila* fila);

#endif
