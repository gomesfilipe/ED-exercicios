#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"
#include "hash.h"

#define NPAL 64
#define NTAB 127

// Obs: passar nome do arquivo.txt na linha de comando.
// Não fiz um tratamento muito rigoroso na leitura do arquivo, pois não é
// o foco do exercício.

/**
 * @brief Le uma palavra num arquivo.
 * @param f Ponteiro para o arquivo que contém a palavra que será lida.
 * @param string String que terá o conteúdo da palavra armazenado.
 * @return 0, caso chegue ao final do arquivo e 1, caso contrário.
 * 
 **/
int le_palavra(FILE* f, char* string);

int main(int argc, char** argv){
    if(argc != 2){
        printf("Arquivo nao encontrado.\n");
        exit(1);
    }

    FILE* f = fopen(argv[1], "r");
    if(f == NULL){
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    Hash* hash = cria_hash(NTAB);
    char string[100];
    char end;
    while(1){
        end = le_palavra(f, string);
        if(end == 0){ // Chegou no final do arquivo.
            break;
        }
        Palavra* palavra = acessa(hash, string);
        atualiza_ocorrencias(palavra);
    }

    imprime_hash(hash);

    libera_hash(hash);
    fclose(f);
    return 0;
}

int le_palavra(FILE* f, char* string){
    fscanf(f, "%s%*c", string);
    if(feof(f)){
        return 0;
    }
    return 1;
}
