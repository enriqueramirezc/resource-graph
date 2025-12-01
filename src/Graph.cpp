// Copyright [2025] Enrique Ramírez
#include "Graph.hpp"

// Agregar nodo al grafo
void Graph::addNode(const Node& node) {
  nodes.push_back(node);
  if (node.type == 1) {
    startNode = node.id;
  }
}

// Agregar arista a la lista de adyacencia
void Graph::addEdge(int origin, int destination, int weight) {
  if (origin >= adjList.size()) {
    adjList.resize(origin + 1);
  }
  adjList[origin].push_back(Edge(destination, weight));
}
