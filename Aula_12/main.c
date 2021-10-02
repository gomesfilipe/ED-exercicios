#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "pilha_generica.h"
#include "pilha_produto.h"

int main(){
    Produto* produto1 = criaProduto("Cimento", 22.5, 25.5, 100);
    Produto* produto2 = criaProduto("Aglofilito", 3.0, 6.2, 300);
    Produto* produto3 = criaProduto("Cabinho 6mm", 4.0, 7.0, 150);
    Produto* produto4 = criaProduto("Pincel", 2.5, 8.0, 50);
    Produto* produto5 = criaProduto("Massa corrida PVA", 12.0, 21.00, 70);
    Produto* produto6 = criaProduto("Massa corrida acrilica", 17.0, 32.9, 30);
    Produto* produto7 = criaProduto("Cal", 5.0, 11.5, 15);
    Produto* produto8 = criaProduto("Manilha de barro", 20.0, 29.0, 250);

    Pilha* pilha = cria_pilha(pilha);

    pilha = push(pilha, produto1);
    pilha = push(pilha, produto2);
    pilha = push(pilha, produto3);
    pilha = push(pilha, produto4);
    pilha = push(pilha, produto5);
    pilha = push(pilha, produto6);
    pilha = push(pilha, produto7);
    pilha = push(pilha, produto8);

    printf("Imprimindo pilha\n");
    imprime_pilha(pilha);

    // pilha = pop(pilha);
    // pilha = pop(pilha);
    // pilha = pop(pilha);

    // printf("\nImprimindo pilha depois de remover alguns elementos\n");
    // imprime_pilha(pilha);
    
    // pilha = push(pilha, produto6);
    // pilha = push(pilha, produto7);
    // pilha = push(pilha, produto8);

    // printf("\nImprimindo pilha depois de colocar os elementos novamente\n");
    // imprime_pilha(pilha);

    printf("\nManilha de barro pertence a pilha? [%d]\n", pertence_pilha(pilha, "Manilha de barro"));
    printf("Cimento pertence a pilha? [%d]\n", pertence_pilha(pilha, "Cimento"));
    printf("Chave de fenda pertence a pilha? [%d]\n", pertence_pilha(pilha, "Chave de fenda"));

    destroi_pilha(pilha);
    destroiProduto(produto1);
    destroiProduto(produto2);
    destroiProduto(produto3);
    destroiProduto(produto4);
    destroiProduto(produto5);
    destroiProduto(produto6);
    destroiProduto(produto7);
    destroiProduto(produto8);
}
