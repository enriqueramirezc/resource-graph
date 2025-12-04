// Copyright [2025] Enrique Ramírez
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include "Node.hpp"
#include "Edge.hpp"

/**
 * @brief Clase que representa un grafo dirigido con pesos.
 */
class Graph {
 private:
  std::vector<Node> nodes;  // Nodos del grafo.
  std::vector<std::vector<Edge>> adjList;  // Lista de ady. (porque es disperso)
  int startNode;  // Nodo de inicio

  float scale = 1.2f;
  float offsetX = 30.0f;
  float offsetY = 120.0f;

 public:
  Graph() : startNode(-1) {}  // Se inicializa en -1 el punto de inicio

  /**
   * @brief Método encargado de agregar un nodo al grafo.
   * @param node Nodo que se desea agregar.
   */
  void addNode(const Node& node);

  /**
   * @brief Método encargado de agregar una arista a la lista de adyacencia
   * @param origin Número de nodo origen de la arista.
   * @param destination Número de nodo destino de la arista.
   * @param weight Peso de la arista.
   */
  void addEdge(int origin, int destination, int weight);

  /**
   * @brief Método que retorna la cantidad de nodos que tiene un grafo.
   */
  int getNodeCount() const {
    return nodes.size();
  }

  /**
   * @brief Método que retorna el valor del nodo de inicio del grafo.
   */
  int getStartNode() const {
    return startNode;
  }

  const std::vector<Node>& getNodes() const {
    return nodes;
  }

  const Node& getNode(int id) const {
    return nodes[id];
  }
  
  const std::vector<std::vector<Edge>>& getAdjList() const {
    return adjList;
  }

  void drawEdges();

  void drawNodes();

  bool isAdjacent(int nodeA, int nodeB) const {
    if (nodeA >= adjList.size()) {
      return false;
    }
    for (const Edge& edge : adjList[nodeA]) {
      if (edge.getDestination() == nodeB) return true;
    }
    return false;
  }

  int getEdgeWeight(int origin, int destination) const {
    if (origin >= adjList.size()) return -1;
    for (const Edge& edge : adjList[origin]) {
      if (edge.getDestination() == destination) 
        return edge.getWeight();
    }
    return -1;
  }

  // Algoritmos de búsqueda
  std::vector<int> bfs(int start, int end);
  std::vector<int> dfs(int start, int end);
  std::vector<int> greedy(int start, int end);
  std::vector<int> dijkstra(int start, int end);

  // Calcular costo de un recorrido
  int calcPathCost(const std::vector<int>& path);
};  // class Graph
#endif  // GRAPH_HPP
