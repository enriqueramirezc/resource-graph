// Copyright [2025] Enrique Ramírez
#ifndef NODE_HPP
#define NODE_HPP

/**
 * @brief Clase que representa un nodo dentro de un grafo
 */
class Node {
  friend class Graph;
 private:
  int id;  // Número de nodo
  int type;  // Tipo de nodo (0=vacío, 1=inicio, 2=recurso)
  int value;  // Valor del nodo
  int x;  // Coordenada del nodo en el eje x
  int y;  // Coordenada del nodo en el eje y
 public:
  // Constructor
  Node(int id, int type, int value, int x, int y) 
  : id(id), type(type), value(value), x(x), y(y) {}

  int getX() const {
    return x;
  }

  int getY() const {
    return y;
  }

  int getType() const {
    return type;
  }

  int getId() const {
    return id;
  }

    int getValue() const {
    return value;
  }
};  // class Node
#endif  // NODE_HPP
