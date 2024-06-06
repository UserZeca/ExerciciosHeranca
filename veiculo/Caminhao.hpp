#ifndef CAMINHAO_HPP
#define CAMINHAO_HPP

#include "Veiculo.hpp"

class Caminhao : public Veiculo {
private:
    int eixos;
public:
    Caminhao(const std::string& marca, const std::string& modelo, int capacidade, int eixos);
    void exibirDados() const override;
};

#endif /* CAMINHAO_HPP */