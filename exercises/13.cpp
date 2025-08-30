#include <iostream>
#include <vector>
#include <type_traits>


template<typename T>
T suma(const std::vector<T>& v) {
    T total = 0;
    for (const auto& x : v) total += x;
    return total;
}

template<typename T>
struct EsEntero {
    static constexpr bool valor = std::is_integral<T>::value;
};

template<typename T>
void imprimeTipo(const T& x) {
    if constexpr (EsEntero<T>::valor) std::cout << "entero\n";
    else std::cout << "no entero\n";
}

int main() {
    std::vector<int> vi = {1,2,3};
    std::vector<double> vd = {1.5,2.5,3.5};
    std::cout << suma(vi) << std::endl;
    std::cout << suma(vd) << std::endl;
    imprimeTipo(vi[0]);
    imprimeTipo(vd[0]);
    return 0;
}
