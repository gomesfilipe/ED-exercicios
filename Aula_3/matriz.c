#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct matriz{
    int nlinhas;
    int ncolunas;
    int** tabela;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz* matriz = (Matriz*) malloc(sizeof(Matriz));

    matriz->nlinhas = nlinhas;
    matriz->ncolunas = ncolunas;
    matriz->tabela = (int**) malloc(sizeof(int*) * nlinhas);
    
    for(int i = 0; i < nlinhas; i++){
        matriz->tabela[i] = (int*) malloc(sizeof(int) * ncolunas);
    }

    return matriz;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->tabela[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->tabela[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->ncolunas;
}

int recuperaNLinhas (Matriz* mat){
    return mat->nlinhas;
}

Matriz* transposta (Matriz* mat){
    Matriz* transp = inicializaMatriz(mat->ncolunas, mat->nlinhas);
    for(int i = 0; i < transp->nlinhas; i++){
        for(int j = 0; j < transp->ncolunas; j++){
            modificaElemento(transp, i, j, mat->tabela[j][i]);
        }
    }

    return transp;
}

// Função auxiliar para a função 'multiplicacao'. Não precisa declarar no .h pois é usado apenas na implementação.
int multiplicaLinhaPorColuna(Matriz* mat1, Matriz* mat2, int linha, int coluna){
    int result = 0;
    for(int i = 0; i < mat1->ncolunas; i++){
        result += mat1->tabela[linha][i] * mat2->tabela[i][coluna];
    }
    return result;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    Matriz *result = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);

    for(int i = 0; i < result->nlinhas; i++){
        for(int j = 0; j < result->ncolunas; j++){
            result->tabela[i][j] = multiplicaLinhaPorColuna(mat1, mat2, i, j);
        }
    }

    return result;
}

void imprimeMatriz(Matriz* mat){
    for(int i = 0; i < mat->nlinhas; i++){
        for(int j = 0; j < mat->ncolunas; j++){
            printf("%d ", mat->tabela[i][j]);
        }

        printf("\n");
    }
}

void destroiMatriz(Matriz* mat){
    for(int i = 0; i < mat->nlinhas; i++){
        free(mat->tabela[i]);
    }

    free(mat->tabela);
    free(mat);
}
