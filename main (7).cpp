#include <iostream>
#include <vector>
#include <string>
class Empleado {
public:
    std::string nombre;
    double salario;
    std::string departamento;

    Empleado(std::string nombre, double salario, std::string departamento) :
        nombre(nombre), salario(salario), departamento(departamento) {}
};
class Empresa {
private:
    std::vector<Empleado> empleados;

public:
    void agregarEmpleado(const Empleado& empleado) {
        empleados.push_back(empleado);
    }
    double calcularNominaTotal() const {
        double nominaTotal = 0;
        for (const auto& empleado : empleados) {
            nominaTotal += empleado.salario;
        }
        return nominaTotal;
    }
    Empleado* encontrarEmpleadoMayorSalario() const {
        if (empleados.empty()) {
            return nullptr; 
        }
        return &(*std::max_element(empleados.begin(), empleados.end(),
            [](const Empleado& a, const Empleado& b) {
                return a.salario < b.salario;
            }));
    }
    void listarEmpleadosDepartamento(const std::string& departamento) const {
        bool encontrado = false; 
        for (const auto& empleado : empleados) {
            if (empleado.departamento == departamento) {
                std::cout << "Nombre: " << empleado.nombre << ", Salario: " << empleado.salario << std::endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            std::cout << "No se encontraron empleados en el departamento: " << departamento << std::endl;
        }
    }
    void listarTodosLosEmpleadosOrdenadosPorSalario() const {
        std::vector<Empleado> empleadosOrdenados = empleados;
        std::sort(empleadosOrdenados.begin(), empleadosOrdenados.end(),
            [](const Empleado& a, const Empleado& b) {
                return a.salario < b.salario;
            });

        for (const auto& empleado : empleadosOrdenados) {
            std::cout << "Nombre: " << empleado.nombre << ", Salario: " << empleado.salario << ", Departamento: " << empleado.departamento << std::endl;
        }
    }
};


int main() {
    Empresa miEmpresa;

    miEmpresa.agregarEmpleado({"Ana Pérez", 55000, "Ventas"});
    miEmpresa.agregarEmpleado({"Juan López", 70000, "Marketing"});
    miEmpresa.agregarEmpleado({"Maria Sánchez", 62000, "Ventas"});
    miEmpresa.agregarEmpleado({"Pedro Martínez", 80000, "Gerencia"});
    miEmpresa.agregarEmpleado({"Laura García", 58000, "Ventas"});


    std::cout << "Nómina total de la empresa: $" << miEmpresa.calcularNominaTotal() << std::endl << std::endl;

    Empleado* empleadoMayorSalario = miEmpresa.encontrarEmpleadoMayorSalario();
    if (empleadoMayorSalario != nullptr) {
        std::cout << "Empleado con mayor salario: " << empleadoMayorSalario->nombre << " ($" << empleadoMayorSalario->salario << ")" << std::endl << std::endl;
    } else {
        std::cout << "No hay empleados en la empresa." << std::endl << std::endl;
    }

    std::cout << "Empleados del departamento de Ventas:" << std::endl;
    miEmpresa.listarEmpleadosDepartamento("Ventas");
    std::cout << std::endl;

    std::cout << "Todos los empleados ordenados por salario:" << std::endl;
    miEmpresa.listarTodosLosEmpleadosOrdenadosPorSalario();

    return 0;
}
