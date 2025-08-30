#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 42;
    int y = 17;
    int* ptr = &x;

    std::cout << "Valor de x: " << x << std::endl;
    std::cout << "Dirección de x: " << &x << std::endl;
    std::cout << "Valor del puntero ptr: " << ptr << std::endl;
    std::cout << "Valor al que apunta ptr: " << *ptr << std::endl;

    std::cout << "\nAntes de intercambiar: x = " << x << ", y = " << y << std::endl;
    swap(&x, &y);
    std::cout << "Después de intercambiar: x = " << x << ", y = " << y << std::endl;

    return 0;
}
