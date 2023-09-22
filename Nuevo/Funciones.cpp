#include "Funciones.h"
//comentario prueba git
int InputRange(int a, int b) {
    cout << endl;
    int input;
    while (true) {
        cout << "Ingrese una entrada: ";
            if (!(cin >> input) || input < 0 || input < a || input > b) { //Evalua si es menor que 0 o menor que a o menor que b
            // La entrada no es un número entero positivo dentro del rango
            // limpiar el estado de error y descartar la entrada inválida
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no valida. Intente nuevamente." << endl;
        } else {
            break;  // La entrada cumple con todas las condiciones, salir del bucle
        }
    }
    return input; //Retorna la entrada
}

int RowsInput(int i, int size) {
    string rowStr;
    int row;
    while (true) {
        cout << "Fila No " << i + 1 << ": ";
        cin >> rowStr;
        // Verificar si la longitud de la cadena es 8
        if (static_cast<int>(rowStr.length()) == size) {
            // Verificar si la cadena contiene solo los dígitos 0 y 1
            bool esBinario = true;
            for (char c : rowStr) {
                if (c != '0' && c != '1') {
                    esBinario = false;
                    break;
                }
            }
            if (esBinario) {// Convertir la cadena binaria a un entero
                row = stoi(rowStr);
                break; // La entrada cumple con las condiciones, salir del bucle.
            }
        }
        cout << "Entrada invalida, esto puede deberse a la cantidad incorrecta de leds por fila, ingreso de numeros o caracterec diferentes a 1 y 0." << endl;
    }
    return row;
}

int Reps(int Repe){
    cout << "Ingrese la cantida N veces que quiere que se repita la verificacion. N = ";
    Repe = InputRange(1, numeric_limits<int>::max());
    return Repe;
}

int Time(int time, string mood, int i){
    cout << "Ingrese el tiempo T"<<i<< " indicando la duracion de los leds " << mood <<". T" << i << " = ";
    time = InputRange(1, numeric_limits<int>::max());
    return time;
}

void Imagen(bool**matriz, int size)
{
    int fila, aux_led;
    int Rep = 0, time_1 = 0, time_2 = 0;
    cout << "Para ingresar el patron personalizado ten en cuenta que..." << endl;
    cout << "Vas a ingresar fila por fila de la matriz." << endl;
    cout << "Considerando que los 1 significa led encendido y 0 led apagado" << endl;

    for(int i=0; i<size; i++) {
        fila = RowsInput(i, size);
        for (int j=0; j<size; j++) {
            aux_led = fila%10;
            fila /= 10;
            if (aux_led) matriz[i][size-1-j] = true;
            else matriz[i][size-1-j] = false;
        }
    }

    Rep = Reps(Rep);
    time_1 = Time(time_1, "encendidos", 1);
    time_2 = Time(time_2, "apagados", 2);
    cout << endl;
    for (int i = 0; i < Rep; i++){
        PrintMatrix(matriz, size);
        cout << endl;
    }

}

void Verificacion(bool **matrix, int size)
{
    int Repe = 0, time_1 = 0, time_2 = 0;
    Repe = Reps(Repe);
    time_1 = Time(time_1, "encendidos", 1);
    time_2 = Time(time_2, "apagados", 2);

    cout << "Ejecutando verificacion de leds:" << endl << endl;

    //Repeticiones de los leds encendidos y apagados
    for (int i=0; i<Repe; i++ ) {
        //Leds encendidos
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                matrix[i][j] = true;
            }
        }
        //Delay(T1*(1000)) -> tiempo en milisegundos
        //Leds apagados
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                matrix[i][j] = false;
            }
        }
        //Delay(T2*(1000)) -> tiempo en milisegundos
    }
    for (int i = 0; i<Repe; i++){
        cout << endl;
        PrintMatrix(matrix, size); //Encendido time_1
        //Apagado time_2
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
    int Repe = 0, time_1 = 0, time_2 = 0;
    Repe = Reps(Repe);
    time_1 = Time(time_1, "encendidos", 1);
    time_2 = Time(time_2, "apagados", 2);

    //Ciclo para repetir los patrones
    for (int i=0; i<Repe; i++) {
        Figure1(matriz, dim);
        PrintMatrix(matriz, dim);
        cout << endl;
        //Delay(T*(1000)) -> Tiempo en milisegundos
        Figure2(matriz, dim);
        PrintMatrix(matriz, dim);
        cout << endl;
        //Delay(T*(1000)) -> Tiempo en milisegundos
        Figure3(matriz, dim);
        PrintMatrix(matriz, dim);
        cout << endl;
        //Delay(T*(1000)) -> Tiempo en milisegundos
        Figure4(matriz, dim);
        PrintMatrix(matriz, dim);
        cout << endl;
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
    cout << "Menu: Estas son las funciones que puedes realizar." << endl;
    cout << "1. Ejecutar la verificacion de los leds." << endl;
    cout << "2. Un patron personalizado o imagen de prueba." << endl;
    cout << "3. Mostrar de forma altermada 4 patrones ya predeterminados." << endl;
    opcion = InputRange(1,3);

    switch (opcion) {

    case 1:
        Verificacion(matriz, dim);
        break;

    case 2:
        Imagen(matriz, dim);
        break;

    case 3:
        Sequence(matriz, dim);
        break;
    }
}
