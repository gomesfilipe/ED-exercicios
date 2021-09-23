#include "hash.h"

struct hash{
    Palavra** vet;
    int tam;
};

Hash* cria_hash(int tam){
    Hash* hash = (Hash*) malloc(sizeof(Hash));
    hash->tam = tam;

    hash->vet = (Palavra**) malloc(tam * sizeof(Palavra*));
    
    for(int i = 0; i < tam; i++){
        hash->vet[i] = NULL;
    }
    return hash;
}

Palavra* acessa(Hash* hash, char* string){
    int indice = funcao_hash(string, hash->tam);

    Palavra* palavra = busca_palavra(hash->vet[indice], string);
    
    if(palavra != NULL){
        return palavra; 
    }
    // Palavra não está na lista de colisões.
    palavra = cria_palavra(string);
    hash->vet[indice] = insere_palavra_lista(hash->vet[indice], palavra);
    return palavra;
}

int conta_palavras(Hash* hash){
    int counter = 0;
    for(int i = 0; i < hash->tam; i++){
        counter += conta_palavras_lista(hash->vet[i]);
    }
    return counter;
}

void imprime_hash(Hash* hash){
    for(int i=  0; i < hash->tam; i++){
        printf("vet[%d]:\n", i);
        imprime_lista_palavra(hash->vet[i]);
        printf("\n");
    }
}

void libera_hash(Hash* hash){
    for(int i = 0; i < hash->tam; i++){
        libera_lista_palavra(hash->vet[i]);
    }
    free(hash->vet);
    free(hash);
}

int funcao_hash(char* string, int tam){
    int indice = 0;
    for(int i = 0; string[i] != '\0'; i++){
        indice += string[i];
    }
    return indice % tam;
}
