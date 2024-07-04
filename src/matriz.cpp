#include "../include/matriz.hpp"
#include <iostream>
#include <cmath>

std::vector<std::vector<float>> Matriz::submatrizLinhaColuna(
            std::vector<std::vector<float>> matriz_reduzida,
            int linha,
            int coluna
        ) {
         
        matriz_reduzida.erase(matriz_reduzida.begin() + linha);
        for (std::vector<float> &vetor_linha : matriz_reduzida) {
            vetor_linha.erase(vetor_linha.begin() + coluna);
        }
        return matriz_reduzida;
    }

int Matriz::maiorColuna() {
    int maior = matriz_[0].size();
    for (std::vector<float> vetor_linha : matriz_) {
        if (vetor_linha.size() > maior) {
            maior = vetor_linha.size();
        }
    }
    return maior;
}

void Matriz::retangularizarMatriz() {
    int tamanhoDaColuna = maiorColuna();
    for (std::vector<float> &vetor_linha : matriz_) {
        vetor_linha.resize(tamanhoDaColuna);
    }
}

bool Matriz::matrizQuadrada() {
    return (matriz_[0].size() == matriz_.size());
}

float Matriz::det() {
    if(matrizQuadrada()) {
        if (matriz_.size() > 1) {
                float determinante = 0;
                for (int i = 0; i < matriz_.size(); i++) {
                    determinante += matriz_[0][i] * Matriz(submatrizLinhaColuna(matriz_, 0, i)).det() *pow(-1, i);
                }
                return determinante;
        } else {
                return matriz_[0][0];
        }
    } else {
        return -999999;
    }
}

Matriz::Matriz(std::vector<std::vector<float>> nova_matriz) : matriz_(nova_matriz) {
    retangularizarMatriz();
}

void Matriz::imprimir() const {
    for (std::vector<float> vetor_linha : matriz_) {
        for (float coluna : vetor_linha) {
            std::cout << coluna << " ";
        }
        std::cout << std::endl;
    }
}