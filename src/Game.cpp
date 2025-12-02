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

  for (int i = 0; i < nodes.size(); i++) {
    Node node = nodes[i];
    Color color;
    float radius;

    // Colores según tipo
    if (node.getType() == 1) {  // Base
      color = BLUE;
      radius = 8.0f;
    } else if (node.getType() == 2) {  // Recurso
      color = GREEN;
      radius = 6.0f;
    } else {  // Vacío
      color = GRAY;
      radius = 4.0f;
    }

    // Dibujar nodo
    DrawCircle(node.getX()*1.3, node.getY()*1.3, radius, color);

    // ID del nodo
    DrawText(TextFormat("%d", node.getId())
      , (node.getX() - 5)*1.3, (node.getY() - 15)*1.3, 10, WHITE);
  }
}
