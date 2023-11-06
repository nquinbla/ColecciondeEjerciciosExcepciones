#include <iostream>

// Función que lanza una excepción
void lanzarExcepcion() {
    std::cout << "Lanzando una excepción en la función 'lanzarExcepcion'." << std::endl;
    throw std::runtime_error("Excepción lanzada en 'lanzarExcepcion'");
}
// Función intermedia que llama a 'segundafunción'
void funcionIntermedia() {
    std::cout << "entrando en la función 'segundafunción'." << std::endl;
    lanzarExcepcion();
    std::cout << "Saliendo de la función 'segundafunción'." << std::endl;
}

// Función principal que llama a 'función intermedia'
int main() {
    try {
        std::cout << "Entrando en la función 'main'." << std::endl;
        funcionIntermedia();
        std::cout << "Saliendo de la función 'main'." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada en 'main': " << e.what() << std::endl;
    }

    return 0;
}

