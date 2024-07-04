#include <iostream>
#include "include/matriz.hpp"

int main() {
    Matriz m({{1, 2, 3}, {3, 2}, {1, 1, 1}});
    std::cout << "A matriz M é dada por" << std::endl;
    m.imprimir(); 
    std::cout << "O seu determinante é det M = " << m.det() << std::endl;
    std::cout << "Sua submatriz, após remover a primeira linha e a segunda coluna, é: " << std::endl;
    Matriz(m.matriz_, 0, 1).imprimir();
    return 0;
}