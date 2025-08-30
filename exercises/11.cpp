
#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <fstream>
// Clase abstracta
class Persona {
protected:
	std::string nombre;
	int edad;
public:
	Persona(std::string n, int e) : nombre(n), edad(e) {}
	virtual void saludar() const = 0;
	std::string getNombre() const { return nombre; }
	int getEdad() const { return edad; }
	virtual ~Persona() {}
};

class Empleado : public Persona {
	double salario;
public:
	Empleado(std::string n, int e, double s) : Persona(n, e), salario(s) {}
	void saludar() const override {
		std::cout << "Soy empleado. Mi nombre es " << nombre << ", tengo " << edad << " años y gano $" << salario << std::endl;
	}
	double getSalario() const { return salario; }
};

class Estudiante : public Persona {
	std::string carrera;
public:
	Estudiante(std::string n, int e, std::string c) : Persona(n, e), carrera(c) {}
	void saludar() const override {
		std::cout << "Soy estudiante. Mi nombre es " << nombre << ", tengo " << edad << " años y estudio " << carrera << std::endl;
	}
	std::string getCarrera() const { return carrera; }
};



int main() {
	std::vector<std::unique_ptr<Persona>> grupo;
	grupo.push_back(std::make_unique<Empleado>("Ana", 30, 2500.0));
	grupo.push_back(std::make_unique<Estudiante>("Luis", 22, "Ingeniería"));
	grupo.push_back(std::make_unique<Empleado>("Marta", 40, 3200.0));
	grupo.push_back(std::make_unique<Estudiante>("Carlos", 19, "Matemáticas"));

	// Guardar datos en archivo
	std::ofstream archivo("grupo.txt");
	for (const auto& persona : grupo) {
		if (auto emp = dynamic_cast<Empleado*>(persona.get())) {
			archivo << "Empleado," << emp->getSalario() << "," << emp->getNombre() << "," << emp->getEdad() << "\n";
		} else if (auto est = dynamic_cast<Estudiante*>(persona.get())) {
			archivo << "Estudiante," << est->getCarrera() << "," << est->getNombre() << "," << est->getEdad() << "\n";
		}
	}
	archivo.close();

	std::cout << "--- Grupo saludando en paralelo ---" << std::endl;
	std::vector<std::thread> hilos;
	for (const auto& persona : grupo) {
		hilos.emplace_back([&persona]{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			persona->saludar();
		});
	}
	for (auto& t : hilos) t.join();

	std::cout << "--- Solo empleados (en paralelo) ---" << std::endl;
	std::vector<std::thread> hilosEmp;
	for (const auto& persona : grupo) {
		hilosEmp.emplace_back([&persona]{
			if (auto emp = dynamic_cast<Empleado*>(persona.get())) {
				std::cout << "Salario: " << emp->getSalario() << std::endl;
			}
		});
	}
	for (auto& t : hilosEmp) t.join();

	// Leer datos del archivo y mostrarlos
	std::cout << "--- Datos leídos del archivo ---" << std::endl;
	std::ifstream archivoIn("grupo.txt");
	std::string linea;
	while (std::getline(archivoIn, linea)) {
		std::cout << linea << std::endl;
	}
	archivoIn.close();

	return 0;
}
