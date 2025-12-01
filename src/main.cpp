// Copyright [2025] Enrique Ramírez
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Window.hpp"
#include "Home.hpp"
#include "Graph.hpp"
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
  SoundManager soundManager;

  // Grafo que representa el planeta
  Graph graph;

  // Agregar elementos al grafo
  readNodes(graph);
  readEdges(graph);

  // Ciclo del juego
  std::uint8_t paused = 0;
  std::uint8_t inHome = 1;
  std::uint8_t inGame = 0;
  std::uint8_t inSettings = 0;

  // Inicializar ventana de juego
  window.initializeWindow();
  // Inicializar pantalla de ajustes
  homeScreen.initializeHomeScreen();

  // Inicializar sonidos
  soundManager.initializeSounds();

  // Ciclo de juego
  while (!WindowShouldClose()) {
    window.beginWindowDraw();
    if (inHome) {
      homeScreen.drawHomeScreen();
      homeScreen.hasGameStarted(inGame, &soundManager);
      inHome = !(inGame || inSettings);
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
