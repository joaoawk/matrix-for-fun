#include "../include/matriz.hpp"
#include <iostream>
#include <cmath>

Matriz::Matriz(std::vector<std::vector<float>> nova_matriz) : matriz_(nova_matriz) {
    retangularizarMatriz();
}

Matriz::Matriz(std::vector<std::vector<float>> matriz_entrada, int linha, int coluna) : Matriz(matriz_entrada) {
    // Constroi uma submatriz a partir da remoção de linha e coluna da matriz.
    matriz_.erase(matriz_.begin() + linha);
    for (std::vector<float> &vetor_linha : matriz_) {
            vetor_linha.erase(vetor_linha.begin() + coluna);
    }
}

void Matriz::imprimir() const {
    for (std::vector<float> vetor_linha : matriz_) {
        for (float coluna : vetor_linha) {
            std::cout << coluna << " ";
        }
        std::cout << std::endl;
    }
}

int Matriz::maiorColuna() const {
    int maior = matriz_[0].size();
    for (std::vector<float> vetor_linha : matriz_) {
        if (vetor_linha.size() > maior) {
            maior = vetor_linha.size();
        }
    }
    return maior;
}

bool Matriz::matrizQuadrada() const {
    return (matriz_[0].size() == matriz_.size());
}

void Matriz::retangularizarMatriz() {
    int tamanhoDaColuna = maiorColuna();
    for (std::vector<float> &vetor_linha : matriz_) {
        vetor_linha.resize(tamanhoDaColuna);
    }
}

float Matriz::det() {
    if(matrizQuadrada()) {
        if (matriz_.size() > 1) {
                float determinante = 0;
                for (int i = 0; i < matriz_.size(); i++) {
                    determinante += matriz_[0][i] * Matriz(matriz_, 0, i).det() * pow(-1, i);
                }
                return determinante;
        } else {
                return matriz_[0][0];
        }
    } else {
        int ERRO_DETERMINANTE = -99999;
        return ERRO_DETERMINANTE;
    }
}