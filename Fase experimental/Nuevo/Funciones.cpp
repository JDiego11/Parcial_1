#include "Funciones.h"

void Imagen(bool**matriz, int size)
{
    int fila, aux_led;
    cout << "Para ingresar el patron personalizado tenga en cuenta que..." << endl;
    cout << "Vas a ingresar fila por fila de la matriz." << endl;
    cout << "Considerando que los 1 significa led encendido y 0 led apagado" << endl;

    for(int i=0; i<size; i++) {
        cout << "Fila No " << i+1 << ": ";
        cin >> fila;
        for (int j=0; j<size; j++) {
            aux_led = fila%10;
            fila /= 10;
            if (aux_led) matriz[i][size-1-j] = true;
            else matriz[i][size-1-j] = false;
        }
    }
}

void Verificacion(bool **matrix, int size)
{
    int Repe, time_1, time_2;
    cout << "Ingrese la cantida N veces que quiere que se repita la verificacion: N=";
    cin >> Repe;
    cout << "Ingrese el tiempo T1 indicando la duracion de los leds encendidos: T1= ";
    cin >> time_1;
    cout << "Ingrese el tiempo T2 indicando la duracion de los leds apagados: T2= ";
    cin >> time_2;

    cout << "Ejecutando verificacion de leds:" << endl;

    //Repeticiones de los leds encendidos y apagados
    for (int i=0; i<Repe; i++ ) {
        //Leds encendidos
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                matrix[i][j] = true;
            }
        }
        PrintMatrix(matrix, size);
        //Delay(T1*(1000)) -> tiempo en milisegundos
        //Leds apagados
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                matrix[i][j] = false;
            }
        }
        PrintMatrix(matrix, size);
        //Delay(T2*(1000)) -> tiempo en milisegundos
    }
}

void Figure1(bool **matriz, int dim) {
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
}

void Figure2(bool **matriz, int dim) {
    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            if (i==j || (i+j) == (dim-1)) matriz[i][j] = true;
            else matriz[i][j] = false;
        }
    }
}

void Figure3(bool **matriz, int dim){
    for (int i = 0; i < dim; i++){
        if ((i/2) % 2 == 0){
            int pos = 2;
            for (int k = 0; k < dim; k++){
                if ((i-i)+k == pos){
                    matriz[i][k] = false;
                    pos += 3;
                }else{
                    matriz[i][k] = true;
                }
            }
        }else{
            for (int k = 0; k < dim; k++) {
                if (i - i + k % 3 == 0) {
                    matriz[i][k] = false;
                } else {
                    matriz[i][k] = true;
                }
            }
        }
    }
}

void Figure4(bool **matriz, int dim){
    for (int i = 0; i < dim; i++){
        for (int k = 0; k < dim; k++){
            if (i < dim /2){
                if (k - i < 0 or k - i > dim/2 - 1){
                    matriz[i][k] = false;
                }else{
                    matriz[i][k] = true;
                }
            }else{
                if (k+i < dim - 1 or k + i > dim + (dim/2) - 2){
                    matriz[i][k] = false;
                }else
                    matriz[i][k] = true;
            }
        }
    }
}

void Sequence(bool**matriz, int dim)
{
    int Repe, time;
    cout << "Acontinuacion se van a mostrar 4 patrones ya declarados" << endl;
    cout << "Ingrese la cantida N veces que quiere que se repita el patron: N=";
    cin >> Repe;
    cout << "Ingrese el tiempo T que se visualizara cada patron: T= ";
    cin >> time;

    //Ciclo para repetir los patrones
    for (int i=0; i<Repe; i++) {
        Figure1(matriz, dim);
        PrintMatrix(matriz, dim);
        //Delay(T*(1000)) -> Tiempo en milisegundos
        Figure2(matriz, dim);
        PrintMatrix(matriz, dim);
        //Delay(T*(1000)) -> Tiempo en milisegundos
        Figure3(matriz, dim);
        PrintMatrix(matriz, dim);
        //Delay(T*(1000)) -> Tiempo en milisegundos
        Figure4(matriz, dim);
        PrintMatrix(matriz, dim);
        //Delay(T*(1000)) -> Tiempo en milisegundos
    }
}

void PrintMatrix(bool **matrix, int size){
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Publik(bool **matriz, int dim)
{
    int opcion;
    cout << "Menu:\nEstas son las funciones que puedes realizar." << endl;
    cout << "1. Ejecutar la verificacion de los leds." << endl;
    cout << "2. Un patron personalizado o imagen de prueba." << endl;
    cout << "3. Mostrar de forma altermada 4 patrones ya predeterminados." << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    while (opcion < 1 || opcion > 3) {
        cout << "La entrada " << opcion << " no es valida, intente de nuevo: ";
        cin >> opcion;
    }

    switch (opcion) {

    case 1:
        Verificacion(matriz, dim);
        break;

    case 2:
        Imagen(matriz, dim);
        PrintMatrix(matriz, dim);
        break;

    case 3:
        Sequence(matriz, dim);
        break;
    }
}
