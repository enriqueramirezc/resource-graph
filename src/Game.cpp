// Copyright [2025] Enrique Ramírez
/**
 * @note Código de elaboración propia adaptado de mi proyecto del curso CI0119,
 * hecho con los estudiantes Brandon Alfaro, David Orias y Joaquín Rodríguez.
 */
#include "Game.hpp"

void Game::updateElements() {
}

void Game::initializeGame() {
  // Dice que la escena es interactuable
  this->interactable = 0;
}

void Game::drawGameElements() {
  ClearBackground(BLACK);
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
void Game::drawGraph(const Graph& graph) {
  std::vector<Node> nodes = graph.getNodes();

  // Centrar y escalar elementos
  float scale = 1.2f;
  float offsetX = 30.0f;
  float offsetY = 120.0f;

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
