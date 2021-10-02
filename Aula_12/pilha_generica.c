#include "pilha_generica.h"

struct pilha_gen{
    void* item;
    Pilha_gen* next;
};

Pilha_gen* cria_pilha_gen(){
    return NULL;
}

void destroi_pilha_gen(Pilha_gen* pilha){
    Pilha_gen* i = pilha;
    Pilha_gen* aux;

    while(i != NULL){
        aux = i;
        i = i->next;
        free(aux);
    }
    free(pilha);
}

Pilha_gen* push_gen(Pilha_gen* pilha, void* item){
    Pilha_gen* nova = (Pilha_gen*) malloc(sizeof(Pilha_gen));
    nova->next = pilha;
    nova->item = item;
    return nova;
}

Pilha_gen* pop_gen(Pilha_gen* pilha){
    Pilha_gen* aux = pilha;
    pilha = pilha->next;
    free(aux);
    return pilha;
}

int percorre_pilha_gen(Pilha_gen* pilha, fptr cb, void* dado){
    Pilha_gen* i;
    int retorno;
    for(i = pilha; i != NULL; i = i->next){
        retorno = cb(i->item, dado); // Condição de parada do caminhamento na pilha depende do callback.
        if(retorno == 0){
            return retorno;
        }
    }
    return 1;
}
