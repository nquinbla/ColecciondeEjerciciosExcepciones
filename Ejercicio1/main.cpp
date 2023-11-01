#include<iostream>

// Variable global que indica si ocurrio un error.
// Si errorFlag es verdadero, entonces ocurrio un error.

bool errorFlag = false;

int divide(int a, int b) {
    // Si b es 0, entonces ocurrio un error.
    // Se asigna true a errorFlag, para indicar que ocurrio un error.
    if (b == 0) {
        errorFlag = true;
        return 0;
    }
    else {
        return a / b;
    }
}

int main() {
    // Se utiliza la funcion divide para dividir 54 entre 0.
    int result = divide(54, 0);
    if (errorFlag) {
        std::cout << "Ocurrio un error: division por cero." << std::endl;
        errorFlag = false;
    }

    return 0;
}
