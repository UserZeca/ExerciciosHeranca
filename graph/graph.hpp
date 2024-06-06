#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <map>

class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;
    std::map<std::string, int> vertexIndices;

public:
    // Construtor
    Graph();

    // Adiciona vertice
    void addVertex(const std::string& cityName);

    // Adiciona aresta entre dois vertices
    void addEdge(const std::string& srcCity, const std::string& destCity);

    // Verifica se dois vertices sao vizinhos
    bool isAdjacent(const std::string& srcCity, const std::string& destCity);

    // Obtem vertices vizinhos de um determinado vertice
    std::vector<std::string> getNeighbors(const std::string& cityName);

    // Mostrar matriz de adjacencia
    void display();
};
#endif // !GRAPH_HPP