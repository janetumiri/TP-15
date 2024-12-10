#include <iostream>
#include <vector>

enum class EstadoMesa { Libre, Ocupada };

class Mesa {
public:
  int numeroComensales;
  EstadoMesa estado;
  Mesa(int nc) : numeroComensales(nc), estado(EstadoMesa::Libre) {}
};

class Restaurante {
private:
  std::vector<Mesa> mesas;
public:
  void agregarMesa(const Mesa& mesa) { mesas.push_back(mesa); }
  bool reservarMesa(int comensales) {
    for (auto& mesa : mesas) {
      if (mesa.estado == EstadoMesa::Libre && mesa.numeroComensales >= comensales) {
        mesa.estado = EstadoMesa::Ocupada;
        return true;
      }
    }
    return false;
  }
  void liberarMesa(int indice) {
    if (indice >= 0 && indice < mesas.size()) {
      mesas[indice].estado = EstadoMesa::Libre;
    }
  }
  int obtenerMesasLibres() const {
    int contador = 0;
    for (const auto& mesa : mesas) {
      if (mesa.estado == EstadoMesa::Libre) {
        contador++;
      }
    }
    return contador;
  }
};


int main() {
  Restaurante restaurante;
  restaurante.agregarMesa({4});
  restaurante.agregarMesa({2});

  std::cout << "Mesas libres: " << restaurante.obtenerMesasLibres() << std::endl;
  restaurante.reservarMesa(4);
  std::cout << "Mesas libres después de reservar: " << restaurante.obtenerMesasLibres() << std::endl;
  restaurante.liberarMesa(0);
  std::cout << "Mesas libres después de liberar: " << restaurante.obtenerMesasLibres() << std::endl;
  return 0;
}
