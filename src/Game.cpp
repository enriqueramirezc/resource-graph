// Copyright [2025] Enrique Ramírez
#include "Game.hpp"
#include <math.h>
void Game::updateElements(Graph& graph) {
  if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return;
  
  Vector2 mousePos = GetMousePosition();
  int currentNode = player.getCurrentNode();
  
  if (currentNode < exploredNodes.size()) {
    exploredNodes[currentNode] = true;
  }

  for (int i = 0; i < graph.getNodeCount(); i++) {
    if (i == currentNode) continue;
    
    Node node = graph.getNode(i);
    float x = node.getX() * scale + offsetX;
    float y = node.getY() * scale + offsetY;
    float radius = 22.0f;
    
    float dist = sqrt(pow(mousePos.x - x, 2) + pow(mousePos.y - y, 2));
    if (dist <= radius && graph.isAdjacent(currentNode, i)) {
      int edgeWeight = graph.getEdgeWeight(currentNode, i);
      
      if (player.getBattery() >= edgeWeight) {
        player.updatePlayer(edgeWeight, i, x, y);
        exploredNodes[i] = true;

        if (node.getType() == 2 && !pipe.hasMachineAt(i)) {
          if (plyResources >= pipe.bfsCost) {
            pipe.buildMachine(i, BFS, graph, plyResources);
          }
        }
      }
      break;
    }
  }
}

void Game::initializeGame(Graph& graph) {
  player.initializePlayer();
  plyResources = 500;
  exploredNodes.resize(graph.getNodeCount(), false);
  resetMatch(graph);
  // Dice que la escena es interactuable
  this->interactable = 0;
}

void Game::drawGameElements(Graph& graph) {
  ClearBackground(BLACK);
  graph.drawEdges();
  pipe.drawPipelines(graph);
  graph.drawNodes();
  player.drawPlayer();

  DrawText(TextFormat("Bateria: %d%%", player.getBattery()), 10, 10, 25, GREEN);
  DrawText(TextFormat("Recursos: %d", plyResources), 10, 40, 25, YELLOW);
  DrawText(TextFormat("Motor: %d", engineCost), 10, 70, 25, BLUE);
  DrawText(TextFormat("Maquinas: %d", pipe.getMachineCount()), 10, 100, 25
  , WHITE);
  
  if (interactable) {
    updateElements(graph);
    pipe.updateResourceGen(plyResources);
  }
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