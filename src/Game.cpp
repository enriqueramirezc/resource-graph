// Copyright [2025] Enrique Ramírez
#include "Game.hpp"
#include <math.h>
void Game::updateElements(Graph& graph) {
  if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return;
  
  Vector2 mousePos = GetMousePosition();
  int currentNode = player.getCurrentNode();
  
  // Revisar cada nodo del grafo
  for (int i = 0; i < graph.getNodeCount(); i++) {
    if (i == currentNode) continue;
    
    Node node = graph.getNode(i);
    float x = node.getX() * scale + offsetX;
    float y = node.getY() * scale + offsetY;
    float radius = 22.0f;
    
    // Verificar click en el nodo
    float dist = sqrt(pow(mousePos.x - x, 2) + pow(mousePos.y - y, 2));
    if (dist <= radius && graph.isAdjacent(currentNode, i)) {
      // Obtener peso de la arista
      int edgeWeight = graph.getEdgeWeight(currentNode, i);
      
      if (player.getBattery() >= edgeWeight) {
        player.updatePlayer(edgeWeight, i, x, y);
      }
      break;
    }
  }
}

void Game::initializeGame(Graph& graph) {
  player.initializePlayer();
  resetMatch(graph);
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
    10, 10, 25, GREEN);

  
  if (interactable) 
  updateElements(graph);
}

// Pausar juego
void Game::isGamePaused(byte& paused) {
  // Si tocamos espacio, pausamos
  if (IsKeyDown(KEY_SPACE)) paused = 1;
}

void Game::resetMatch(Graph& graph) {
  player.setCurrentNode(graph.getStartNode());

  Node startNode = graph.getNode(graph.getStartNode());
  float x = startNode.getX() * scale + offsetX;
  float y = startNode.getY() * scale + offsetY;
  player.setPlayerPosition(x, y);
  player.rechargeBattery();
}

void Game::checkDefeat(byte& defeated) {
  if (player.getBattery() <= 0 && player.getCurrentNode() != 0) {
    defeated = 1;
  }
}