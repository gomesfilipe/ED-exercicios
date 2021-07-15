#ifndef LISTAMAT_H_
#define LISTAMAT_H_

typedef struct celula Celula;
typedef struct list List;

/**
 * Creates an empty list.
 **/
List* createList();

/**
 * Inserts an element at the end of list.
 * @param list List of matrices.
 * @param matriz Element that will be inserted on the list.
 **/
void insertElement(List* list, Matriz* matriz);

/**
 * Removes an element from a specific position from the list.
 * @param list List of matrices.
 * @param position Position of element that will be removed.
 **/
void removeElement(List* list, int position);

/**
 * Print the list of matrices.
 * @param list List that will be printed.
 **/
void printList(List* list);

/**
 * Releases from memory the list of matrices.
 * @param list List that will be destroyed.
 **/
void destroyList(List* list);

#endif
