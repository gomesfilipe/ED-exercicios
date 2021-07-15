#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "listaMat.h"

int main(){
    int matriz1[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    int matriz2[2][2] = { {10, 20}, {30, 40}};
    int matriz3[2][3] = { {100, 200, 300}, {400, 500, 600} };
    int matriz4[3][4] = { {1000, 2000, 3000, 4000}, {5000, 6000, 7000, 8000}, {9000, 10000, 11000, 12000} }; 
    Matriz* m1 = inicializaMatriz(3, 2);
    Matriz* m2 = inicializaMatriz(2, 2);
    Matriz* m3 = inicializaMatriz(2, 3);
    Matriz* m4 = inicializaMatriz(3, 4);

    // Inicializando matriz 1.
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            modificaElemento(m1, i, j, matriz1[i][j]);
        }
    }
   
    // Inicializando matriz 2.
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            modificaElemento(m2, i, j, matriz2[i][j]);
        }
    }

    // Inicializando matriz 3.
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            modificaElemento(m3, i, j, matriz3[i][j]);
        }
    }

    // Inicializando matriz 4.
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            modificaElemento(m4, i, j, matriz4[i][j]);
        }
    }

    Matriz* transp1 = transposta(m1);
    Matriz* transp2 = transposta(m2);
    Matriz* transp3 = transposta(m3);
    Matriz* transp4 = transposta(m4);

    List* listaNormal = createList();
    List* listaTransp = createList();

    insertElement(listaNormal, m1);
    insertElement(listaNormal, m2);
    insertElement(listaNormal, m3);
    insertElement(listaNormal, m4);

    insertElement(listaTransp, transp1);
    insertElement(listaTransp, transp2);
    insertElement(listaTransp, transp3);
    insertElement(listaTransp, transp4);

    printf("Lista matrizes normais:\n\n");
    printList(listaNormal);
    printf("Lista matrizes transpostas:\n\n");
    printList(listaTransp);

    removeElement(listaNormal, 1);
    printList(listaNormal);

    destroyList(listaNormal);
    destroyList(listaTransp);
    destroiMatriz(m1);
    destroiMatriz(m2);
    destroiMatriz(m3);
    destroiMatriz(m4);
    destroiMatriz(transp1);
    destroiMatriz(transp2);
    destroiMatriz(transp3);
    destroiMatriz(transp4);

    // printf("chegou aq");
    // return 0;
    return 0;
}