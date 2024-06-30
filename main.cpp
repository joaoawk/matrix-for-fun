#include <iostream>
#include "include/matriz.hpp"

int main() {
    Matriz m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    std::cout << m.det();
    return 0;
}