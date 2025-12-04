#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <vector>
#include "raylib.h"

enum MachineType {
  NONE = 0,
  BFS = 1,
  DFS = 2,
  GREEDY = 3,
  DIJKSTRA = 4
};

class Machine {
 private:
  int resourceNodeId;
  MachineType type;
  std::vector<int> path;  // Camino desde recurso hasta base
  int maintenanceCost;  // Costo de mantenimiento (suma de pesos)
  int resourceValue;  // Valor del recurso
  int netProfit;  // Ganancia
  Color pipeColor;  // Color de la tubería

 public:
  Machine(int nodeId, MachineType t, int resValue)
    : resourceNodeId(nodeId), type(t), maintenanceCost(0)
    , resourceValue(resValue), netProfit(0) {
    switch(type) {
      case BFS:
      case DFS:
        pipeColor = PURPLE;
        break;
      case GREEDY:
        pipeColor = YELLOW;
        break;
      case DIJKSTRA:
        pipeColor = GREEN;
        break;
      default:
        pipeColor = WHITE;
    }
  }

  void setPath(const std::vector<int>& p) {
    path = p;
  }

  void setMaintenanceCost(int cost) {
    maintenanceCost = cost;
  }

  void calcProfit() {
    netProfit = resourceValue - maintenanceCost;
  }

  int getResourceNode() const {
    return resourceNodeId;
  }

  MachineType getType() const {
    return type;
  }

  const std::vector<int>& getPath() const {
    return path;
  }

  int getNetProfit() const {
    return netProfit;
  }

  Color getPipeColor() const {
    return pipeColor;
  }
};

#endif  // MACHINE_HPP
