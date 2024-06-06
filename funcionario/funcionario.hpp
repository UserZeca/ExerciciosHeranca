#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

//Classe base que representa um funcionario
class Funcionario {
protected:
    std::string nome; 
    int id; 
    double salarioBase; 
public:
    // Construtor de funcionário com nome, ID e salario base
    Funcionario(std::string _nome, int _id, double _salarioBase);

    // Obtem Nome
    std::string getNome() const;
    // Seta Nome
    void setNome(const std::string& _nome);
    // Obtem id
    int getId() const;
    // seta id
    void setId(int _id);

    // Calcula o salário total do funcionario (metodo virtual)
    virtual double calcularSalarioTotal();
};

// Classe derivada representando um funcionário regular
class FuncionarioRegular : public Funcionario {
public:
    // Construtor de funcionario regular
    FuncionarioRegular(std::string _nome, int _id, double _salarioBase);
};

// Classe derivada representando um gerente
class Gerente : public Funcionario {
private:
    double bonusAnual; // Armazenando o bonus anual do gerente
public:
    // Construtor de gerente com nome, ID, salário base e bônus anual
    Gerente(std::string _nome, int _id, double _salarioBase, double _bonusAnual);

    // Calculando o salário total do gerente
    double calcularSalarioTotal() override;
};

// Classe derivada representando um estagiário
class Estagiario : public Funcionario {
public:
    // Construtor de estagiário com nome, ID e salário base
    Estagiario(std::string _nome, int _id, double _salarioBase);

    // Calculando o salário total do estagiário
    double calcularSalarioTotal() override;
};

#endif // FUNCIONARIO_H