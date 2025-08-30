#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::string nombre_archivo = "demo_io.txt";
    int num_lineas;
    std::cout << "¿Cuántas líneas quieres escribir en el archivo? ";
    std::cin >> num_lineas;
    std::cin.ignore();

    std::ofstream archivo_salida(nombre_archivo);
    if (!archivo_salida) {
        std::cerr << "No se pudo abrir el archivo para escritura.\n";
        return 1;
    }
    for (int i = 0; i < num_lineas; ++i) {
        std::string linea;
        std::cout << "Introduce la línea " << i+1 << ": ";
        std::getline(std::cin, linea);
        archivo_salida << linea << std::endl;
    }
    archivo_salida.close();
    std::cout << "Texto escrito en " << nombre_archivo << std::endl;

    std::ifstream archivo_entrada(nombre_archivo);
    if (!archivo_entrada) {
        std::cerr << "No se pudo abrir el archivo para lectura.\n";
        return 1;
    }
    std::cout << "Contenido del archivo:\n";
    int contador_lineas = 0;
    int contador_palabras = 0;
    std::string linea;
    while (std::getline(archivo_entrada, linea)) {
        std::cout << linea << std::endl;
        ++contador_lineas;
        std::istringstream iss(linea);
        std::string palabra;
        while (iss >> palabra) {
            ++contador_palabras;
        }
    }
    archivo_entrada.close();

    std::cout << "Número de líneas: " << contador_lineas << std::endl;
    std::cout << "Número de palabras: " << contador_palabras << std::endl;

    return 0;
}
