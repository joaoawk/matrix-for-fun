#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <vector>

class Matriz {
    private:
    std::vector<std::vector<float>> submatrizLinhaColuna(
        std::vector<std::vector<float>> nova_matriz,
        int linha,
        int coluna
    );

    int maiorColuna();

    void retangularizarMatriz();

    bool matrizQuadrada();

    float determinanteRecursiva(std::vector<std::vector<float>> nova_matriz);

    public:

    std::vector<std::vector<float>> matriz_;

    Matriz(std::vector<std::vector<float>> nova_matriz);

    void imprimir() const;

    float det();

};

#endif