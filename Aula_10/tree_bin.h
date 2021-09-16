#ifndef TREE_BIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct tree Tree;

/**
 * @brief Cria uma árvore binária de busca vazia.
 * @return Árvore de busca vazia.
 **/
Tree* cria_vazia_bin();

/**
 * @brief Cria um nó raíz de uma árvore com um aluno.
 * @param aluno Aluno que estará no nó raiz da árvore.
 * @return Árvore inicializada.
 **/
Tree* cria_tree_bin(Aluno* aluno);

/**
 * @brief Libera uma árvore binária de busca da memória.
 * @param tree Árvore que será liberada da memória.
 **/
void libera_tree_bin(Tree* tree);

/**
 * @brief Imprime uma árvore binária de busca.
 * @param tree Árvore que será impressa.s
 **/
void imprime_tree_bin(Tree* tree);

/**
 * @brief Insere um elemento numa árvore binária de busca.
 * @param tree Árvore que terá um elemento inserido.
 * @param aluno Elemento que será inserido na árvore.
 * @return O retorno dessa função serve para encadear o novo nó com a árvore.
 **/
Tree* insere_tree_bin(Tree* tree, Aluno* aluno);

/**
 * @brief Remove um elemento de uma árvore de busca binária.
 * @param tree Árvore que terá um elemento removido.
 * @param chave Chave de busca. Nesse caso, é o CR do aluno.
 * @return Ponteiro para nó raiz da árvore.
 **/
Tree* remove_tree_bin(Tree* tree, float chave);

/**
 * @brief Busca um determinado elemento numa árvore binária de busca.
 * @param tree Árvore que terá um elemento procurado.
 * @param chave Chave de busca. Nesse caso, é o CR do aluno.
 * @return Ponteiro para o conteúdo do nó que estava o aluno procurado.
 * Se não estiver na lista, retorna NULL.
 **/
Tree* busca_tree_bin(Tree* tree, float chave);

/**
 * @brief Imprime somente o conteúdo do nó raiz de uma árvore binária de busca.
 * Função para auxíliar a testar o TAD de árvore binária de busca.
 * @param tree Árvore que terá seu nó raíz impresso.
 **/
void imprime_somente_raiz(Tree* tree);

#endif
