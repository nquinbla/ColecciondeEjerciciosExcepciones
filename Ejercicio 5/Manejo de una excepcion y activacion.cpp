#include <iostream>
#include <stdexcept>

double divisionSegura(double numerador, double denominador) {
    if (denominador == 0) {
        throw std::runtime_error("Intento de división por cero.");
    }
    return numerador / denominador;
}

int main() {
    try {
        double numerador, denominador;
        std::cout << "Ingrese el numerador: ";
        std::cin >> numerador;
        std::cout << "Ingrese el denominador: ";
        std::cin >> denominador;

        double resultado = divisionSegura(numerador, denominador);
        std::cout << "Resultado de la división: " << resultado << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
        std::cout << "Por favor, vuelva a intentarlo con valores diferentes." << std::endl;
    }

    return 0;
}
