#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "arvore.h"

int main(){
    Aluno* a = criaAluno('A', 1, 1.0);
    Aluno* b = criaAluno('B', 2, 2.0);
    Aluno* c = criaAluno('C', 3, 3.0);
    Aluno* d = criaAluno('D', 4, 4.0);
    Aluno* e = criaAluno('E', 5, 5.0);
    Aluno* f = criaAluno('F', 6, 6.0);
    Aluno* g = criaAluno('G', 7, 7.0);
    Aluno* h = criaAluno('H', 8, 8.0);
    Aluno* i = criaAluno('I', 9, 9.0);
    Aluno* j = criaAluno('j', 10, 10.0);

    Arvore* arvore;

    destroiAluno(a);
    destroiAluno(b);
    destroiAluno(c);
    destroiAluno(d);
    destroiAluno(e);
    destroiAluno(f);
    destroiAluno(g);
    destroiAluno(h);
    destroiAluno(i);
    destroiAluno(j);

    return 0;
}
