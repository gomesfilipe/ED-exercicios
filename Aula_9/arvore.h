#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct arvore Arvore;

/**
 * @brief Cria uma árvore vazia.
 * @return Árvore vazia.
 **/
Arvore* criaArvoreVazia();

/**
 * @brief Cria uma ávore com seu conteúdo e filhos inicializados.
 * @param aluno Aluno que estará no nó raiz da árvore criada.
 * @param left Ponteiro para subárvore esquerda.
 * @param right Ponteiro para subárvore direita.
 * @return Árvore criada e inicializada.
 **/
Arvore* criaArvore(Aluno* aluno, Arvore* left, Arvore* right);

/**
 * @brief Libera uma árvore da memória. Essa função apenas desfaz o encadeamento da árvore.
 * @param arvore Árvore que será liberada.
 * @return Ponteiro NULL para a árvore que será liberada.
 **/
Arvore* destroiArvore(Arvore* arvore);

/**
 * @brief Conta a quantidade de folhas de uma árvore.
 * @param arvore Árvore que terá suas folhas contabilizadas.
 * @return Quantidade de folhas da árvore.
 **/
int folhas(Arvore* arvore);

/**
 * @brief Conta a quantidade de um determinado elemento numa árvore.
 * @param arvore Árvore que terá a quantidade de um determinado elemento contabilizada.
 * @param chave Chave de busca. Nesse caso, é o nome do aluno.
 * @return Quantidade de vezes que um determinado aluno aparece na árvore.
 **/
int ocorrencias(Arvore* arvore, char* chave);

/**
 * @brief Calcula a altura de uma árvore.
 * @param arvore Árvore que terá a sua altura calculada.
 * @return Altura da árvore.
 **/
int altura(Arvore* arvore);

/**
 * @brief Função booleana, que diz se uma árvore é vazia ou não.
 * @param arvore Árvore que será verificada.
 * @return 1, caso seja vazia e 0, caso não seja vazia.
 **/
int ehArvoreVazia(Arvore* arvore);

/**
 * @brief Função booleana, que diz se uma árvore é folha ou não.
 * @param arvore Árvore que será verificada.
 * @return 1, caso seja folha e 0, caso não seja folha.
 **/
int ehFolha(Arvore* arvore);

/**
 * @brief Função booleana, que diz se um elemento pertence ou não a árvore.
 * @param arvore Árvore que será verificada.
 * @param chave Chave de busca do elemento, que neste caso é o nome do aluno.
 * @return 1, caso o elemento pertença e 0, caso contrário.
 **/
int pertence(Arvore* arvore, char* chave);

/**
 * @brief Imprime os dados de uma árvore.
 * @param arvore Árvore que será impressa.
 **/
void imprimeArvore(Arvore* arvore);

#endif
