#ifndef LISTAHET_H_
#define LISTAHET_H_

typedef struct celula Celula;
typedef struct lista Lista;

/**
 * Cria uma lista heterogênea vazia.
 * @return Lista heterogênea vazia.
 **/
Lista* criaLista();

/**
 * Libera uma lista heterogênea da memória.
 * @param lista Lista heterogênea.
 **/
void destroiLista(Lista* lista);

/**
 * Insere um aluno no final da lista heterogênea.
 * @param lista Lista heterogênea.
 * @param aluno Aluno que será inserido.
 **/
void insereAluno(Lista* lista, Aluno* aluno);

/**
 * Remove um aluno da lista heterogênea.
 * @param lista Lista heterogênea.
 * @param chave Chave para remover o elemento desejado. Neste caso é o nome do aluno.
 **/
void removeAluno(Lista* lista, char* chave);

/**
 * Insere um professor no final da lista heterogênea.
 * @param lista Lista heterogênea.
 * @param professor Professor que será inserido.
 **/
void insereProfessor(Lista* lista, Professor* professor);

/**
 * Remove um professor da lista heterogênea.
 * @param lista Lista heterogênea.
 * @param chave Chave para remover o elemento desejado. Neste caso é o nome do professor.
 **/
void removeProfessor(Lista* lista, char* chave);

/**
 * Imprime uma lista heterogênea.
 * @param lista Lista heterogênea.
 **/
void imprimeLista(Lista* lista);

#endif
