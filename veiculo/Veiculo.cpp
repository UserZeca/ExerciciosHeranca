#include "Veiculo.hpp"

Veiculo::Veiculo(const std::string& marca, const std::string& modelo, int capacidade)
    : marca(marca), modelo(modelo), capacidade(capacidade) {}

void Veiculo::exibirDados() const {
    std::cout << "Marca: " << marca << ", Modelo: " << modelo << ", Capacidade: " << capacidade << " toneladas\n";
}