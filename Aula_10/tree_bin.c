#include "tree_bin.h"

struct tree{
    Aluno* aluno;
    Tree* left;
    Tree* right;
};

Tree* cria_vazia_bin(){
    return NULL;
}

Tree* cria_tree_bin(Aluno* aluno){
    Tree* tree = (Tree*) malloc(sizeof(Tree));
    tree->aluno = aluno;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void libera_tree_bin(Tree* tree){
    if(tree != NULL){
        libera_tree_bin(tree->left);
        libera_tree_bin(tree->right);
        free(tree);
    }
}

void imprime_tree_bin(Tree* tree){
    if(tree != NULL){
        imprime_tree_bin(tree->left);
        imprimeAluno(tree->aluno);
        imprime_tree_bin(tree->right);
    }
}

Tree* insere_tree_bin(Tree* tree, Aluno* aluno){
    if(tree != NULL){
        if(getCR(aluno) <= getCR(tree->aluno)){
            tree->left = insere_tree_bin(tree->left, aluno);
        
        } else if(getCR(aluno) > getCR(tree->aluno)){
            tree->right = insere_tree_bin(tree->right, aluno);
        }

    } else{ // Chegou numa folha.
        tree = cria_tree_bin(aluno);
    }
    return tree;
}

Tree* remove_tree_bin(Tree* tree, float chave){
    /**
     * Caso 1: nó folha
     * Caso 2: retirar nó que tem apenas uma filho.
     * Caso 3: retirar nó que tem 2 filhos.
     **/
    Tree* aux;
    if(tree != NULL){
        if(chave < getCR(tree->aluno)){
            tree->left = remove_tree_bin(tree->left, chave);

        } else if(chave > getCR(tree->aluno)){
            tree->right = remove_tree_bin(tree->right, chave);

        } else{ // Encontrou o elemento. Verificar qual caso é.
            if(tree->left == NULL && tree->right == NULL){ // Folha.
                free(tree);
                return NULL; // Atualizando ponteiro do nó pai. 
            
            } else if(tree->left != NULL ^ tree->right != NULL){ // Somente um filho (^ é xor).
                if(tree->left != NULL){ // left é o único filho.
                    aux = tree->left;
                    
                } else{ // right é o único filho.
                    aux = tree->right;
                }
                free(tree);
                return aux; // Encadeando com nó pai.
            
            } else{ // Dois filhos.
                aux = tree->left;
                while(aux->right != NULL){ // Procurando sucessor.
                    aux = aux->right;
                }

                Aluno* alunoAux = aux->aluno;
                aux->aluno = tree->aluno;
                tree->aluno = alunoAux;
                tree->left = remove_tree_bin(tree->left, chave);
            }
        }
        return tree;
    } else{
        return NULL;
    }
}

Tree* busca_tree_bin(Tree* tree, float chave){
    if(tree != NULL){
        if(chave < getCR(tree->aluno)){
            return busca_tree_bin(tree->left, chave);
        
        } else if(chave > getCR(tree->aluno)){
            return busca_tree_bin(tree->right, chave);

        } else{
            return tree;
        }
    }
    return NULL;
}

void imprime_somente_raiz(Tree* tree){
    if(tree != NULL){
        imprimeAluno(tree->aluno);
    } else{
        printf("Arvore vazia!\n");
    }
}
