#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <iostream>
#include <string>

class Veiculo {
protected:
    std::string marca;
    std::string modelo;
    int capacidade; // Capacidade de carga em toneladas
public:
    Veiculo(const std::string& marca, const std::string& modelo, int capacidade);
    virtual void exibirDados() const;
};

#endif /* VEICULO_HPP */