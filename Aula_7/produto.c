#include "produto.h"

struct produto{
    char* nome;
    float custo;
    float preco;
    int estoque;
};

char* getNome(Produto* produto){
    return produto->nome;
}

float getCusto(Produto* produto){
    return produto->custo;
}

float getPreco(Produto* produto){
    return produto->preco;
}

int getEstoque(Produto* produto){
    return produto->estoque;
}

Produto* setNome(Produto* produto, char* nome){
    free(produto->nome);
    produto->nome = strdup(nome);
    return produto;
}

Produto* setCusto(Produto* produto, float custo){
    produto->custo = custo;
    return produto;
}

Produto* setPreco(Produto* produto, float preco){
    produto->preco = preco;
    return produto;
}

Produto* setEstoque(Produto* produto, int estoque){
    produto->estoque = estoque;
    return produto;
}

Produto* criaProduto(char* nome, float custo, float preco, float estoque){
    Produto* produto = (Produto*) malloc(sizeof(Produto));
    produto->nome = strdup(nome);
    produto->custo = custo;
    produto->preco = preco;
    produto->estoque = estoque;
    return produto;
}

void destroiProduto(Produto* produto){
    free(produto->nome);
    free(produto);
}

void imprimeProduto(Produto* produto){
    printf("Nome: %s\n", produto->nome);
    printf("Custo: %d\n", produto->custo);
    printf("Preco: %d\n", produto->preco);
    printf("Estoque: %d\n", produto->estoque);
}
