#ifndef NODE_HPP
#define NODE_HPP

class Node {
 private:
  int id;
  int type;  // 0=Vacío, 1=Base, 2=Recurso
  int value;
  int x, y;  // Coordenadas
};  // class Node
#endif  // NODE_HPP
