#include "palavra.h"

struct palavra{
    char* string;
    int ocorrencias;
    Palavra* next;
};

Palavra* cria_palavra(char* string){
    Palavra* palavra = (Palavra*) malloc(sizeof(Palavra));
    palavra->string = strdup(string);
    palavra->ocorrencias = 0;
    palavra->next = NULL;
    return palavra;
}

char* get_string(Palavra* palavra){
    return palavra->string;
}

int get_ocorrencias(Palavra* palavra){
    return palavra->ocorrencias;
}

void atualiza_ocorrencias(Palavra* palavra){
    palavra->ocorrencias++;
}

Palavra* busca_palavra(Palavra* palavra, char* string){
    Palavra* i;
    for(i = palavra; i != NULL; i = i->next){
        if(strcmp(i->string, string) == 0){
            return i;
        }
    }
    return NULL;
}

Palavra* insere_palavra_lista(Palavra* lista, Palavra* inserida){
    inserida->next = lista;
    return inserida;
}

int conta_palavras_lista(Palavra* palavra){
    Palavra* i;
    int counter = 0;
    for(i = palavra; i != NULL; i = i->next){
        counter++;
    }
    return counter;
}

void imprime_lista_palavra(Palavra* palavra){
    Palavra* i;
    for(i = palavra; i != NULL; i = i->next){
        printf("string: [%s] | ocorrencias: [%d]\n", i->string, i->ocorrencias);
    }
}

void libera_lista_palavra(Palavra* palavra){
    Palavra* i = palavra;
    Palavra* aux;
    while(i != NULL){
        aux = i;
        i = i->next;
        free(aux->string);
        free(aux);
    }
}
