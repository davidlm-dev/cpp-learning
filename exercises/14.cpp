#include <iostream>
#include <stdexcept>
#include <string>


class MiExcepcion : public std::exception {
    std::string msg;
public:
    MiExcepcion(const std::string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

void funcionA() {
    throw MiExcepcion("Error en funcionA");
}

void funcionB() {
    try {
        funcionA();
    } catch (const MiExcepcion& e) {
        throw std::runtime_error(std::string("funcionB atrapó: ") + e.what());
    }
}

int main() {
    try {
        funcionB();
    } catch (const std::exception& e) {
        std::cout << "Excepción final: " << e.what() << std::endl;
    }
    return 0;
}
