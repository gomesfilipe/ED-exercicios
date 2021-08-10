#include "pilha_dupla.h"

// Neste exercício considerei que a função de destruir pilha libera da memória o conteúdo dentro de cada posição do vetor.

int main(){
    Produto* produto1 = criaProduto("Cimento", 22.5, 25.5, 100);
    Produto* produto2 = criaProduto("Aglofilito", 3.0, 6.2, 300);
    Produto* produto3 = criaProduto("Cabinho 6mm", 4.0, 7.0, 150);
    Produto* produto4 = criaProduto("Pincel", 2.5, 8.0, 50);
    
    Produto* produto5 = criaProduto("Massa corrida PVA", 12.0, 21.00, 70);
    Produto* produto6 = criaProduto("Massa corrida acrilica", 17.0, 32.9, 30);
    Produto* produto7 = criaProduto("Cal", 5.0, 11.5, 15);
    Produto* produto8 = criaProduto("Manilha de barro", 20.0, 29.0, 250);

    PilhaDupla* pilhaDupla = criaPilhaDupla();

    push(pilhaDupla, produto1, 1);
    push(pilhaDupla, produto2, 1);
    push(pilhaDupla, produto3, 1);
    push(pilhaDupla, produto4, 1);

    push(pilhaDupla, produto5, 2);
    push(pilhaDupla, produto6, 2);
    push(pilhaDupla, produto7, 2);
    push(pilhaDupla, produto8, 2);

    printf("PILHAS INICIALIZADAS:\n");
    printPilha(pilhaDupla);

    pop(pilhaDupla, 1);
    pop(pilhaDupla, 2);
    pop(pilhaDupla, 1);
    pop(pilhaDupla, 2);

    printf("PILHAS APOS REMOVER ALGUNS ELEMENTOS:\n");
    printPilha(pilhaDupla);

    pop(pilhaDupla, 1);
    pop(pilhaDupla, 2);
    pop(pilhaDupla, 1);
    pop(pilhaDupla, 2);
    
    printf("PILHAS APOS REMOVER TODOS OS ELEMENTOS:\n");
    printPilha(pilhaDupla);

    // Criando novos produtos para inserir na pilha novamente.
    Produto* produto9 = criaProduto("Carrinho de mao", 120.0, 159.9, 4);
    Produto* produto10 = criaProduto("Pa de bico numero 4", 30.0, 55.0, 6);
    Produto* produto11 = criaProduto("Pa quadrada", 28.0, 52.9, 8);
    Produto* produto12 = criaProduto("Derepoxi", 4.2, 10.0, 15);
    
    push(pilhaDupla, produto9, 1);
    push(pilhaDupla, produto10, 1);
    
    push(pilhaDupla, produto11, 2);
    push(pilhaDupla, produto12, 2);

    printf("PILHA APOS ADICIONAR ALGUNS ELEMENTOS PARA VERIFICAR SE ESTA TUDO CERTO:\n");
    printPilha(pilhaDupla);

    destroiPilhaDupla(pilhaDupla);
    return 0;
}
