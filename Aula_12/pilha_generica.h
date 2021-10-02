#ifndef PILHA_GENERICA_H
#define PILHA_GENERICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct pilha_gen Pilha_gen;

typedef int (*fptr) (void*, void*);

/**
 * @brief Cria uma pilha genérica vazia.
 * @return Pilha genérica vazia (NULL).
 **/
Pilha_gen* cria_pilha_gen();

/**
 * @brief Libera uma pilha genérica da memória.
 * @param pilha Pilha que será liberada da memória.
 **/
void destroi_pilha_gen(Pilha_gen* pilha);

/**
 * @brief Insere um item genérico na primeira posição de uma pilha genérica.
 * @param pilha Pilha genérica que terá um item inserido.
 * @param item Item genérico que será inserido.
 * @return Ponteiro para pilha genérica atualizado.
 **/
Pilha_gen* push_gen(Pilha_gen* pilha, void* item);

/**
 * @brief Remove o primeiro item de uma pilha genérica.
 * @param pilha Pilha genérica que terá um item removido.
 * @return Ponteiro para pilha genérica atualizado.
 **/
Pilha_gen* pop_gen(Pilha_gen* pilha);

/**
 * @brief Percorre uma pilha genérica.
 * @param pilha Pilha genérica que será percorrida.
 * @param cb Função booleana de callback, que servirá de condição de parada do caminhamento na pilha.
 * @param dado Algum dado genérico que pode auxiliar o callback ou não.
 * @return 1, caso a pilha tenha sido totalmente percorrida, e diferente de 1 caso ocorra alguma interrupção.
 **/
int percorre_pilha_gen(Pilha_gen* pilha, fptr cb, void* dado);

#endif
