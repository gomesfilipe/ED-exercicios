#include <stdio.h>
#include <stdlib.h>
#include "cars.h"
#include "carList.h"

int main(){
    Car* car1 = createCar("Saveiro", "Volkswagen", 1982, 30000.00);
    Car* car2 = createCar("Hilux", "Toyota", 2021, 200000.00);
    Car* car3 = createCar("Palio", "Fiat", 2010, 80000.00);
    Car* car4 = createCar("Vectra", "Chevrolet", 2015, 100000.00);
    Car* car5 = createCar("Captur", "Renault", 2019, 150000.00);

    List* carList = createList();
    carList = insertElement(carList, car1);
    carList = insertElement(carList, car2);
    carList = insertElement(carList, car3);
    carList = insertElement(carList, car4);
    carList = insertElement(carList, car5);
    printf("Lista depois de criada e elementos serem inseridos\n");
    printList(carList);

    carList = removeElement(carList, "vectra");
    carList = removeElement(carList, "sfgfgdg");
    carList = removeElement(carList, "captur");
    carList = removeElement(carList, "saveiro");
    printf("\nLista depois de remover alguns elementos\n");
    printList(carList);

    carList = insertElement(carList, car4);
    printf("\nLista depois de adicionar elementos novamente\n");
    printList(carList);

    destroyCar(car1);
    destroyCar(car2);
    destroyCar(car3);
    destroyCar(car4);
    destroyCar(car5);
    destroyList(carList);
    return 0;
}
