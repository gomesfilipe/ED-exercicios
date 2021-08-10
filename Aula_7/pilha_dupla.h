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
 * @param pilhaDupla Pilha que terá algum elemento inserido.
 * @param produto Produto que será inserido na pilha.
 * @param numPilha Número da pilha que terá algum elemento inserido. Só são válidos os números 0 e 1. Caso diferente, ocorrerá erro.
 **/
void push(PilhaDupla* pilhaDupla, Produto* produto, int numPilha);

/**
 * @brief Remove um elemento no topo de uma das pilhas.
 * @param pilhaDupla Pilha que terá algum elemento retirado.
 * @param numPilha Número da pilha que terá seu elemento do topo retirado.
 **/
void pop(PilhaDupla* pilhaDupla, int numPilha);

/**
 * @brief Imprime uma pilha dupla. Primeiro a pilha 1 é impressa, do topo para sua base e depois a pilha 2 é impressa, do topo para sua base.
 * @param pilhaDupla Pilha que será impressa.
 **/
void printPilha(PilhaDupla* pilhaDupla);

#endif
