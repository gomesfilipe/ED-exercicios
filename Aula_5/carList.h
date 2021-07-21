#ifndef CARLIST_H_
#define CARLIST_H_

typedef struct list List;

/**
 * Creates an empyt car list.
 * @return Empty car list.
 **/
List* createList();

/**
 * Frees from memory a car list.
 * @param list Car list.
 **/
void destroyList(List* list);

/**
 * Inserts an element at the beginning of list.
 * @param list Car list.
 * @param element Car that will be inserted.
 * @return Updated list.
 **/
List* insertElement(List* list, Car* element);

/**
 * Removes an element from a specific key from the list. This case, the key are car name.
 * @param list Car list.
 * @param key Car name that will be removed.
 * @return Updated list.
 **/
List* removeElement(List* list, char* key);

/**
 * Prints on the screen the datas of car.
 * @param list Car list.
 **/
void printList(List* list);

//! RETIRAR
List* searchElement(List* list, char* key);

#endif
