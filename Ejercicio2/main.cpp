#include<iostream>
#include<stdexcept>

int divideError(int a, int b) {
    if (b == 0) {
        return -1;
    }
    else {
        return a / b;
    }
}

int divideException(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("División por cero"); 
    }
    else {
        return a / b;
    }
}

int main() {
    int resultError = divideError(5, 0);
    if (resultError == -1) {
        std::cout << "Error: división por cero." << std::endl;
    }

    try {
        int resultException = divideException(5, 0);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}