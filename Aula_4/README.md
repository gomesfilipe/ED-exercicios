Neste exercício, vocês vão implementar uma Lista Simplesmente Encadeada com Sentinela, como explicada nos vídeos da professora. No entanto, ao invés de ser uma lista de Alunos, será uma Lista de Matrizes! O TAD Matriz já está implementando no Exercício 3, então, vai ser moleza! :-)

Espero 3 arquivos de vocês (submetidos pelo Classroom):

1) listaMat.h: especificação do TAD Lista de Matrizes com funções de criação, inserção, retirada, impressão e liberação de memória; o retira só vai fazer sentido considerando a posição da matriz na lista.

2) listaMat.c: implementação do TAD Lista de Matrizes. Nesta implementação, não serão criadas e nem liberadas matrizes. Isso será função do cliente testador. Apenas manipulem células da lista, como explicado nos vídeos.

3) testador.c: Este arquivo contém a main que deve testar o seu TAD Lista de Matrizes. Deve-se fazer o seguinte:

a. Gerar algumas matrizes para teste (umas 3 ou 4 matrizes já seria suficiente);
b. Inicializar uma lista encadeada;
c. Inserir as matrizes na lista;
d. Inicializar outra lista encadeada;
e. Inserir as matrizes transpostas na segunda lista encadeada;
f. Imprima as listas e veja se estão corretas!!!
g. Retire algumas matrizes para verificar se o retira está funcionando (retire da primeira posição, última posição e caso comum);
h. Insira as matrizes novamente para verificar se o retira não “quebrou” a lista;
i. Libere as listas!
j. Libere as matrizes!
k. Passe o valgrind para verificar se não há erros e/ou vazamento de memória.

Divirtam-se!!!! :-)