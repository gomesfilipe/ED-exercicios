#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "arvore.h"

// Criei duas árvores para testar o TAD árvore.
// Está sob responsabilidade do programador liberar os alunos ao final do programa.
// A função de liberar apenas desfaz o encadeamento da árvore.

int main(){
    Aluno* a = criaAluno("A", 1, 1.0);
    Aluno* b = criaAluno("B", 2, 2.0);
    Aluno* c = criaAluno("C", 3, 3.0);
    Aluno* d = criaAluno("D", 4, 4.0);
    Aluno* e = criaAluno("E", 5, 5.0);
    Aluno* f = criaAluno("F", 6, 6.0);
    Aluno* g = criaAluno("G", 7, 7.0);
    Aluno* h = criaAluno("H", 8, 8.0);
    Aluno* i = criaAluno("I", 9, 9.0);
    Aluno* j = criaAluno("J", 10, 10.0);

    // Criando árvore de modo aninhado.
    Arvore* arvore1 = criaArvore(a, 
                        criaArvore(b,
                            criaArvoreVazia(), 
                            criaArvore(d, 
                                criaArvore(i, 
                                    criaArvoreVazia(),
                                    criaArvoreVazia()),
                                criaArvore(j, 
                                    criaArvoreVazia(), 
                                    criaArvoreVazia()))), 
                        criaArvore(c,
                            criaArvore(g, 
                                criaArvoreVazia(), 
                                criaArvoreVazia()), 
                            criaArvore(f, 
                                criaArvore(h, 
                                    criaArvoreVazia(), 
                                    criaArvoreVazia()), 
                                criaArvoreVazia())));

    printf("Arvore 1\n");
    imprimeArvore(arvore1);
    printf("\n[%d] folhas\n", folhas(arvore1));
    printf("[%d] ocorrencias de A\n", ocorrencias(arvore1, "A"));
    printf("[%d] altura\n", altura(arvore1));
    printf("A pertence? [%d]\n", pertence(arvore1, "A"));

    // Criando árvore 2 com declaração de várias subárvores.
    Arvore* J = criaArvore(j, criaArvoreVazia(), criaArvoreVazia());
    Arvore* F = criaArvore(f, criaArvoreVazia(), J);
    Arvore* E = criaArvore(e, F, criaArvoreVazia());
    Arvore* D = criaArvore(d, E, criaArvoreVazia());
    Arvore* C = criaArvore(c, criaArvoreVazia(), D);
    Arvore* B = criaArvore(b, criaArvoreVazia(), C);
    
    Arvore* H = criaArvore(h, criaArvoreVazia(), criaArvoreVazia());
    Arvore* I = criaArvore(i, criaArvoreVazia(), criaArvoreVazia());
    Arvore* G = criaArvore(g, H, I);
    Arvore* A = criaArvore(a, B, G);

    printf("\nArvore 2\n");
    imprimeArvore(A);
    printf("\n[%d] folhas\n", folhas(A));
    printf("[%d] ocorrencias de J\n", ocorrencias(A, "J"));
    printf("[%d] altura\n", altura(A));
    printf("Z pertence? [%d]\n", pertence(arvore1, "Z"));

    arvore1 = destroiArvore(arvore1);
    A = destroiArvore(A);

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
