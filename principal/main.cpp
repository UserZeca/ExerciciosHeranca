#include <iostream>
#include <vector>
#include <map>
#include "../graph/graph.hpp"
#include "../funcionario/funcionario.hpp"
#include "../veiculo/Veiculo.hpp"
#include "../veiculo/Caminhao.hpp"
#include "../veiculo/Van.hpp"

void desafio(){
    
    std::cout << "Desafio de Grafo" << std::endl;

    Graph graph;

    // Adiciona alguns vertices e arestas
    graph.addVertex("Sao Paulo");
    graph.addVertex("Rio de Janeiro");
    graph.addVertex("Belo Horizonte");
    graph.addEdge("Sao Paulo", "Rio de Janeiro");
    graph.addEdge("Sao Paulo", "Belo Horizonte");
    graph.addEdge("Rio de Janeiro", "Belo Horizonte");

    // Mostra a matriz de adjac�ncia
    graph.display();

    // Testa as funcoes isAdjacent e getNeighbors
    std::cout << "Sao Paulo e Rio de Janeiro sao vizinhos? " << (graph.isAdjacent("Sao Paulo", "Rio de Janeiro") ? "Sim" : "Nao") << std::endl;
    std::cout << "Vizinhos de Sao Paulo: ";
    std::vector<std::string> neighbors = graph.getNeighbors("Sao Paulo");
    for (const std::string& neighbor : neighbors) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

}

void testeProblemaFuncionario(){

    std::cout << "Problema Funcionarios" << std::endl;

    // Criando objetos para diferentes tipos de funcionários
    FuncionarioRegular regular("Julia", 1, 2000.0);
    Gerente gerente("Maria", 2, 3000.0, 1000.0);
    Estagiario estagiario("Pedro", 3, 1500.0);

    // Exibindo o salário total de cada funcionário
    std::cout << "ID:" << regular.getId() << "\t|Nome:" << regular.getNome() << "\t| salario total como Funcionario Regular: " << regular.calcularSalarioTotal() << std::endl;
    std::cout << "ID:" << gerente.getId() << "\t|Nome:" << gerente.getNome() << "\t| salario total como Gerente: " << gerente.calcularSalarioTotal() << std::endl;
    std::cout << "ID:" << estagiario.getId() << "\t|Nome:" << estagiario.getNome() << "\t| salario total como Estagiario: " << estagiario.calcularSalarioTotal() << std::endl;

}

void testandoProblemaVeiculos(){

    std::cout << "Problema Veiculos" << std::endl;
    std::vector<Veiculo*> frota;

    // Adicionando veículos à frota
    frota.push_back(new Caminhao("Scania", "R730", 20, 4));
    frota.push_back(new Van("Mercedes-Benz", "Sprinter", 2, 10));
    frota.push_back(new Caminhao("MAN", "TGX", 18, 3));
    frota.push_back(new Van("Renault", "Master", 1, 6));
    frota.push_back(new Caminhao("Iveco", "Stralis", 22, 4));
    frota.push_back(new Van("Peugeot", "Boxer", 1, 9));
    frota.push_back(new Caminhao("Volvo", "FH16", 25, 5));
    frota.push_back(new Van("Ford", "Transit", 1, 8));

    // Exibindo dados de cada veículo na frota
    std::cout << "Veiculos:\n" << std::endl;
    for (const auto& veiculo : frota) {
        veiculo->exibirDados();
        std::cout << std::endl;
    }

    // Liberando memória alocada dinamicamente
    for (auto& veiculo : frota) {
        delete veiculo;
    }
    frota.clear();

}

int main() {
    
    testeProblemaFuncionario();
    testandoProblemaVeiculos();
    desafio();

    return 0;
}
