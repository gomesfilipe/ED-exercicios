#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "professor.h"
#include "listahet.h"

// Neste exercício deixei sob responsabilidade do programador liberar os alunos e professores da memória.

int main(){
    Aluno* aluno1 = criaAluno("Filipe", 100, 10.0);
    Aluno* aluno2 = criaAluno("Jose", 200, 9.0);
    Aluno* aluno3 = criaAluno("Maria", 300, 8.0);
    Professor* professor1 = criaProfessor("Eugenio", 400, 10000.00);
    Professor* professor2 = criaProfessor("Marta", 500, 15000.00);
    Professor* professor3 = criaProfessor("Irineu", 600, 20000.00);

    Lista* lista = criaLista();
    insereAluno(lista, aluno1);
    insereProfessor(lista, professor1);
    insereAluno(lista, aluno2);
    insereProfessor(lista, professor2);
    insereAluno(lista, aluno3);
    insereProfessor(lista, professor3);

    printf("Lista apos inserir elementos:\n");
    imprimeLista(lista);

    removeAluno(lista, "filipe"); // Removendo primeiro.
    removeProfessor(lista, "irineu"); // Removendo último.
    removeAluno(lista, "Jose"); // Removendo aluno no meio da lista.
    removeProfessor(lista, "Eugenio"); // Removendo professor no meio da lista.

    printf("Lista apos remover elementos:\n");
    imprimeLista(lista);

    insereAluno(lista, aluno1);
    insereProfessor(lista, professor3);

    printf("Lista apos adicionar elementos novamente:\n");
    imprimeLista(lista);

    destroiAluno(aluno1);
    destroiAluno(aluno2);
    destroiAluno(aluno3);
    destroiProfessor(professor1);
    destroiProfessor(professor2);
    destroiProfessor(professor3);
    destroiLista(lista);
    return 0;
}