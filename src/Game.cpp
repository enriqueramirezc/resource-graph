// Copyright [2025] Enrique Ramírez
#include "Game.hpp"

void Game::updateElements() {
}

void Game::initializeGame(const Graph& graph) {
  player.initializePlayer();
  player.setCurrentNode(graph.getStartNode());

  Node startNode = graph.getNode(graph.getStartNode());
  float x = startNode.getX() * scale + offsetX;
  float y = startNode.getY() * scale + offsetY;
  player.setPlayerPosition(x, y);
  // Dice que la escena es interactuable
  this->interactable = 0;
}

void Game::drawGameElements(const Graph& graph) {
  ClearBackground(BLACK);
  drawEdges(graph);
  drawNodes(graph);
  player.drawPlayer();
  // Mostrar batería
  DrawText(TextFormat("Bateria: %d%%", player.getBattery()), 
    10, 10, 25, WHITE);

  if (interactable) updateElements();
}

// Pausar juego
void Game::isGamePaused(byte& paused) {
  // Si tocamos espacio, pausamos
  if (IsKeyDown(KEY_SPACE)) paused = 1;
}

void Game::resetMatch() {
}

// Poner nodos en el área de juego
void Game::drawNodes(const Graph& graph) {
  std::vector<Node> nodes = graph.getNodes();

  for (int i = 0; i < nodes.size(); i++) {
    Node node = nodes[i];
    Color color;
    float radius;

    if (node.getType() == 1) {  // Base
      color = BLUE;
      radius = 15.0f;
    } else if (node.getType() == 2) {  // Recurso
      color = GREEN;
      radius = 15.0f;
    } else {  // Vacío
      color = GRAY;
      radius = 15.0f;
    }

    // Aplicar escala y offset
    float x = node.getX() * scale + offsetX;
    float y = node.getY() * scale + offsetY;

    DrawCircle(x, y, radius, color);
    DrawText(TextFormat("%d", node.getId()), x - 9, y - 9, 18, BLACK);
  }
}

// Dibujar aristas y sus pesos
void Game::drawEdges(const Graph& graph) {
  std::vector<Node> nodes = graph.getNodes();
  const std::vector<std::vector<Edge>>& adjList = graph.getAdjList();

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
