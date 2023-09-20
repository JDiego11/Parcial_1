#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

void Imagen(bool**, int);               //Pide al usuario ingresar la representación personalizada de un patrón

void Verificacion(bool**, int);         //Enciende todos los leds

void Figure1(bool**, int);              //Función que replica la primera figura mostrada en el documento
void Figure2(bool**, int);              //Función que replica la segunda figura mostrada en el documento
void Figure3(bool**, int);              //Función que replica la tercera figura mostrada en el documento
void Figure4(bool**, int);              //Función que replica la cuarta figura mostrada en el documento
void Sequence(bool**, int);   //Muestra la secuencia de las figuras 1-4 un número n veces con un tiempo t entre
                                        //patrón

void PrintMatrix(bool**, int);          //Función que imprime la representación matricial del funcionamiento de los leds

void Publik(bool**, int);               //Unificación de las funciones previamente hechas (funcionamiento total del programa)

#endif // FUNCIONES_H
