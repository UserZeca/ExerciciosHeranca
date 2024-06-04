#include <iostream>
#include <vector>
#include <map>

class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;
    std::map<std::string, int> vertexIndices;

public:
    // Construtor
    Graph() {}

    // Adicionar v�rtice
    void addVertex(const std::string& cityName) {
        // Adicionar uma linha e uma coluna � matriz de adjac�ncia para o novo v�rtice
        for (auto& row : adjMatrix)
            row.push_back(0);
        adjMatrix.push_back(std::vector<int>(adjMatrix.size() + 1, 0));
        // Mapear o nome da cidade para o �ndice do v�rtice na matriz de adjac�ncia
        vertexIndices[cityName] = adjMatrix.size() - 1;
    }

    // Adicionar aresta entre dois v�rtices
    void addEdge(const std::string& srcCity, const std::string& destCity) {
        // Obter os �ndices dos v�rtices a partir dos nomes das cidades
        int src = vertexIndices[srcCity];
        int dest = vertexIndices[destCity];
        // Certifique-se de que os v�rtices est�o dentro dos limites
        if (src >= 0 && dest >= 0 && src < adjMatrix.size() && dest < adjMatrix.size()) {
            // Atribua 1 � posi��o correspondente na matriz para indicar a aresta
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1; // Se for um grafo n�o direcionado
        }
        else {
            std::cout << "Vertices invalidos!" << std::endl;
        }
    }

    // Verificar se dois v�rtices s�o vizinhos
    bool isAdjacent(const std::string& srcCity, const std::string& destCity) {
        // Obter os �ndices dos v�rtices a partir dos nomes das cidades
        int src = vertexIndices[srcCity];
        int dest = vertexIndices[destCity];
        if (src >= 0 && dest >= 0 && src < adjMatrix.size() && dest < adjMatrix.size()) {
            return adjMatrix[src][dest] == 1;
        }
        return false;
    }

    // Obter v�rtices vizinhos de um determinado v�rtice
    std::vector<std::string> getNeighbors(const std::string& cityName) {
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

    // Mostrar matriz de adjac�ncia
    void display() {
        std::cout << "Matriz de Adjacencia:" << std::endl;
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph graph;

    // Adicionar alguns v�rtices e arestas
    graph.addVertex("Sao Paulo");
    graph.addVertex("Rio de Janeiro");
    graph.addVertex("Belo Horizonte");
    graph.addEdge("Sao Paulo", "Rio de Janeiro");
    graph.addEdge("Sao Paulo", "Belo Horizonte");
    graph.addEdge("Rio de Janeiro", "Belo Horizonte");

    // Mostrar a matriz de adjac�ncia
    graph.display();

    // Testar os m�todos isAdjacent e getNeighbors
    std::cout << "Sao Paulo e Rio de Janeiro sao vizinhos? " << (graph.isAdjacent("Sao Paulo", "Rio de Janeiro") ? "Sim" : "Nao") << std::endl;
    std::cout << "Vizinhos de Sao Paulo: ";
    std::vector<std::string> neighbors = graph.getNeighbors("Sao Paulo");
    for (const std::string& neighbor : neighbors) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    return 0;
}
