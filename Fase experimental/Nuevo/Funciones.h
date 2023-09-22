#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <limits>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

void Imagen(bool**, int);               //Pide al usuario ingresar la representación personalizada de un patrón

void Verificacion(bool**, int);         //Enciende todos los leds

void Figure1(bool**, int);              //Función que replica la primera figura mostrada en el documento
void Figure2(bool**, int);              //Función que replica la segunda figura mostrada en el documento
void Figure3(bool**, int);              //Función que replica la tercera figura mostrada en el documento
void Figure4(bool**, int);              //Función que replica la cuarta figura mostrada en el documento
<<<<<<< HEAD
void Sequence(bool**, int);             //Muestra la secuencia de las figuras 1-4 un número N veces con un tiempo T entre
=======
void Sequence(bool**, int);   //Muestra la secuencia de las figuras 1-4 un número n veces con un tiempo t entre
>>>>>>> a39cec0f7c4b0380e9bc152bbbd6e3046dc86a5a
                                        //patrón

void PrintMatrix(bool**, int);          //Función que imprime la representación matricial del funcionamiento de los leds

void Publik(bool**, int); //Unificación de las funciones previamente hechas (funcionamiento total del programa)

int InputRange(int, int);  //Funcion que verifica una entrada entera entre a y b.
int RowsInput(int, int);   //Funcion que verifica la entrada binaria para las filas de encendido de los leds
int Reps(int); //Funcion que pide las repeticiones de secuencias
int Time(int, char, int);

#endif // FUNCIONES_H
