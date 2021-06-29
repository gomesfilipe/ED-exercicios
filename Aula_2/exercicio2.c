#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char *nome;
    int matricula;
    float p1;
    float p2;
    float p3;
};

typedef struct aluno tAluno;

tAluno* criaAluno(char* nome, int matricula, float p1, float p2, float p3);
tAluno** criaTurmaVazia(int qtdAlunos);
void imprimeAluno(tAluno* aluno);
void imprimeTurma(tAluno** turma, int qtdAlunos);
void destroiAluno(tAluno* aluno);
void destroiTurma(tAluno** turma, int qtdAlunos);
tAluno* leAluno();
tAluno** leTurma(int qtdAlunos);
float mediaAluno(tAluno* aluno);
void imprime_aprovados(int n, tAluno** turma);
float media_turma(int n, tAluno** turma);
void imprimeMediaTurma(int n, tAluno** turma);
void exercicio2();

int main(){
    exercicio2();
    return 0;
}

tAluno* criaAluno(char* nome, int matricula, float p1, float p2, float p3){
    tAluno* aluno = (tAluno*) malloc(sizeof(tAluno));
    aluno->nome = strdup(nome);
    aluno->matricula = matricula;
    aluno->p1 = p1;
    aluno->p2 = p2;
    aluno->p3 = p3;
    return aluno;
}

tAluno** criaTurmaVazia(int qtdAlunos){
    tAluno** turma = (tAluno**) malloc(sizeof(tAluno*) * qtdAlunos);
    return turma;
}

void imprimeAluno(tAluno* aluno){
    printf("Nome: %s | ", aluno->nome);
    printf("Matricula: %d | ", aluno->matricula);
    printf("Nota 1: %.2f | ", aluno->p1);
    printf("Nota 2: %.2f | ", aluno->p2);
    printf("Nota 3: %.2f\n", aluno->p3);
}

void imprimeTurma(tAluno** turma, int qtdAlunos){
    for(int i = 0; i < qtdAlunos; i++){
        imprimeAluno(turma[i]);
    }

    printf("\n");
}

void destroiAluno(tAluno* aluno){
    free(aluno->nome);
    free(aluno);
}

void destroiTurma(tAluno** turma, int qtdAlunos){
    for(int i = 0; i < qtdAlunos; i++){
        destroiAluno(turma[i]);
    }

    free(turma);
}

tAluno* leAluno(){
    tAluno* aluno;
    char nome[100];
    int matricula;
    float p1;
    float p2;
    float p3;

    printf("Nome: ");
    scanf("%s", nome);
    
    printf("Matricula: ");
    scanf("%d", &matricula);
    
    printf("Nota 1: ");
    scanf("%f", &p1);
    
    printf("Nota 2: ");
    scanf("%f", &p2);
    
    printf("Nota 3: ");
    scanf("%f", &p3);

    printf("\n");
    aluno = criaAluno(nome, matricula, p1, p2, p3);
    return aluno;
}

tAluno** leTurma(int qtdAlunos){
    tAluno** turma = criaTurmaVazia(qtdAlunos);

    for(int i = 0; i < qtdAlunos; i++){
        printf("Insira os dados do aluno %d\n", i + 1);
        turma[i] = leAluno();
    }

    return turma;
}

float mediaAluno(tAluno* aluno){
    return (aluno->p1 + aluno->p2 + aluno->p3) / 3.0;
}

void imprime_aprovados(int n, tAluno** turma){
    printf("Alunos aprovados:\n\n");
    for(int i = 0; i < n; i++){
        if(mediaAluno(turma[i]) >= 5.0){
            printf("%s\n", turma[i]->nome);
        }
    }

    printf("\n");
}

float media_turma(int n, tAluno** turma){
    float media = 0.0;

    for(int i = 0; i < n; i++){
        media += mediaAluno(turma[i]);
    }

    return media / n;
}

void imprimeMediaTurma(int n, tAluno** turma){
    printf("Media da turma: %.2f\n\n", media_turma(n, turma));
}

void exercicio2(){
    int qtdAlunos;
    printf("Quantos alunos ha na turma? ");
    scanf("%d", &qtdAlunos);
    printf("\n");

    tAluno** turma = leTurma(qtdAlunos);
    imprimeTurma(turma, qtdAlunos);
    imprime_aprovados(qtdAlunos, turma);
    imprimeMediaTurma(qtdAlunos, turma);
    destroiTurma(turma, qtdAlunos);
}