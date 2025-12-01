#ifndef NODE_HPP
#define NODE_HPP

class Node {
  friend class Graph;
 private:
  int id;
  int type;  // 0=Vacío, 1=Base, 2=Recurso
  int value;
  int x, y;  // Coordenadas
 public:
  // Constructor
  Node(int id, int type, int value, int x, int y) 
  : id(id), type(type), value(value), x(x), y(y) {}
};  // class Node
#endif  // NODE_HPP
