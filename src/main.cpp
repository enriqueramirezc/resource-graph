// Copyright [2025] Enrique Ramírez
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Window.hpp"
#include "Home.hpp"
#include "Graph.hpp"
#include "Game.hpp"
#include "Pause.hpp"
#include "SoundManager.hpp"

/**
 * @brief Método encargado de leer los nodos del grafo desde un archivo `.csv`.
 * @param graph Grafo al que se van a agregar nos nodos leídos.
 */
int readNodes(Graph& graph) {
  std::ifstream archivoNodos("Nodes.csv");
  if (!archivoNodos.is_open()) {
    std::cerr << "ERROR: No se pudo abrir Nodes.csv" << std::endl;
    return 1;
  }

  std::string line;
  while (std::getline(archivoNodos, line)) {
    if (line.empty()) continue;

    // Leer cada elemento
    std::stringstream ss(line);
    int id, type, value, x, y;
    char comma;
    ss >> id >> comma >> type >> comma >> value >> comma >> x >> comma >> y;

    // Agregar el elemento al grafo
    graph.addNode(Node(id, type, value, x, y));
  }
  archivoNodos.close();
  return 0;
}

/**
 * @brief Método encargado de leer las aristas de un grafo desde un archivo
 * `.csv`.
 * @param graph Grafo al cual pertenecen las aristas.
 */
int readEdges(Graph& graph) {
  std::ifstream archivoAristas("Edges.csv");
  if (!archivoAristas.is_open()) {
    std::cerr << "ERROR: No se pudo abrir Edges.csv" << std::endl;
    return 1;
  }

  std::string line;
  while (std::getline(archivoAristas, line)) {
    if (line.empty()) continue;

    // Leer cada elemento
    std::stringstream ss(line);
    int origin, dest, weight;
    char comma;
    ss >> origin >> comma >> dest >> comma >> weight;

    // Agregar la arista a la lista de adyacencia
    graph.addEdge(origin, dest, weight);
  }
  archivoAristas.close();
  return 0;
}

int main() {
  // Componentes de juego
  Window window;
  Home homeScreen;
  Game game;
  SoundManager soundManager;
  Pause pause;

  // Grafo que representa el planeta
  Graph graph;

  // Agregar elementos al grafo
  readNodes(graph);
  readEdges(graph);

  // Ciclo del juego
  std::uint8_t paused = 0;
  std::uint8_t inHome = 1;
  std::uint8_t playing = 0;

  // Inicializar ventana de juego
  window.initializeWindow();

  // Inicializar pantalla de ajustes
  homeScreen.initializeHomeScreen();

  // Inicializar partida
  game.initializeGame(graph);

  pause.initializePauseMenu();

  // Inicializar sonidos
  soundManager.initializeSounds();

  // Ciclo de juego
  while (!WindowShouldClose()) {
  window.beginWindowDraw();
  if (inHome) {
    homeScreen.drawHomeScreen();
    homeScreen.hasGameStarted(playing, &soundManager);
    inHome = !(playing);
  } else if (playing) {  // partida
    game.setInteractable();
    game.drawGameElements(graph);
    game.isGamePaused(paused);
    playing = !(paused);
    if (!playing) game.setNotInteractable();
  } else if (paused) {
    pause.drawPauseMenu();
    pause.gameResumed(playing, &soundManager);
    pause.goHome(inHome, &soundManager);
    paused = !(playing);
    if (paused) paused = !(inHome);
  }
  window.endWindowDraw();
}
  soundManager.unloadSounds();
  window.killWindow();  // Cierra la ventana

  // Prueba
  std::cout << "cantidad de nodos: " << graph.getNodeCount() << std::endl;
  std::cout << "Nodo de inicio: " << graph.getStartNode() << std::endl;
  return 0;
}
