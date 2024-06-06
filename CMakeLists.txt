cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Collect all source files from different directories
file(GLOB CORE_SOURCES "main/*.cpp")
file(GLOB GRAPH_SOURCES "graph/*.cpp")
#file(GLOB ACESSORIOS_SOURCES "acessorios-cpp/*.cpp")

# Combine all source files into a single list
set(SOURCES
    ${CORE_SOURCES}
    ${GRAPH_SOURCES}
    #${PERSONAGENS_SOURCES}
    #${ACESSORIOS_SOURCES}
    principal/main.cpp
)

# Include header files
include_directories(graph-hpp)

# Create an executable
add_executable(my_program ${SOURCES})