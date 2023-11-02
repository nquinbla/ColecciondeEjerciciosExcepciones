#include <iostream>
#include <fstream>
#include <stdexcept>

void funcion_lanza_excepcion() {
    std::ifstream archivo("archivo_inexistente.txt");
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo");
    }
}

int main() {
    try {
        funcion_lanza_excepcion();
    } catch (const std::exception& e) {
        std::cout << "Excepción atrapada en la función: " << e.what() << std::endl;

        try {
            throw;
        } catch (const std::exception& rethrown) {
            std::cout << "Excepción relanzada y atrapada nuevamente: " << rethrown.what() << std::endl;
        }
    }

    return 0;
}
