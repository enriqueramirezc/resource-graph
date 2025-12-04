// Copyright [2025] Enrique Ramírez
#include "Game.hpp"
#include <math.h>

void Game::updateElements(Graph& graph) {
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    int currentNode = player.getCurrentNode();

    if (currentNode < static_cast<int>(exploredNodes.size())) {
      exploredNodes[currentNode] = true;
    }

    // Revisar todos los nodos
    for (int i = 0; i < graph.getNodeCount(); i++) {
      if (i == currentNode) continue;

      Node node = graph.getNode(i);
      float x = node.getX() * scale + offsetX;
      float y = node.getY() * scale + offsetY;
      float radius = 22.0f;

      float dist = sqrt(pow(mousePos.x - x, 2) + pow(mousePos.y - y, 2));

      // Verificar si el jugador puede ir a este nodo
      if (dist <= radius && graph.isAdjacent(currentNode, i)) {
        int edgeWeight = graph.getEdgeWeight(currentNode, i);
        player.updatePlayer(edgeWeight, i, x, y);
        if (player.getBattery() >= edgeWeight) {
          exploredNodes[i] = true;

          // Si hay máquina, recargar
          if (pipe.hasMachineAt(i)) {
            player.rechargeAtMachine();
          }

          // Si es un nodo de recursos, seleccionarlo
          if (node.getType() == 2) {
            selectedResourceNode = i;
          }
        }
        break;
      }
    }
  }
  // detectar teclas
  if (selectedResourceNode != -1 && !pipe.hasMachineAt(selectedResourceNode)) {

    if (IsKeyPressed(KEY_B) && plyResources >= pipe.bfsCost) {
      pipe.buildMachine(selectedResourceNode, BFS, graph, plyResources);
      player.rechargeAtMachine();
      selectedResourceNode = -1;
    }
    else if (IsKeyPressed(KEY_D) && plyResources >= pipe.dfsCost) {
      pipe.buildMachine(selectedResourceNode, DFS, graph, plyResources);
      player.rechargeAtMachine();
      selectedResourceNode = -1;
    }
    else if (IsKeyPressed(KEY_G) && plyResources >= pipe.greedyCost) {
      pipe.buildMachine(selectedResourceNode, GREEDY, graph, plyResources);
      player.rechargeAtMachine();
      selectedResourceNode = -1;
    }
    else if (IsKeyPressed(KEY_J) && plyResources >= pipe.dijkstraCost) {
      pipe.buildMachine(selectedResourceNode, DIJKSTRA, graph, plyResources);
      player.rechargeAtMachine();
      selectedResourceNode = -1;
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

  if (selectedResourceNode != -1 && !pipe.hasMachineAt(selectedResourceNode)) {
    int yPos = 25;
    DrawText("Construir maquina:", 700, yPos, 25, WHITE);
    
    DrawText(TextFormat("[B] BFS/DFS - %d", pipe.bfsCost), 700, yPos + 30, 20
      , plyResources >= pipe.bfsCost ? GREEN : RED);
    DrawText(TextFormat("[D] DFS - %d", pipe.dfsCost), 700, yPos + 55, 20
      , plyResources >= pipe.dfsCost ? GREEN : RED);
    DrawText(TextFormat("[G] Greedy - %d", pipe.greedyCost), 700, yPos + 80, 20
      , plyResources >= pipe.greedyCost ? GREEN : RED);
    DrawText(TextFormat("[J] Dijkstra - %d", pipe.dijkstraCost), 700, yPos + 105, 20
      , plyResources >= pipe.dijkstraCost ? GREEN : RED);
  }

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

  plyResources = 500;

  pipe.resetPipes();

  // Reset a nodos explorados
  for (size_t i = 0; i < exploredNodes.size(); i++) {
    exploredNodes[i] = false;
  }

  player.setPlayerPosition(x, y);
  player.rechargeBattery();
  selectedResourceNode = -1;
}

void Game::checkDefeat(byte& defeated) {
  if (player.getBattery() <= 0 && player.getCurrentNode() != 0) {
    defeated = 1;
  }
}
