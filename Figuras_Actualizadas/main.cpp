#include "Figuras.h"

int main()
{
    int dim = 8, cont = 0;
    bool **matriz = new bool*[dim];

    for(int i=0; i<dim; i++) {
        *(matriz+i) = new bool[dim];
    }

    while(cont < 5) {

        //Imprimimos la figura 1
        PrintMatrix(Figure1(matriz, dim), dim);

        cout << endl << "Delay 1s" << endl << endl;

        //imprimimos la figura 2
        PrintMatrix(Figure2(matriz, dim), dim);

        cout << endl << "Delay 1s" << endl << endl;

        //imprimimos la figura 3
        PrintMatrix(Figure3(matriz,dim),dim);
        cout << endl << "Delay 1s" << endl << endl;

        //imprimimos la figura 4
        PrintMatrix(Figure4(matriz,dim),dim);
        cout << endl << "Delay 1s" << endl << endl;

        cont++;
    }

    for(int i=0; i<dim; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
