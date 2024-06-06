#include "funcionario.hpp"

// Implementações dos construtores e métodos

// Construindo um funcionário com nome, ID e salário base
Funcionario::Funcionario(std::string _nome, int _id, double _salarioBase) : nome(_nome), id(_id), salarioBase(_salarioBase) {}

// Calculando o salário total do funcionário (método virtual)
double Funcionario::calcularSalarioTotal() {
    return salarioBase;
}

 // Obtem Nome
std::string Funcionario::getNome() const {
    return nome;
}

// Seta nome
void Funcionario::setNome(const std::string& _nome) {
    nome = _nome;
}

 // Obtem id
int Funcionario::getId() const {
    return id;
}

// Seta id
void Funcionario::setId(int _id) {
    id = _id;
}

// Construindo um funcionário regular
FuncionarioRegular::FuncionarioRegular(std::string _nome, int _id, double _salarioBase) : Funcionario(_nome, _id, _salarioBase) {}

// Construindo um gerente com nome, ID, salário base e bônus anual
Gerente::Gerente(std::string _nome, int _id, double _salarioBase, double _bonusAnual) : Funcionario(_nome, _id, _salarioBase), bonusAnual(_bonusAnual) {}

// Calculando o salário total do gerente
double Gerente::calcularSalarioTotal() {
    return salarioBase + bonusAnual;
}

// Construindo um estagiário com nome, ID e salário base
Estagiario::Estagiario(std::string _nome, int _id, double _salarioBase) : Funcionario(_nome, _id, _salarioBase * 0.8) {}

// Calculando o salário total do estagiário
double Estagiario::calcularSalarioTotal() {
    return salarioBase;
}