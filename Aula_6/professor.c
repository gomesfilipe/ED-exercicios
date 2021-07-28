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

void imprimeProfessor(Professor *professor){
    printf("Nome: %s\n", professor->nome);
    printf("Siap: %d\n", professor->siape);
    printf("Salario: %.2f\n", professor->salario);
}

Professor* criaProfessor(char* nome, int siape, float salario){
    Professor* professor = (Professor*) malloc(sizeof(Professor));
    professor->nome = strdup(nome);
    professor->siape = siape;
    professor->salario = salario;
    return professor;
}

void destroiProfessor(Professor* professor){
    free(professor->nome);
    free(professor);
}
