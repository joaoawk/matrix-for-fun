#include "../include/matriz.hpp"
#include <iostream>

Matriz::Matriz(std::vector<std::vector<float>> nova_matriz) : matriz_(nova_matriz) {

}

void Matriz::imprimir() const {
    for (std::vector<float> linha : matriz_) {
        for (float coluna : linha) {
            std::cout << coluna << " ";
        }
        std::cout << std::endl;
    }
}

float Matriz::det() {
    return 0;
}