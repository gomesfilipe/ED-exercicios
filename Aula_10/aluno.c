#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char* nome;
    int matricula;
    float cr;
};

char* getNomeAluno(Aluno* aluno){
    return aluno->nome;
}

int getMatricula(Aluno* aluno){
    return aluno->matricula;
}

float getCR(Aluno* aluno){
    return aluno->cr;
}

void imprimeAluno(Aluno* aluno){
    printf("[Nome: %s, ", aluno->nome);
    printf("Matricula: %d, ", aluno->matricula);
    printf("CR: %.2f]", aluno->cr);
    printf("\n");
}

Aluno* criaAluno(char* nome, int matricula, float cr){
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->nome = strdup(nome);
    aluno->matricula = matricula;
    aluno->cr = cr;
    return aluno;
}

void destroiAluno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}
