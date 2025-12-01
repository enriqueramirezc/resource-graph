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

  void addNode(const Node& node) {
    nodes.push_back(node);
    if (node.type == 1) {
      startNode = node.id;
    }
  }

  void addEdge(int origin, int destination, int weight) {
    if (origin >= adjList.size()) {
      adjList.resize(origin + 1);
    }
    adjList[origin].push_back(Edge(destination, weight));
  }

  int getNodeCount() const {
    return nodes.size();
  }

  int getStartNode() const {
    return startNode;
  }
};  // class Graph
#endif  // GRAPH_HPP
