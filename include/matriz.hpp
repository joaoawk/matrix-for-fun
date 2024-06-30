#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <vector>

class Matriz {
    
    public: 
    std::vector<std::vector<float>> matriz_;

    Matriz(std::vector<std::vector<float>> matriz_saida);

    void imprimir() const;


};

#endif