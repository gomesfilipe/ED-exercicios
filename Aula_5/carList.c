#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cars.h"
#include "carList.h"

struct list{
    Car* car;
    List* previous;
    List* next;
};

List* createList(){
    return NULL;
}

void destroyList(List* list){
    List* aux = list;
    List* aux2;
    while(aux != NULL){
        aux2 = aux;
        aux = aux->next;
        free(aux2);
    }
}

List* insertElement(List* list, Car* element){
    List* new = (List*) malloc(sizeof(List));
    if(list != NULL){
        list->previous = new;
    }
    new->car = element;
    new->previous = NULL;
    new->next = list;
    return new;
}

List* searchElement(List* list, char* key){
    List* aux;
    char* name;
    for(aux = list; aux != NULL; aux = aux->next){
        name = getName(aux->car);
        if(strcasecmp(name, key) == 0){
            return aux;
        }
    }

    return NULL;
}

List* removeElement(List* list, char* key){
    List* aux = searchElement(list, key);
    if(aux == NULL)
        return list;

    if(aux->previous == NULL && aux->next == NULL){ // If first and last.
        free(aux);
        return NULL;
    }

    if(aux->previous == NULL){ // If first.
        list = aux->next;
        list->previous = NULL;
    
    } else if(aux->next == NULL){ // If last.
        aux->previous->next = NULL;
    
    } else{ // Normal case.
        aux->previous->next = aux->next;
        aux->next->previous = aux->previous;
    }

    free(aux);
    return list;
}

void printList(List* list){
    List* aux;
    for(aux = list; aux != NULL; aux = aux->next){
        printCar(aux->car);
        printf("\n");
    }
}