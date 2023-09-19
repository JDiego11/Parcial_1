#include "Funciones.h"

int main()
{
    int dim = 8;
    //Creamos la matriz de tamaño dim x dim
    bool **matriz = new bool*[dim];

    for(int i=0; i<dim; i++) {
        *(matriz+i) = new bool[dim];
    }

    //Funciones a llamar
    Imagen(matriz, dim);
    PrintMatrix(matriz, dim);

    //Liberamos la memoria ocupada por la matriz
    for(int i=0; i<dim; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    return 0;
}
