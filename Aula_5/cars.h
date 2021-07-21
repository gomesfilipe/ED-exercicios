#ifndef CARS_H_
#define CARS_H_

typedef struct car Car;

/**
 * Allocates memory space to a car and initializes it.
 * @param name Car name.
 * @param brand Car brand.
 * @param year Car year.
 * @param value Car value.
 * @return Car type initialized.
 **/
Car* createCar(char* name, char* brand, int year, float value);

/**
 * Frees from memory a car type.
 * @param car Car.
 **/
void destroyCar(Car* car);

/**
 * Prints on the screen a car type.
 * @param car Car.
 **/
void printCar(Car* car);

/**
 * Get car name.
 * @param car
 * @return Car name.
 **/
char* getName(Car* car);

/**
 * Get car brand.
 * @param car
 * @return Car brand.
 **/
char* getBrand(Car* car);

/**
 * Get car year.
 * @param car
 * @return Car year.
 **/
int getYear(Car* car);

/**
 * Get car value.
 * @param car
 * @return Car value.
 **/
float getValue(Car* car);

#endif
