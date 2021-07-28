#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "professor.h"
#include "listahet.h"

#define ALUNO 0
#define PROFESSOR 1

struct celula{
    void* item;
    Celula* next;
    int id;
};

struct lista{
    Celula* first;
    Celula* last;
};

Lista* criaLista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->first = NULL;
    lista->last = NULL;
    return lista;
}

void destroiLista(Lista* lista){
    Celula* i = lista->first;
    Celula *aux;
    while(i != NULL){
        aux = i;
        i = i->next;
        free(aux);
    }

    free(lista);
}

void insereAluno(Lista* lista, Aluno* aluno){
    Celula* new = (Celula*) malloc(sizeof(Celula));
    new->item = aluno;
    new->next = NULL;
    new->id = ALUNO;
    if(lista->first != NULL){
        lista->last->next = new;
    } else{
        lista->first = new;
    }
    
    lista->last = new;
}

void removeAluno(Lista* lista, char* chave){
    Celula* i = lista->first;
    Celula* aux;
    Celula* anterior = NULL;
    char* nome;
    while(i != NULL){
        if(i->id == ALUNO){
            nome = getNomeAluno(i->item);
            if(strcasecmp(chave, nome) == 0){
                if(lista->first == lista->last){ // Único elemento.
                    aux = i;
                    lista->first = NULL;
                    lista->last = NULL;
                    free(aux);
                    break;
                
                } else if(i == lista->first){ // Primeiro elemento.
                    aux = i;
                    lista->first = i->next;
                    free(aux);
                    break;
                
                } else if(i == lista->last){ // Último elemento.
                    aux = i;
                    lista->last = anterior;
                    lista->last->next = NULL;
                    free(aux);
                    break;
                
                } else{ // Caso comum.
                    aux = i;
                    anterior->next = i->next;
                    free(aux);
                    break;
                }
            }
        }

        anterior = i;
        i = i->next;
    }
}

void insereProfessor(Lista* lista, Professor* professor){
    Celula* new = (Celula*) malloc(sizeof(Celula));
    new->item = professor;
    new->next = NULL;
    new->id = PROFESSOR;
    if(lista->first != NULL){
        lista->last->next = new;
    } else{
        lista->first = new;
    }
    
    lista->last = new;
}

void removeProfessor(Lista* lista, char* chave){
    Celula* i = lista->first;
    Celula* aux;
    Celula* anterior = NULL;
    char* nome;
    while(i != NULL){
        if(i->id == PROFESSOR){
            nome = getNomeProfessor(i->item);
            if(strcasecmp(chave, nome) == 0){
                if(lista->first == lista->last){ // Único elemento.
                    aux = i;
                    lista->first = NULL;
                    lista->last = NULL;
                    free(aux);
                    break;
                
                } else if(i == lista->first){ // Primeiro elemento.
                    aux = i;
                    lista->first = i->next;
                    free(aux);
                    break;
                
                } else if(i == lista->last){ // Último elemento.
                    aux = i;
                    lista->last = anterior;
                    lista->last->next = NULL;
                    free(aux);
                    break;
                
                } else{ // Caso comum.
                    aux = i;
                    anterior->next = i->next;
                    free(aux);
                    break;
                }
            }
        }

        anterior = i;
        i = i->next;
    }
}

void imprimeLista(Lista* lista){
    Celula* i = lista->first;
    while(i != NULL){
        if(i->id == ALUNO){
            imprimeAluno(i->item);

        } else if(i->id == PROFESSOR){
            imprimeProfessor(i->item);
        }
        
        printf("\n");
        i = i->next;
    }
}
