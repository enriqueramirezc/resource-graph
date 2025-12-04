#include "Pipe.hpp"
#include "raylib.h"

void Pipe::drawPipelines(Graph& graph) {
  for (int m = 0; m < static_cast<int>(machines.size()); m++) {
    std::vector<int> path = machines[m].getPath();
    Color color = machines[m].getPipeColor();

    for (int i = 0; i < static_cast<int>(path.size()) - 1; i++) {
      Node n1 = graph.getNode(path[i]);
      Node n2 = graph.getNode(path[i + 1]);

      float x1 = n1.getX() * scale + offsetX;
      float y1 = n1.getY() * scale + offsetY;
      float x2 = n2.getX() * scale + offsetX;
      float y2 = n2.getY() * scale + offsetY;

      DrawLineEx((Vector2){x1, y1}, (Vector2){x2, y2}, 5.0f, color);
    }
  }
}

void Pipe::buildMachine(int nodeId, MachineType type, Graph& graph, int& playerRes) {
  // Buscar si ya hay máquina en este nodo
  for (int i = 0; i < static_cast<int>(machines.size()); i++) {
    if (machines[i].getResourceNode() == nodeId) {
      int refund = 0;
      if (machines[i].getType() == BFS || machines[i].getType() == DFS) {
        refund = bfsCost / 2;
      } else if (machines[i].getType() == GREEDY) {
        refund = greedyCost / 2;
      } else if (machines[i].getType() == DIJKSTRA) {
        refund = dijkstraCost / 2;
      }
      playerRes += refund;
      machines.erase(machines.begin() + i);
      break;
    }
  }

  // Calcular costo
  int cost = 0;
  if (type == BFS || type == DFS) cost = bfsCost;
  else if (type == GREEDY) cost = greedyCost;
  else if (type == DIJKSTRA) cost = dijkstraCost;

  if (playerRes < cost) return;
  playerRes -= cost;

  // Calcular camino
  std::vector<int> path;
  if (type == BFS) path = graph.bfs(nodeId, graph.getStartNode());
  else if (type == DFS) path = graph.dfs(nodeId, graph.getStartNode());
  else if (type == GREEDY) path = graph.greedy(nodeId, graph.getStartNode());
  else if (type == DIJKSTRA) path = graph.dijkstra(nodeId, graph.getStartNode());

  if (path.size() == 0) return;

  // Crear máquina
  Node resourceNode = graph.getNode(nodeId);
  Machine newMachine(nodeId, type, resourceNode.getValue());
  newMachine.setPath(path);

  int maintenanceCost = graph.calcPathCost(path);
  newMachine.setMaintenanceCost(maintenanceCost);
  newMachine.calcProfit();

  machines.push_back(newMachine);
}

void Pipe::updateResourceGen(int& playerRes) {
  static int frameCount = 0;
  frameCount++;

  if (frameCount >= 60) {
    frameCount = 0;
    for (int i = 0; i < static_cast<int>(machines.size()); i++) {
      playerRes += machines[i].getNetProfit();
      if (playerRes < 0) playerRes = 0;
    }
  }
}

bool Pipe::hasMachineAt(int nodeId) {
  for (int i = 0; i < static_cast<int>(machines.size()); i++) {
    if (machines[i].getResourceNode() == nodeId) {
      return true;
    }
  }
  return false;
}
