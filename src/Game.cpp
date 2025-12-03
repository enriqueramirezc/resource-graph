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

void Game::drawGameElements(Graph& graph) {
  ClearBackground(BLACK);
  graph.drawEdges();
  graph.drawNodes();
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
