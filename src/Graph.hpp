#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include "Node.hpp"
#include "Edge.hpp"

class Graph {
 private:
  std::vector<Node> nodes;
  std::vector<std::vector<Edge>> adjList;  // Lista de ady. porque es disperso
  int startNode;  // Nodo de inicio

 public:
  Graph() : startNode(-1) {}  // Se inicializa en -1 el punto de inicio

  void addNode(const Node& node);
  void addEdge(int origin, int destination, int weight);

};  // class Graph
#endif  // GRAPH_HPP
