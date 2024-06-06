cmake_minimum_required(VERSION 3.10)
project(SeuProjeto)

# Definindo o compilador C++
set(CMAKE_CXX_COMPILER g++)  # Altere para o compilador que você está utilizando, se necessário

# Configuração do CMake para encontrar os arquivos de header
include_directories(funcionario)
include_directories(graph)
include_directories(veiculo)

# Adicionando todos os arquivos de código fonte
set(SOURCES
    funcionario/funcionario.cpp
    funcionario/funcionario.hpp
    graph/graph.cpp
    graph/graph.hpp
    veiculo/Caminhao.cpp
    veiculo/Caminhao.hpp
    veiculo/Van.cpp
    veiculo/Van.hpp
    veiculo/Veiculo.cpp
    veiculo/Veiculo.hpp
    principal/main.cpp
)

# Criando o executável
add_executable(seu_executavel ${SOURCES})