#include "matriz.h"

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
        matriz->tabela[i] = (Matriz*) malloc(sizeof(Matriz) * ncolunas);
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

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicação
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 não são modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){

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
