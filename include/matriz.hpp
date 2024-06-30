#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <vector>

class Matriz {
    private:

    public: 
    std::vector<std::vector<float>> matriz_;

    Matriz(std::vector<std::vector<float>> nova_matriz);

    void imprimir() const;

    float det();

};

#endif