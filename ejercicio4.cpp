#include <iostream>
#include <exception>

// Clase de excepción para errores de entrada inválida
class InputErrorException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Entrada inválida.";
    }
};

// Clase de excepción para errores de cálculo
class CalculationErrorException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Error de cálculo.";
    }
};

// Función que realiza un cálculo, pero puede lanzar una excepción CalculationErrorException
int performCalculation(int a, int b) {
    if (b == 0) {
        throw CalculationErrorException();
    }
    return a / b;
}

int main() {
    int numerador, denominador;

    try {
        std::cout << "Ingrese el numerador: ";
        std::cin >> numerador;
        std::cout << "Ingrese el denominador: ";
        std::cin >> denominador;

        if (denominador == 0) {
            throw InputErrorException();
        }

        int resultado = performCalculation(numerador, denominador);
        std::cout << "El resultado de la división es: " << resultado << std::endl;
    } catch (const InputErrorException& ex) {
        std::cerr << "Excepción de entrada capturada: " << ex.what() << std::endl;
    } catch (const CalculationErrorException& ex) {
        std::cerr << "Excepción de cálculo capturada: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Otra excepción capturada: " << ex.what() << std::endl;
    }

    return 0;
}
