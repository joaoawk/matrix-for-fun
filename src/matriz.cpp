#include "../include/matriz.hpp"
#include <iostream>

Matriz::Matriz(std::vector<std::vector<float>> matriz_saida) : matriz_(matriz_saida) {

}

void Matriz::imprimir() const {
    for (std::vector<float> linha : matriz_) {
        for (float coluna : linha) {
            std::cout << coluna << " ";
        }
        std::cout << std::endl;
    }
}