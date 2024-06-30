#include "../include/matriz.hpp"
#include <iostream>
#include <cmath>

std::vector<std::vector<float>> Matriz::submatrizLinhaColuna(
            std::vector<std::vector<float>> nova_matriz,
            int linha,
            int coluna
        ) {
         
        nova_matriz.erase(nova_matriz.begin() + linha);
        for (std::vector<float> &vetor_linha : nova_matriz) {
            vetor_linha.erase(vetor_linha.begin() + coluna);
        }
        return nova_matriz;
    }

bool Matriz::matrizQuadrada(std::vector<std::vector<float>> nova_matriz) {
    bool ehQuadrada = true;
    for (std::vector<float> vetor_linha : nova_matriz) {
        if (vetor_linha.size() != nova_matriz.size()) {
            ehQuadrada = false;
        }
    }
    return ehQuadrada;
}

float Matriz::determinanteRecursiva(std::vector<std::vector<float>> nova_matriz) {
    if (nova_matriz.size() != 1) {
        float valor_determinante = 0;
        for (int i = 0; i < nova_matriz.size(); i++) {
            valor_determinante +=
              nova_matriz[0][i] 
            * determinanteRecursiva(submatrizLinhaColuna(nova_matriz, 0, i))
            * pow(-1, i);
        }
        return valor_determinante;
    } else {
        return nova_matriz[0][0];
    }
}

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
    if (matrizQuadrada(matriz_)) {
        return determinanteRecursiva(matriz_);
    } else {
        return -9999;
    }
}