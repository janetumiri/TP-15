#include <iostream>

class Calculadora {
public:
  int sumar(int a, int b) { return a + b; }
  double sumar(double a, double b) { return a + b; }
};

int main() {
  Calculadora calc;
  std::cout << "Suma de enteros: " << calc.sumar(5, 3) << std::endl;
  std::cout << "Suma de flotantes: " << calc.sumar(5.5, 3.2) << std::endl;
  return 0;
}


