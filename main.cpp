#include <iostream>
#include "include/matriz.hpp"

int main() {
    Matriz m({{1, 2}, {3, 4}});
    std::cout << m.det(); // Teste de determinante
    return 0;
}