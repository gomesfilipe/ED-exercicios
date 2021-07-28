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
