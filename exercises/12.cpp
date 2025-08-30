
#include <iostream>
#include <vector>
#include <stdexcept>


struct Producto {
    std::string nombre;
    double precio;
};



Producto buscarProducto(const std::vector<Producto>& productos, const std::string& nombre) {
    for (const auto& p : productos) {
        if (p.nombre == nombre) return p;
    }
    throw std::runtime_error("Producto no encontrado: " + nombre);
}



int main() {
    std::vector<Producto> inventario = {
        {"Manzana", 0.5},
        {"Pan", 1.2},
        {"Leche", 0.9}
    };

    std::cout << "Introduce el nombre del producto a buscar: ";
    std::string nombre;
    std::cin >> nombre;

    try {
        Producto p = buscarProducto(inventario, nombre);
        std::cout << "Producto encontrado: " << p.nombre << ", precio: $" << p.precio << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
