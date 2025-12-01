#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.hpp"

// Leer archivo de nodos
int readNodes(Graph& graph) {
  std::ifstream archivoNodos("Nodes.csv");
  if (!archivoNodos.is_open()) {
    std::cerr << "ERROR: No se pudo abrir Nodes.csv" << std::endl;
    return 1;
  }
  
  std::string line;
  while (std::getline(archivoNodos, line)) {
    if (line.empty()) continue;
    
    // Leer cada elemento
    std::stringstream ss(line);
    int id, type, value, x, y;
    char comma;
    ss >> id >> comma >> type >> comma >> value >> comma >> x >> comma >> y;
    
    // Agregar el elemento al grafo
    graph.addNode(Node(id, type, value, x, y));
  }
  archivoNodos.close();
  return 0;
}

// Leer archivo de aristas
int readEdges(Graph& graph) {
  std::ifstream archivoAristas("Edges.csv");
  if (!archivoAristas.is_open()) {
    std::cerr << "ERROR: No se pudo abrir Edges.csv" << std::endl;
    return 1;
  }

  std::string line;
  while (std::getline(archivoAristas, line)) {
    if (line.empty()) continue;
    
    // Leer cada elemento
    std::stringstream ss(line);
    int origin, dest, weight;
    char comma;
    ss >> origin >> comma >> dest >> comma >> weight;
    
    // Agregar la arista a la lista de adyacencia
    graph.addEdge(origin, dest, weight);
  }
  archivoAristas.close();
  return 0;
}

int main() {
  Graph graph;

  readNodes(graph);
  readEdges(graph);

  // Prueba
  std::cout << "cantidad de nodos: " << graph.getNodeCount() << std::endl;
  std::cout << "Nodo de inicio: " << graph.getStartNode() << std::endl;
  return 0;
}
