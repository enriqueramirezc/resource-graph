// Copyright [2025] Enrique Ramírez
#ifndef EDGE_HPP
#define EDGE_HPP

/**
 * @brief Clase que representa una arista dentro de un grafo dirigido con pesos.
 */
class Edge {
 private:
  int origin;  // Número asignado al nodo del cual se origina la arista
  int destination;  // Número asignado al nodo hacia el que se dirige la arista
  int weight;  // Peso de la arista.
 public:
  // Constructor
  Edge(int dest, int w) : destination(dest), weight(w) {}
};  // class Edge
#endif  // EDGE_HPP
