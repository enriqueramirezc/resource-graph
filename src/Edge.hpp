#ifndef EDGE_HPP
#define EDGE_HPP

class Edge {
 private:
  int origin;
  int destination;
  int weight;
 public:
  // Constructor
  Edge(int dest, int w) : destination(dest), weight(w) {}
};  // class Edge
#endif  // EDGE_HPP
