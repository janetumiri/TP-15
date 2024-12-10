#include <iostream>
#include <cmath>
#include <string>

class Figura {
public:
  std::string color;
  double posicionX, posicionY;
  Figura(std::string c, double x, double y) : color(c), posicionX(x), posicionY(y) {}
  virtual double calcularArea() = 0; 
  virtual double calcularPerimetro() = 0; 
  virtual ~Figura() = default;
};

class Circulo : public Figura {
private:
  double radio;
public:
  Circulo(std::string c, double x, double y, double r) : Figura(c, x, y), radio(r) {}
  double calcularArea() override { return M_PI * radio * radio; }
  double calcularPerimetro() override { return 2 * M_PI * radio; }
};

class Rectangulo : public Figura {
private:
  double ancho;
  double alto;
public:
  Rectangulo(std::string c, double x, double y, double a, double b) : Figura(c, x, y), ancho(a), alto(b) {}
  double calcularArea() override { return ancho * alto; }
  double calcularPerimetro() override { return 2 * (ancho + alto); }
};

int main() {
  Circulo circulo("Rojo", 1, 2, 5);
  Rectangulo rectangulo("Azul", 3, 4, 4, 6);

  std::cout << "Área del círculo: " << circulo.calcularArea() << std::endl;
  std::cout << "Perímetro del círculo: " << circulo.calcularPerimetro() << std::endl;
  std::cout << "Área del rectángulo: " << rectangulo.calcularArea() << std::endl;
  std::cout << "Perímetro del rectángulo: " << rectangulo.calcularPerimetro() << std::endl;
  return 0;
}
