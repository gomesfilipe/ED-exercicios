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

#endif