#include "fila.h"

// Neste exercício considerei que a função de destruir fila não libera da memória o conteúdo dentro dela.

int main(){
    Produto* produto1 = criaProduto("Cimento", 22.5, 25.5, 100);
    Produto* produto2 = criaProduto("Aglofilito", 3.0, 6.2, 300);
    Produto* produto3 = criaProduto("Cabinho 6mm", 4.0, 7.0, 150);
    Produto* produto4 = criaProduto("Pincel", 2.5, 8.0, 50);
    Produto* produto5 = criaProduto("Massa corrida PVA", 12.0, 21.00, 70);
    Produto* produto6 = criaProduto("Massa corrida acrilica", 17.0, 32.9, 30);
    Produto* produto7 = criaProduto("Cal", 5.0, 11.5, 15);
    Produto* produto8 = criaProduto("Manilha de barro", 20.0, 29.0, 250);

    Fila* fila = criaFila();

    insere(fila, produto1);
    insere(fila, produto2);
    insere(fila, produto3);
    insere(fila, produto4);
    insere(fila, produto5);
    insere(fila, produto6);
    insere(fila, produto7);
    insere(fila, produto8);

    printf("FILA INICIALIZADA:\n");
    printFila(fila);

    retira(fila);
    retira(fila);
    retira(fila);
    retira(fila);

    printf("FILA APOS REMOVER ALGUNS ELEMENTOS:\n");
    printFila(fila);

    retira(fila);
    retira(fila);
    retira(fila);
    retira(fila);
    
    printf("FILA APOS REMOVER TODOS OS ELEMENTOS:\n");
    printFila(fila);

    // Criando novos produtos para inserir na pilha novamente.
    Produto* produto9 = criaProduto("Carrinho de mao", 120.0, 159.9, 4);
    Produto* produto10 = criaProduto("Pa de bico numero 4", 30.0, 55.0, 6);
    Produto* produto11 = criaProduto("Pa quadrada", 28.0, 52.9, 8);
    Produto* produto12 = criaProduto("Derepoxi", 4.2, 10.0, 15);
    
    insere(fila, produto9);
    insere(fila, produto10);
    insere(fila, produto11);
    insere(fila, produto12);

    printf("FILA APOS ADICIONAR ALGUNS ELEMENTOS PARA VERIFICAR SE ESTA TUDO CERTO:\n");
    printFila(fila);

    destroiFila(fila);
    destroiProduto(produto1);
    destroiProduto(produto2);
    destroiProduto(produto3);
    destroiProduto(produto4);
    destroiProduto(produto5);
    destroiProduto(produto6);
    destroiProduto(produto7);
    destroiProduto(produto8);
    destroiProduto(produto9);
    destroiProduto(produto10);
    destroiProduto(produto11);
    destroiProduto(produto12);
    return 0;
}
