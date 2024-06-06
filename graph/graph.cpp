#include <iostream>
#include <vector>
#include <map>
#include "graph.hpp"

// Construtor
Graph::Graph() {}

// Adiciona um novo vertice
void Graph::addVertex(const std::string& cityName) {
    // Adiciona uma linha e uma coluna e matriz de adjacencia para o novo vertice
    for (auto& row : adjMatrix)
        row.push_back(0);
    adjMatrix.push_back(std::vector<int>(adjMatrix.size() + 1, 0));
    // Mapeia o nome da cidade para o indice do vertice na matriz de adjacencia
    vertexIndices[cityName] = adjMatrix.size() - 1;
}

// Adiciona aresta entre dois vertices
void Graph::addEdge(const std::string& srcCity, const std::string& destCity) {
    // Obtem os indices dos vertices a partir dos nomes das cidades
    int src = vertexIndices[srcCity];
    int dest = vertexIndices[destCity];
    // Verifica se os vertices estao dentro dos limites
    if (src >= 0 && dest >= 0 && src < adjMatrix.size() && dest < adjMatrix.size()) {
        // Atribui 1 a posicao correspondente na matriz para indicar a aresta
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // Grafo nao direcionado
    }
    else {
        std::cout << "Vertices invalidos!" << std::endl;
    }
}

// Verifica se dois vertices sao vizinhos
bool Graph::isAdjacent(const std::string& srcCity, const std::string& destCity) {
    // Obtendo os indices dos vertices a partir dos nomes das cidades
    int src = vertexIndices[srcCity];
    int dest = vertexIndices[destCity];
    if (src >= 0 && dest >= 0 && src < adjMatrix.size() && dest < adjMatrix.size()) {
        return adjMatrix[src][dest] == 1;
    }
    return false;
}

// Obtem os vertices vizinhos de um determinado vertice
std::vector<std::string> Graph::getNeighbors(const std::string& cityName) {
    std::vector<std::string> neighbors;
    int vertex = vertexIndices[cityName];
    if (vertex >= 0 && vertex < adjMatrix.size()) {
        for (const auto& pair : vertexIndices) {
            int neighborIndex = pair.second;
            if (adjMatrix[vertex][neighborIndex] == 1) {
                neighbors.push_back(pair.first);
            }
        }
    }
    return neighbors;
}

// Mostra a matriz de adjacencia
void Graph::display() {
    std::cout << "Matriz de Adjacencia:" << std::endl;
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}