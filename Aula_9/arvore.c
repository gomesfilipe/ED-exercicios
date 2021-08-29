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

void destroiArvore(Arvore* arvore){

}

int folhas(Arvore* arvore){

}

int ocorrencias(Arvore* arvore, char* chave){

}

int altura(Arvore* arvore){

}
