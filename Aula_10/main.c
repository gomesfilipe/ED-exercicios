#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "tree_bin.h"

int main(){
    Aluno* a1 = criaAluno("a1", 1, 1.0);
    Aluno* a2 = criaAluno("a2", 2, 2.0);
    Aluno* a3 = criaAluno("a3", 3, 3.0);
    Aluno* a4 = criaAluno("a4", 4, 4.0);
    Aluno* a5 = criaAluno("a5", 5, 5.0);
    Aluno* a6 = criaAluno("a6", 6, 6.0);
    Aluno* a7 = criaAluno("a7", 7, 7.0);
    Aluno* a8 = criaAluno("a8", 8, 8.0);
    Aluno* a9 = criaAluno("a9", 9, 9.0);
    Aluno* a10 = criaAluno("a10", 10, 4.5);
    
    Tree* tree = cria_vazia_bin();

    tree = insere_tree_bin(tree, a2);
    tree = insere_tree_bin(tree, a5);
    tree = insere_tree_bin(tree, a6);
    tree = insere_tree_bin(tree, a9);
    tree = insere_tree_bin(tree, a4);
    tree = insere_tree_bin(tree, a8);
    tree = insere_tree_bin(tree, a7);
    tree = insere_tree_bin(tree, a1);
    tree = insere_tree_bin(tree, a3);
    tree = insere_tree_bin(tree, a10);

    printf("Arvore:\n");
    imprime_tree_bin(tree);

    Tree* busca1 = busca_tree_bin(tree, 1.0);
    Tree* busca2 = busca_tree_bin(tree, 2.0);
    Tree* busca3 = busca_tree_bin(tree, 3.0);
    Tree* busca4 = busca_tree_bin(tree, 4.0);
    Tree* busca5 = busca_tree_bin(tree, 5.0);
    Tree* busca6 = busca_tree_bin(tree, 6.0);
    Tree* busca7 = busca_tree_bin(tree, 7.0);
    Tree* busca8 = busca_tree_bin(tree, 8.0);
    Tree* busca9 = busca_tree_bin(tree, 9.0);
    Tree* busca10 = busca_tree_bin(tree, 0.0); // Não há aluno com esse CR.

    printf("Buscas:\n");
    imprime_somente_raiz(busca1);
    imprime_somente_raiz(busca2);
    imprime_somente_raiz(busca3);
    imprime_somente_raiz(busca4);
    imprime_somente_raiz(busca5);
    imprime_somente_raiz(busca6);
    imprime_somente_raiz(busca7);
    imprime_somente_raiz(busca8);
    imprime_somente_raiz(busca9);
    imprime_somente_raiz(busca10);

    tree = remove_tree_bin(tree, 7.0); // Retirando folha.
    tree = remove_tree_bin(tree, 6.0); // Retirando nó com um único filho.
    tree = remove_tree_bin(tree, 5.0); // Retirando nó com dois filhos.
    tree = remove_tree_bin(tree, 0.0); // Retirando nó inexistente.
    

    printf("Removendo alunos da lista:\n");
    imprime_tree_bin(tree);

    libera_tree_bin(tree);
    destroiAluno(a1);
    destroiAluno(a2);
    destroiAluno(a3);
    destroiAluno(a4);
    destroiAluno(a5);
    destroiAluno(a6);
    destroiAluno(a7);
    destroiAluno(a8);
    destroiAluno(a9);
    destroiAluno(a10);
    return 0;
}
