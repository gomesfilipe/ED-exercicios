#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct professor{
    int siape;
    char* nome;
    float salario;
};

int getSiape(Professor *professor){
    return professor->siape;
}

char* getNomeProfessor(Professor *professor){
    return professor->nome;
}

float getSalario(Professor *professor){
    return professor->salario;
}