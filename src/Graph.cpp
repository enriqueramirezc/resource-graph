// Copyright [2025] Enrique Ramírez
#include "Graph.hpp"
#include "raylib.h"
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>

// Agregar nodo al grafo
void Graph::addNode(const Node& node) {
  nodes.push_back(node);
  if (node.type == 1) {
    startNode = node.id;
  }
}

// Agregar arista a la lista de adyacencia
void Graph::addEdge(int origin, int destination, int weight) {
  if (origin >= adjList.size()) {
    adjList.resize(origin + 1);
  }
  adjList[origin].push_back(Edge(destination, weight));

  if (destination >= adjList.size()) {
    adjList.resize(destination + 1);
  }
  adjList[destination].push_back(Edge(origin, weight));
}

// Poner nodos en el área de juego
void Graph::drawNodes() {
  for (int i = 0; i < nodes.size(); i++) {
    Node node = nodes[i];
    Color color;
    float radius;

    // Aplicar escala y offset
    float x = node.getX() * scale + offsetX;
    float y = node.getY() * scale + offsetY;

    if (node.getType() == 1) {  // Base
      color = BLUE;
      radius = 22.0f;
      DrawCircle(x, y, radius, color);
      DrawText(TextFormat("%d", node.getId()), x - 9, y - 9, 18, BLACK);
    } else if (node.getType() == 2) {  // Recurso
      color = ORANGE;
      radius = 35.0f;
      DrawCircle(x, y, radius, color);
      // Número de nodo
      DrawText(TextFormat("N: %d", node.getId()), x - 25, y - 15, 18, BLACK);
      // Valor del recurso del nodo
      DrawText(TextFormat("R: %d", node.getValue()), x - 25, y + 1, 18, BLACK);
    } else {  // Vacío
      color = GRAY;
      radius = 22.0f;
      DrawCircle(x, y, radius, color);
      DrawText(TextFormat("%d", node.getId()), x - 9, y - 9, 18, BLACK);
    }
  }
}

// Dibujar aristas y sus pesos
void Graph::drawEdges() {
  // Dibujar las aristas
  for (int i = 0; i < adjList.size(); i++) {
    Node origin = nodes[i];
    float x1 = origin.getX() * scale + offsetX;
    float y1 = origin.getY() * scale + offsetY;

    for (int j = 0; j < adjList[i].size(); j++) {
      Edge edge = adjList[i][j];
      Node dest = nodes[edge.getDestination()];
      float x2 = dest.getX() * scale + offsetX;
      float y2 = dest.getY() * scale + offsetY;

      // Dibujar línea
      DrawLineEx((Vector2){x1, y1}, (Vector2){x2, y2}, 2.0f, RED);

      // Dibujar el peso en el centro de la arista
      float midX = (x1 + x2) / 2.0f;
      float midY = (y1 + y2) / 2.0f;
      DrawRectangle(midX - 10, midY - 10, 20, 12, BLACK);
      DrawText(TextFormat("%d", edge.getWeight()), midX - 8, midY - 8, 15
      , YELLOW);
    }
  }
}

// BFS (ignora pesos)
std::vector<int> Graph::bfs(int start, int end) {
  std::vector<int> parent(nodes.size(), -1);
  std::vector<bool> visited(nodes.size(), false);
  std::queue<int> q;

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    if (current == end) break;

    for (const Edge& edge : adjList[current]) {
      int neighbor = edge.getDestination();
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        parent[neighbor] = current;
        q.push(neighbor);
      }
    }
  }

  // Reconstruir camino
  std::vector<int> path;
  if (parent[end] != -1 || start == end) {
    for (int v = end; v != -1; v = parent[v]) {
      path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
  }
  return path;
}

// DFS (ignora pesos)
std::vector<int> Graph::dfs(int start, int end) {
  std::vector<int> parent(nodes.size(), -1);
  std::vector<bool> visited(nodes.size(), false);
  std::stack<int> s;

  s.push(start);

  while (!s.empty()) {
    int current = s.top();
    s.pop();

    if (current == end) break;

    if (!visited[current]) {
      visited[current] = true;

      for (const Edge& edge : adjList[current]) {
        int neighbor = edge.getDestination();
        if (!visited[neighbor] && parent[neighbor] == -1) {
          parent[neighbor] = current;
          s.push(neighbor);
        }
      }
    }
  }
  
  // Reconstruir camino
  std::vector<int> path;
  if (parent[end] != -1 || start == end) {
    for (int v = end; v != -1; v = parent[v]) {
      path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
  }
  return path;
}

// Elegir vecino con menor peso inmediato
std::vector<int> Graph::greedy(int start, int end) {
  std::vector<bool> visited(nodes.size(), false);
  std::vector<int> path;

  int current = start;
  path.push_back(current);
  visited[current] = true;

  while (current != end) {
    int bestNeighbor = -1;
    int minWeight = std::numeric_limits<int>::max();
    
    for (const Edge& edge : adjList[current]) {
      int neighbor = edge.getDestination();
      if (!visited[neighbor] && edge.getWeight() < minWeight) {
        minWeight = edge.getWeight();
        bestNeighbor = neighbor;
      }
    }

    if (bestNeighbor == -1) {
      // No hay camino, retornar camino vacío
      return std::vector<int>();
    }

    current = bestNeighbor;
    visited[current] = true;
    path.push_back(current);
  }
  
  return path;
}

// Camino de costo mínimo
std::vector<int> Graph::dijkstra(int start, int end) {
  std::vector<int> dist(nodes.size(), std::numeric_limits<int>::max());
  std::vector<int> parent(nodes.size(), -1);
  std::vector<bool> visited(nodes.size(), false);

  dist[start] = 0;

  for (int i = 0; i < nodes.size(); i++) {
    // Encontrar nodo no visitado con menor distancia
    int minDist = std::numeric_limits<int>::max();
    int u = -1;

    for (int j = 0; j < nodes.size(); j++) {
      if (!visited[j] && dist[j] < minDist) {
        minDist = dist[j];
        u = j;
      }
    }

    if (u == -1) break;
    visited[u] = true;

    // Actualizar distancias de vecinos
    for (const Edge& edge : adjList[u]) {
      int v = edge.getDestination();
      int weight = edge.getWeight();

      if (!visited[v] && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        parent[v] = u;
      }
    }
  }
  
  // Reconstruir camino
  std::vector<int> path;
  if (dist[end] != std::numeric_limits<int>::max()) {
    for (int v = end; v != -1; v = parent[v]) {
      path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
  }
  return path;
}

// Calcular costo total de un camino
int Graph::calcPathCost(const std::vector<int>& path) {
  int totalCost = 0;
  for (size_t i = 0; i < path.size() - 1; i++) {
    int weight = getEdgeWeight(path[i], path[i + 1]);
    if (weight != -1) {
      totalCost += weight;
    }
  }
  return totalCost;
}
