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
    std::vector<std::vector<float>> matrizRetangularizada(matriz_.size(), std::vector<float>(maiorColuna()));
    int indiceLinha = 0;
    int indiceColuna = 0;
    for (std::vector<float> vetor_linha : matriz_) {
        for (float elemento_coluna : vetor_linha) {
            matrizRetangularizada[indiceLinha][indiceColuna] = elemento_coluna;
            indiceColuna++;
        }
        indiceColuna = 0;
        indiceLinha++;
    }
    matriz_ = matrizRetangularizada;
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

float Matriz::det() {
    if (matrizQuadrada(matriz_)) {
        return determinanteRecursiva(matriz_);
    } else {
        return -9999;
    }
}