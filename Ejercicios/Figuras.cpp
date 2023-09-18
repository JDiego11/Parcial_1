#include "Figuras.h"

void Verificacion(bool **matrix, int size)
{
    cout << "Ejecutando verificacion de leds:" << endl;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            matrix[i][j] = true;
        }
    }

    //return matrx;
}

void Figure1(bool **matriz, int dim) {
    cout << "Mostrando Figura 1:" << endl;
    int mid = dim/2;
    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            if (j<=(mid-1)) {
                if (i<=(mid-1) && j>=(mid-1)-i) matriz[i][j] = true;
                else if(i>(mid-1) && j>=(i-mid)) matriz[i][j] = true;
                else matriz[i][j] = false;
            }
            else {
                if (i<=(mid-1) && i>=(j-mid)) matriz[i][j] = true;
                else if (i>mid-1 && (i+j)<=(mid*3)-1) matriz[i][j] = true;
                else matriz[i][j] = false;
            }
        }
    }
    //return matriz;
}
void Figure2(bool **matriz, int dim) {
    cout << "Mostrando Figura 2:" << endl;
    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            if (i==j || (i+j) == (dim-1)) matriz[i][j] = true;
            else matriz[i][j] = false;
        }
    }
    //return matriz;
}

void PrintMatrix(bool **matrix, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
