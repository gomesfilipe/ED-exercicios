#ifndef ALUNO_H_
#define ALUNO_H_

typedef struct aluno Aluno;

/**
 * Retorna o ponteiro para o nome de um aluno.
 * @param aluno Aluno cujo nome será pego.
 * @return Ponteiro para o nome do aluno.
 **/
char* getNomeAluno(Aluno* aluno);

/**
 * Retorna a matrícula de um aluno.
 * @param aluno Aluno cuja matrícula será pega.
 * @return Matrícula do aluno.
 **/
int getMatricula(Aluno* aluno);

/**
 * Retorna o CR de um aluno.
 * @param aluno Aluno cujo CR será pego.
 * @return CR do aluno.
 **/
float getCR(Aluno* aluno);

/**
 * Imprime os dados de um aluno.
 * @param aluno Aluno que terá seus dados impressos na tela.
 **/
void imprimeAluno(Aluno* aluno);

/**
 * Aloca espaço na memória para um aluno e o inicializa.
 * @param nome Nome do aluno.
 * @param matricula Matrícula do aluno.
 * @param cr CR do aluno.
 **/
Aluno* criaAluno(char* nome, int matricula, float cr);

/**
 * Libera um aluno da memória.
 * @param aluno Aluno que será desalocado da memória.
 **/
void destroiAluno(Aluno* aluno);

#endif
