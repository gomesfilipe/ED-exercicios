#ifndef PILHA_DUPLA_H_
#define PILHA_DUPLA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

typedef struct indicePilha IndicePilha;
typedef struct pilhaDupla PilhaDupla;

/**
 * @brief Cria uma pilha dupla vazia.
 * @return Pilha dupla vazia.
 **/
PilhaDupla* criaPilhaDupla();

/**
 * @brief Libera uma pilha dupla da memória. C essa pilha está implementada com um vetor
 * estático, essa função libera o conteúdo de cada posição.
 * @param pilhaDupla Pilha que será liberada da memória.
 **/
void destroiPilhaDupla(PilhaDupla* pilhaDupla);

/**
 * @brief Insere um elemento no topo de uma das pilhas.
 * @param
 * @param
 **/
void push();

/**
 * @brief Remove um elemento no topo de uma das pilhas.
 * @param
 * @param
 * @param
 **/
void pop();

#endif
