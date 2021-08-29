#include "arvore.h"

struct arvore{
    Aluno* aluno;
    Arvore* left;
    Arvore* right;
};

Arvore* criaArvoreVazia(){
    return NULL;
}

Arvore* criaArvore(Aluno* aluno, Arvore* left, Arvore* right){
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));
    arvore->aluno = aluno;
    arvore->left = left;
    arvore->right = right;
    return arvore;
}

Arvore* destroiArvore(Arvore* arvore){
    if(!ehArvoreVazia(arvore)){ // Condição de parada.
        destroiArvore(arvore->left);
        destroiArvore(arvore->right);
        free(arvore);
    }
    return NULL;
}

int folhas(Arvore* arvore){
    if(!ehArvoreVazia(arvore)){
        if(ehFolha(arvore)){
            return 1;
        } else{
            return folhas(arvore->left) + folhas(arvore->right);
        }
    }
    return 0;
}

int ocorrencias(Arvore* arvore, char* chave){
    if(ehArvoreVazia(arvore)){
        return 0;
    }
    
    char* nome = getNomeAluno(arvore->aluno);
    
    return (strcmp(nome, chave) == 0) + (ocorrencias(arvore->left, chave)) + (ocorrencias(arvore->right, chave));
}

int altura(Arvore* arvore){
    int hLeft = 0, hRight = 0;
    if(ehArvoreVazia(arvore)){
        return -1; // Uma árvore vazia deve ter tamanho -1. Tamanho 0 é para árvores cujo nó raiz não tem filhos.
    } else{
        
        hLeft = altura(arvore->left);
        hRight = altura(arvore->right);
        if(hLeft > hRight){
            return hLeft + 1;
        } else{
            return hRight + 1;
        }
    }
}

int ehArvoreVazia(Arvore* arvore){
    return arvore == NULL;
}

int ehFolha(Arvore* arvore){
    if(!ehArvoreVazia(arvore)){
        return ehArvoreVazia(arvore->left) && ehArvoreVazia(arvore->right);
    }

    return 0;
}

int pertence(Arvore* arvore, char* chave){
    if(ehArvoreVazia(arvore)){
        return 0;
    }
    
    char* nome = getNomeAluno(arvore->aluno);

    return (strcmp(nome, chave)) == 0 || pertence(arvore->left, chave) || pertence(arvore->right, chave);
}

void imprimeArvore(Arvore* arvore){
    char* nome;
    printf("<");
    if(!ehArvoreVazia(arvore)){
        nome = getNomeAluno(arvore->aluno);
        printf("%s", nome);
        imprimeArvore(arvore->left);
        imprimeArvore(arvore->right);
    }
    printf(">");
}