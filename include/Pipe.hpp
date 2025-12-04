// Copyright [2025] Enrique Ramírez
#ifndef PIPE_HPP
#define PIPE_HPP

#include "Graph.hpp"
#include "Machine.hpp"
#include <vector>

class Pipe {
 private:
  std::vector<Machine> machines;

  float scale = 1.2f;
  float offsetX = 30.0f;
  float offsetY = 120.0f;

 public:
  // Costos de algoritmos
  int bfsCost = 100;
  int dfsCost = 100;
  int greedyCost = 300;
  int dijkstraCost = 500;

  void drawPipelines(Graph& graph);

  void buildMachine(int nodeId, MachineType type, Graph& graph, int& playerRes);

  void updateResourceGen(int& playerRes);

  bool hasMachineAt(int nodeId);

  int getMachineCount() {
    return machines.size();
  }

  void resetPipes() {
  machines.clear();
  }
};
#endif  // PIPE_HPP
