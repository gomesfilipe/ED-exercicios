#ifndef PROFESSOR_H_
#define PROFESSOR_H_

typedef struct professor Professor;

/**
 * Retorna o siape de um professor.
 * @param professor Professor cujo nome será pego.
 * @return Siape do professor.
 **/
int getSiape(Professor *professor);

/**
 * Retorna o ponteiro para o nome de um professor.
 * @param professor professor cujo nome será pego.
 * @return Ponteiro para o nome do professor.
 **/
char* getNomeProfessor(Professor *professor);


/**
 * Retorna o salário de um professor.
 * @param professor professor cujo salário será pego.
 * @return Salário do professor.
 **/
float getSalario(Professor *professor);

#endif