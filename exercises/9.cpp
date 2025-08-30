#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

std::mutex mtx;
int contador_global = 0;

// Función que incrementa un contador global de forma segura
void incrementar(int id, int veces) {
    for (int i = 0; i < veces; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> lock(mtx);
        ++contador_global;
        std::cout << "Thread " << id << " incrementa contador a " << contador_global << std::endl;
    }
}

// Función que imprime un mensaje varias veces
void imprimir_mensaje(const std::string& mensaje, int veces) {
    for (int i = 0; i < veces; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << mensaje << " (" << i+1 << ")" << std::endl;
    }
}

int main() {
    std::cout << "Demostración de threads en C++\n";

    // Crear hilos que incrementan el contador
    std::vector<std::thread> hilos;
    for (int i = 0; i < 3; ++i) {
        hilos.emplace_back(incrementar, i+1, 5);
    }

    // Crear hilo que imprime mensajes
    std::thread hilo_mensaje(imprimir_mensaje, "Hola desde otro hilo", 5);

    // Crear hilo usando lambda
    std::thread hilo_lambda([](){
        for (int i = 0; i < 5; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(12));
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Hilo lambda ejecutando paso " << i+1 << std::endl;
        }
    });

    // Esperar a que todos los hilos terminen
    for (auto& h : hilos) {
        h.join();
    }
    hilo_mensaje.join();
    hilo_lambda.join();

    std::cout << "\nTodos los hilos han terminado.\n";
    std::cout << "Valor final del contador global: " << contador_global << std::endl;

    // Ejemplo de crear muchos hilos y sumar resultados
    int suma = 0;
    std::mutex suma_mtx;
    auto sumar = [&](int inicio, int fin) {
        int parcial = 0;
        for (int i = inicio; i < fin; ++i) {
            parcial += i;
        }
        std::lock_guard<std::mutex> lock(suma_mtx);
        suma += parcial;
    };

    std::vector<std::thread> hilos_suma;
    int rango = 100;
    int partes = 4;
    int paso = rango / partes;
    for (int i = 0; i < partes; ++i) {
        hilos_suma.emplace_back(sumar, i*paso, (i+1)*paso);
    }
    for (auto& h : hilos_suma) {
        h.join();
    }
    std::cout << "Suma de 0 a " << rango-1 << " usando threads: " << suma << std::endl;

    return 0;
}
