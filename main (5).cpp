#include <iostream>
#include <vector>
#include <string>

class Libro {
public:
  std::string titulo;
  int paginas;
  Libro(std::string t, int p) : titulo(t), paginas(p) {}
};

class Biblioteca {
private:
  std::vector<Libro> libros;
public:
  void agregarLibro(const Libro& libro) { libros.push_back(libro); }
  void eliminarLibro(const std::string& titulo) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
      if (it->titulo == titulo) {
        libros.erase(it);
        return;
      }
    }
  }
  Libro* buscarLibro(const std::string& titulo) {
    for (auto& libro : libros) {
      if (libro.titulo == titulo) {
        return &libro;
      }
    }
    return nullptr;
  }
  int calcularTotalPaginas() const {
    int total = 0;
    for (const auto& libro : libros) {
      total += libro.paginas;
    }
    return total;
  }
};

int main() {
  Biblioteca biblioteca;
  biblioteca.agregarLibro({"El Quijote", 900});
  biblioteca.agregarLibro({"1984", 300});

  std::cout << "Total de páginas: " << biblioteca.calcularTotalPaginas() << std::endl;

  Libro* libro = biblioteca.buscarLibro("1984");
  if (libro != nullptr) {
    std::cout << "Libro encontrado: " << libro->titulo << std::endl;
  }

  biblioteca.eliminarLibro("El Quijote");
  std::cout << "Total de páginas después de eliminar un libro: " << biblioteca.calcularTotalPaginas() << std::endl;
  return 0;
}

