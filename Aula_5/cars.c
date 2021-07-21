#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cars.h"

struct car{
    char* name;
    char* brand;
    int year;
    float value;
};

Car* createCar(char* name, char* brand, int year, float value){
    Car* car = (Car*) malloc(sizeof(Car));
    car->name = strdup(name);
    car->brand = strdup(brand);
    car->year = year;
    car->value = value;
    return car;
}

void destroyCar(Car* car){
    free(car->name);
    free(car->brand);
    free(car);
}

void printCar(Car* car){
    printf("Name: %s\n", car->name);
    printf("Brand: %s\n", car->brand);
    printf("Year: %d\n", car->year);
    printf("Value: %.2f\n", car->value);
}

char* getName(Car* car){
    return car->name;
}

char* getBrand(Car* car){
    return car->brand;
}

int getYear(Car* car){
    return car->year;
}

float getValue(Car* car){
    return car->value;
}
