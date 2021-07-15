#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "listaMat.h"

struct celula {
    Matriz* matriz;
    Celula* next;
};

struct list {
    Celula* first;
    Celula* last;
};

List* createList(){
    List* list = (List*) malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
    return list;
}

Celula* createCelula(Matriz* matriz){
    Celula* celula = (Celula*) malloc(sizeof(Celula));
    celula->matriz = matriz;
    celula->next = NULL;
    return celula;
}

int sizeList(List* list){
    Celula* aux;
    int size = 0;
    for(aux = list->first; aux != NULL; aux = aux->next){
        size++;
    }

    return size;
}

void insertElement(List* list, Matriz* matriz){
    Celula* lastCelula = createCelula(matriz);
    if(sizeList(list) == 0){
        list->first = lastCelula;
        list->last = lastCelula;
    } else{
        list->last->next = lastCelula;
        list->last = lastCelula;
    }
    
}

void removeElement(List* list, int position){
    int size = sizeList(list), i;
    Celula* aux;
    Celula* previous = NULL;
    Celula* next;
    if(position <= 0 || position > size || size == 0){
        printf("ERROR\n");
    
    } else{
        for(i = 1, aux = list->first; i <= position; i++, aux = aux->next){
            next = aux->next;
            
            if(i == position){
                free(aux);
                previous->next = next;

            } else{
                previous = aux;
            }
        }

        // If element is first or last, update the sentinel of list.
        if(position == 1){
            list->first = next;
        }
        
        if(position == size){
            list->last = previous;
        }
    }
}

void printList(List* list){
    Celula* aux;
    for(aux = list->first; aux != NULL; aux = aux->next){
        imprimeMatriz(aux->matriz);
        printf("\n");
    }
}

void destroyList(List* list){
    Celula* aux = list->first;
    Celula* aux2;
    while(aux != NULL){
        aux2 = aux;
        aux = aux->next;
        free(aux2);
    }

    free(list);
}
