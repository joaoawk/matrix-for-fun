#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <vector>

class Matriz {
    private:
    int maiorColuna() const;

    void retangularizarMatriz();

    public:

    std::vector<std::vector<float>> matriz_;

    Matriz(std::vector<std::vector<float>> nova_matriz);

    Matriz(std::vector<std::vector<float>> matriz_entrada, int linha, int coluna);

    void imprimir() const;

    bool matrizQuadrada() const;

    float det();

};

#endif