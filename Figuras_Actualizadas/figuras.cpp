#include "Figuras.h"

bool **Figure1(bool **matriz, int dim) {
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
    return matriz;
}

bool **Figure2(bool **matriz, int dim) {
    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            if (i==j || (i+j) == (dim-1)) matriz[i][j] = true;
            else matriz[i][j] = false;
        }
    }
    return matriz;
}

bool **Figure3(bool **matriz, int dim){
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
    return matriz;
}

bool **Figure4(bool **matriz, int dim){
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
    return matriz;
}

void PrintMatrix(bool **matrix, int size){
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
