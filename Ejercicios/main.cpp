#include "Figuras.h"

int main()
{
    int dim = 8, func;
    bool **matriz = new bool*[dim];

    for(int i=0; i<dim; i++) {
        *(matriz+i) = new bool[dim];
    }

    cout << "elija que quiere hacer: ";
    cin >> func;
    cout << endl;
    switch (func) {

    case 1:                     //Función Verificación
        Verificacion(matriz, dim);
        PrintMatrix(matriz, dim);
        cout << endl << endl;
        break;

    case 2:                     //Figura 1
        Figure1(matriz, dim);
        PrintMatrix(matriz, dim);
        cout << endl << endl;
        break;

    case 3:                     //Figura 2
        Figure2(matriz, dim);
        PrintMatrix(matriz, dim);
        cout << endl << endl;
        break;
    }

    for(int i=0; i<dim; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
