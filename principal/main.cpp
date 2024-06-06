#include <iostream>
#include <vector>
#include <map>
#include "../graph/graph.hpp"


void desafio(){
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

int main() {
   

    return 0;
}
